#pragma once
#include <boost/json/fwd.hpp>
#include <boost/json/object.hpp>
#include <string>
#include <vector>

#include "domain/entities/Book.hpp"
#include "shared/infra/JsonStoreService.hpp"
namespace AvancedLibrary {
    struct BookPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string isbn;
        std::string title;
        std::string author;
        unsigned int year;
        BookStatus status;
        std::vector<std::string> categories;
        std::vector<std::string> reviewIds;
        Infra::Json::object toJson(const BookPersistenceDto& book) const {
            return {{"id", book.id},
                    {"createdAt", book.createdAt},
                    {"updatedAt", book.updatedAt},
                    {"isbn", book.isbn},
                    {"author", book.author},
                    {"year", book.year},
                    {"staus", static_cast<int>(book.status)},
                    {"cateorires", Infra::Json::value_from(book.categories)},
                    {"reviewIds", Infra::Json::value_from(book.reviewIds)}};
        }
        static BookPersistenceDto formJson(const Infra::Json::object& obj) {
            return {obj.at("id").as_string().c_str(),
                    obj.at("createdAt").as_string().c_str(),
                    obj.at("updatedAt").as_string().c_str(),
                    obj.at("isbn").as_string().c_str(),
                    obj.at("title").as_string().c_str(),
                    obj.at("author").as_string().c_str(),
                    (unsigned)obj.at("year").as_uint64(),
                    (BookStatus)obj.at("status").as_uint64(),
                    Infra::Json::value_to<std::vector<std::string>>(obj.at("categories")),
                    Infra::Json::value_to<std::vector<std::string>>(obj.at("reviewIds"))

            };
        }
    };
}  // namespace AvancedLibrary