#pragma  once 
#include "domain/entities/Loan.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct LoanPersistenceDto {

    };
    class LoanMapper : public Infra::InfraMapper<LoanProps,Loan, LoanPersistenceDto> {
        public: 
        LoanMapper();
        LoanPersistenceDto toPersistence(Loan&) const override;
        Loan toDomain(LoanPersistenceDto &) const override;
    };
}