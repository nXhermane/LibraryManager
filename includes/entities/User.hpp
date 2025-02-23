#pragma once
#include <string>

#include "Email.hpp"
#include "Entity.hpp"
#include "Loan.hpp"
namespace AvancedLibrary {
    class Loan;
    struct UserProps {
        std::string lastname;
        std::string firstname;
        Email email;
        int maxLoan;
        std::vector<Loan> activeLoans;
        std::vector<Loan> loanHistory;
        int penalties;
    };

    class User : public Domain::Entity<UserProps> {
       public:
        User(Domain::CreateEntityProps<UserProps>& entityProps);
        void validate() const override;

        bool canBorrow();
        std::vector<Loan> getActiveLoans();
        std::vector<Loan> getLoanHistory();
        void addLoan(Loan loan);
        void addPenalty(double amount);
        void payPenalty(double amount);
        double getPenalties() const;
    };
}  // namespace AvancedLibrary
