#pragma once

#include <atomic>
#include <boost/json.hpp>
#include <boost/json/array.hpp>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>
namespace Infra {
    using JsonArray = boost::json::array;
    namespace Json = boost::json;
    class JsonStoreService {
       private:
        std::string filePath;
        std::mutex fileMutex;
        Json::value buffer;
        Json::value prevBuffer;
        std::condition_variable saveCondition;
        std::atomic<bool> stopThread{false};
        std::thread saveThread;
        bool dataChanged{false};
        unsigned saveIntervalInSeconds{10};
        void initAutoSaveThread();
        void forceSave();

       public:
        explicit JsonStoreService(const std::string &);

        JsonArray load();
        void save(const JsonArray &);

        ~JsonStoreService();
    };
}  // namespace Infra