#include <optional>

#include "Entity.hpp"
#include "Result.hpp"
#include "domain/entities/User.hpp"
#include "domain/factories/UserFactory.hpp"
#include "domain/value-objects/Email.hpp"

namespace AvancedLibrary {
    UserFactory::UserFactory(){};
    Core::Result<User> UserFactory::create(CreateUserProps& createProps) {
        return Core::Result<User>::encapsultate<User>([&createProps]() -> User {
            Email email{createProps.email};
            Domain::CreateEntityProps<UserProps> entityProps{
                std::nullopt, std::nullopt, std::nullopt,
                UserProps{createProps.name, createProps.username, email, User::DEFAULT_MAX_LOAN, std::vector<Loan>{},
                          std::vector<Loan>{}, 0.}};
            return User{entityProps};
        });
    }
}  // namespace AvancedLibrary