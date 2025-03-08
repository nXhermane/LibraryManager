#pragma once

#include <chrono>
#include <memory>
#include <optional>

#include "domain/entities/Book.hpp"
#include "shared/domain/Entity.hpp"
#include "domain/entities/User.hpp"
namespace AvancedLibrary {
    class Book;
    class User;
    enum LoanStatus { ACTIVED, RETURNED, OVERDUE, EXTENDED };
    struct LoanProps {
        std::optional<std::chrono::time_point<std::chrono::system_clock>> startDate;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> dueDate;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> returnDate;
        LoanStatus status;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
    };
    class Loan : public Domain::Entity<LoanProps> {
       public:
        Loan(Domain::CreateEntityProps<LoanProps>& entityProps);
        void validate() const override;
        bool extend();
        void returnBook();
        bool overDue();
        double calculatePenalty();
    };
}  // namespace AvancedLibrary