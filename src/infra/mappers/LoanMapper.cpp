#include "infra/mappers/LoanMapper.hpp"
#include <optional>
#include "domain/entities/Loan.hpp"
#include "shared/utils/time_utils.hpp"

namespace AvancedLibrary {
    LoanMapper::LoanMapper() {};
    LoanPersistenceDto LoanMapper::toPersistence(const Loan& loan) const {
        LoanPersistenceDto loanDto {loan.getId(),loan.getCreatedAt(),loan.getUpdatedAt()};
        loanDto.startDate = Utils::timePointToString(loan.getProps().startDate.value());
        loanDto.dueDate = Utils::timePointToString(loan.getProps().dueDate.value());
        loanDto.returnDate = (loan.getProps().returnDate.has_value()) ? (Utils::timePointToString(loan.getProps().returnDate.value())) : std::nullopt;
        loanDto.status = loan.getProps().status;
        loanDto.userId = loan.getProps().user->getId();
        loanDto.bookId = loan.getProps().book->getId();
        return loanDto;
    }
}