#include <algorithm>
#include <string>

#include "domain/entities/User.hpp"
#include "infra/mappers/UserMapper.hpp"
namespace AvancedLibrary {
    UserMapper::UserMapper() {}
    UserPersistenceDto UserMapper::toPersistence(const User& user) const {
        UserPersistenceDto userDto{
            user.getId(),
            user.getCreatedAt(),
            user.getUpdatedAt(),
            user.getProps().name,
            user.getProps().username,
            user.getProps().email.unpack(),
            user.getProps().maxLoan,
        };
        auto activeLoans = user.getProps().activeLoans;
        userDto.activeLoans.resize(activeLoans.size());
        std::transform(activeLoans.begin(), activeLoans.end(), userDto.activeLoans.begin(),
                       [](const auto& loan) -> std::string { return loan.getId(); });
        auto loanHistory = user.getProps().loanHistory;
        userDto.loanHistory.resize(loanHistory.size());
        std::transform(loanHistory.begin(), loanHistory.end(), userDto.loanHistory.begin(),
                       [](const auto& loan) -> std::string { return loan.getId(); });
        userDto.penalties = user.getProps().penalties;
        return userDto;
    }
}  // namespace AvancedLibrary