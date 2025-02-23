#include <iostream>

#include "Entity.hpp"
#include "User.hpp"

namespace AvancedLibrary {
    User::User(Domain::CreateEntityProps<UserProps>& entityProps) : Domain::Entity<UserProps>(entityProps) {
        validate();
    }
    void User::validate() const { std::cout << "Validate Method Called " << std::endl; }
}  // namespace AvancedLibrary