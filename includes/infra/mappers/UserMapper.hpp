#pragma once
#include <string>
#include <vector>

#include "domain/entities/Loan.hpp"
#include "domain/entities/User.hpp"
#include "shared/infra/InfraMapper.hpp"
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
    struct UserToDomainRecord {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string name;
        std::string username;
        std::string email;
        unsigned maxLoan;
        double penalties;
        std::vector<Loan> activeLoans;
        std::vector<Loan> loanHistory;
    };
    class UserMapper : public Infra::InfraMapper<UserProps, User, UserPersistenceDto> {
       public:
        UserMapper();
        UserPersistenceDto toPersistence(const User &) const override;
        User toDomain(const UserToDomainRecord &) const;
    };
}  // namespace AvancedLibrary