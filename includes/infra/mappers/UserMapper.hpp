#pragma once
#include "domain/entities/User.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct UserPersistenceDto {};
    class UserMapper : public Infra::InfraMapper<UserProps, User, UserPersistenceDto> {
       public:
        UserMapper();
        UserPersistenceDto toPersistence(User &) const override;
        User toDomain(UserPersistenceDto &) const override;
    };
}  // namespace AvancedLibrary