#pragma once
#include <string>

#include "domain/entities/Loan.hpp"
#include "domain/value-objects/Email.hpp"
#include "shared/domain/Entity.hpp"
namespace AvancedLibrary {
    class Loan;
    struct UserProps {
        std::string name;
        std::string username;
        Email email;
        unsigned int maxLoan;
        std::vector<std::string> activeLoans;
        std::vector<std::string> loanHistory;
        double penalties;
    };

    class User : public Domain::Entity<UserProps> {
       private:
        int MAX_LOAN{5};

       public:
        User(Domain::CreateEntityProps<UserProps> &entityProps);
        void validate() const override;

        bool canBorrow() const;
        const std::vector<std::string> &getActiveLoans() const;
        const std::vector<std::string> &getLoanHistory() const;
        void addLoan(Loan &loan);
        void addPenalty(double amount);
        void payPenalty(double amount);
        double getPenalties() const;

        static const unsigned DEFAULT_MAX_LOAN;
    };
}  // namespace AvancedLibrary
