#include <boost/json/object.hpp>
#include <stdexcept>

#include "domain/entities/Review.hpp"
#include "infra/dtos/BookPersistenceDto.hpp"
#include "infra/repository/BookRepository.hpp"
#include "shared/infra/JsonStoreService.hpp"
#include "shared/infra/Repository.hpp"

namespace AvancedLibrary {
    JsonBookRepository::JsonBookRepository(std::string &path, Infra::Repository<ReviewProps, Review> &repo)
        : jsonStore(path), reviewRepo(repo) {
        loadFromFile();
    }
    void JsonBookRepository::loadFromFile() {
        Infra::JsonArray bookJsonArray{jsonStore.load()};
        for (const auto &jsonBookValue : bookJsonArray) {
            if (!jsonBookValue.is_object()) throw std::runtime_error("[Error] Invalid JSON format: expected an object");
            const Infra::Json::object &jsonBook{jsonBookValue.as_object()};
            BookPersistenceDto book{BookPersistenceDto::formJson(jsonBook)};
            store.push_back(book);
        }
    }
    void JsonBookRepository::saveToFile() {
        Infra::JsonArray bookJsonArray;
        for (auto &book : store) {
            bookJsonArray.push_back(book.toJson());
        };
        jsonStore.save(bookJsonArray);
    }

}  // namespace AvancedLibrary