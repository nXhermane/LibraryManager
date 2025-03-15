#pragma once
#include <string>
#include <vector>
namespace AvancedLibrary {
    struct UserPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string name;
        std::string username;
        std::string email;
        unsigned int maxLoan;
        std::vector<std::string> activeLoans;
        std::vector<std::string> loanHistory;
        double penalties;
    };
}  // namespace AvancedLibrary