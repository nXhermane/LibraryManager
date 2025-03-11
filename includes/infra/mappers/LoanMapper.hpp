#pragma once
#include <optional>
#include <string> 

#include "domain/entities/Loan.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct LoanPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string startDate;
        std::string dueDate;
        std::optional<std::string> returnDate;
        LoanStatus status;
        std::string userId;
        std::string bookId;
    };
    class LoanMapper : public Infra::InfraMapper<LoanProps, Loan, LoanPersistenceDto> {
       public:
        LoanMapper();
        LoanPersistenceDto toPersistence(Loan &) const override;
        Loan toDomain(LoanPersistenceDto &) const override;
    };
}  // namespace AvancedLibrary