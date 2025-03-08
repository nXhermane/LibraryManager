#include <optional>

#include "Entity.hpp"
#include "Result.hpp"
#include "domain/entities/Loan.hpp"
#include "domain/factories/LoanFactory.hpp"
namespace AvancedLibrary {
    LoanFactory::LoanFactory() {}
    Core::Result<Loan> LoanFactory::create(CreateLoanProps& createProps) {
        return Core::Result<Loan>::encapsultate<Loan>([&createProps]() -> Loan {
            Domain::CreateEntityProps<LoanProps> entityProps{
                std::nullopt, std::nullopt, std::nullopt,
                LoanProps{std::nullopt, std::nullopt, std::nullopt, LoanStatus::ACTIVED, createProps.user,
                          createProps.book}};
            return Loan{entityProps};
        });
    }
}  // namespace AvancedLibrary