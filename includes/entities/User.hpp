#pragma once
#include <string>

#include "Email.hpp"
#include "Entity.hpp"
#include "Loan.hpp"
namespace AvancedLibrary {
    class Loan;
    struct UserProps {
        std::string name;
        std::string username;
        Email email;
        unsigned int maxLoan;
        std::vector<Loan> activeLoans;
        std::vector<Loan> loanHistory;
        double penalties;
    };

    class User : public Domain::Entity<UserProps> {
       private:
        int MAX_LOAN{5};

       public:
        User(Domain::CreateEntityProps<UserProps> &entityProps);
        void validate() const override;

        bool canBorrow() const;
        const std::vector<Loan> &getActiveLoans() const;
        const std::vector<Loan> &getLoanHistory() const;
        void addLoan(Loan &loan);
        void addPenalty(double amount);
        void payPenalty(double amount);
        double getPenalties() const;
    };
}  // namespace AvancedLibrary
