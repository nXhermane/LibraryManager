#pragma once
#include <vector>

#include "domain/entities/Loan.hpp"
#include "shared/infra/Repository.hpp"
namespace AvancedLibrary {
    class LoanRepository : public Infra::Repository<LoanProps, Loan> {
       public:
        LoanRepository();

        void save(Loan&) override;
        void remove(std::string&) override;
        Loan getById(std::string& id) const override;
        std::vector<Loan> getAll() const override;
    };
    
}  // namespace AvancedLibrary