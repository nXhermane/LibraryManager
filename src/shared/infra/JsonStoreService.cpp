#include <boost/json/parse.hpp>
#include <boost/json/serialize.hpp>
#include <boost/json/serializer.hpp>
#include <boost/json/system_error.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

#include "shared/infra/JsonStoreService.hpp"
namespace Infra {
    JsonStoreService::JsonStoreService(const std::string& path) : filePath(path) { initAutoSaveThread(); }

    JsonStoreService::~JsonStoreService() {
        stopThread = true;
        saveCondition.notify_one();
        if (saveThread.joinable()) saveThread.join();
    }
    void JsonStoreService::initAutoSaveThread() {
        buffer = load();
        prevBuffer = buffer;
        saveThread = std::thread([this]() {
            std::unique_lock<std::mutex> lock(fileMutex);
            while (!stopThread) {
                saveCondition.wait_for(lock, std::chrono::seconds(saveIntervalInSeconds),
                                       [this] { return dataChanged || stopThread; });
                if (stopThread) break;
                if (dataChanged) {
                    forceSave();
                    dataChanged = false;
                }

                save(buffer.as_array());
            }
        });
    }

    JsonArray JsonStoreService::load() {
        std::lock_guard<std::mutex> lock(fileMutex);
        std::ifstream file(filePath);
        if (!file.is_open()) return JsonArray();  // Retourner un tableau vide si le fichier n'exsite pas
        std::stringstream fileContentBuffer;
        fileContentBuffer << file.rdbuf();
        boost::json::error_code errorCode;
        boost::json::value data = boost::json::parse(fileContentBuffer.str(), errorCode);
        if (errorCode) {
            std::cerr << "Erreur de parsing du JSON" << errorCode.message() << std::endl;
            return JsonArray();
        }
        return data.as_array();
    }

    void JsonStoreService::save(const JsonArray& data) {
        std::lock_guard<std::mutex> lock(fileMutex);
        buffer = data;
        if (buffer != prevBuffer) {
            dataChanged = true;
            saveCondition.notify_one();
        }
    }
    void JsonStoreService::forceSave() {
        std::lock_guard<std::mutex> lock(fileMutex);
        if (buffer == prevBuffer) return;
        std::ofstream file(filePath);

        if (!file.is_open()) {
            std::cerr << "Erreur d'ouverture du fichier JSON" << filePath << std::endl;
            return;
        }
        file << boost::json::serialize(buffer);
        prevBuffer = buffer;
    }
}  // namespace Infra