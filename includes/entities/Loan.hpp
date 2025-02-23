#pragma once

#include <chrono>
#include <memory>

#include "Book.hpp"
#include "Entity.hpp"
#include "User.hpp"
namespace AvancedLibrary {
    class Book;
    class User;
    enum LoanStatus { ACTIVED, RETURNED, OVERDUE, EXTENDED };
    struct LoanProps {
        std::chrono::time_point<std::chrono::system_clock> stardDate;
        std::chrono::time_point<std::chrono::system_clock> dueDate;
        std::chrono::time_point<std::chrono::system_clock> returnDate;
        LoanStatus status;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
    };
    class Loan : public Domain::Entity<LoanProps> {
       public:
        Loan(std::shared_ptr<User>& user, std::shared_ptr<Book>& book);
        void validate() const override;
        bool extend();
        void returnBook();
        bool overDue();
        double calculatePenalty();
    };
}  // namespace AvancedLibrary