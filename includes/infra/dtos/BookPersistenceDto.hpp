#pragma once
#include <string>
#include <vector>

#include "domain/entities/Book.hpp"
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
    };
}  // namespace AvancedLibrary