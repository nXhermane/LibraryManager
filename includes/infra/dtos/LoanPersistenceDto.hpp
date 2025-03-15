#pragma once 
#include <optional>
#include <string>

#include "domain/entities/Loan.hpp"

namespace AvancedLibrary {
    struct LoanPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string startDate;
        std::string dueDate;
        std::optional<std::string> returnDate;
        LoanStatus status;
        std::string bookId;
    };
}  // namespace AvancedLibrary