#pragma once
#include <string>
namespace AvancedLibrary {
    struct ReviewPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string comment;
        unsigned rating;
        bool modified;
        std::string date;
        std::string userId;
    };
}  // namespace AvancedLibrary