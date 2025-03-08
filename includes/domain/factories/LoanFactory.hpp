#pragma once
#include <memory>

#include "Result.hpp"
#include "domain/entities/Book.hpp"
#include "domain/entities/Loan.hpp"
#include "domain/entities/User.hpp"
#include "shared/domain/Factory.hpp"
namespace AvancedLibrary {
    struct CreateLoanProps {
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
    };
    class LoanFactory : public Core::Factory<LoanProps, Loan, CreateLoanProps> {
       public:
        LoanFactory();
        Core::Result<Loan> create(CreateLoanProps&) override;
    };
}  // namespace AvancedLibrary