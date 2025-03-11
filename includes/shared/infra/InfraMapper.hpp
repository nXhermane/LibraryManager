#pragma once

#include <type_traits>

#include "shared/domain/Entity.hpp"
namespace Infra {

    template <typename T, typename Props>
    concept InfraAllowedClass = std::is_base_of_v<Domain::Entity<Props>, T>;
    template <typename Props, InfraAllowedClass<Props> T, typename PersistenceDto>
    class InfraMapper {
       protected:
        InfraMapper();

       public:
        ~InfraMapper() = default;
        virtual PersistenceDto toPersistence(T &) const = 0;
        virtual T toDomain(PersistenceDto &) const = 0;
    };
}  // namespace Infra