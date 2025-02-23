
#include <string>

#include "BookLibrary.h"
#include "Email.hpp"
#include "Entity.hpp"
#include "Exceptions.hpp"
#include "Guard.hpp"
#include "User.hpp"
#include "ValueObject.hpp"

/**
 *  Documentation maked by Mintlify Doc Writer
 * @author Mintlify Doc Writer
 *  */

int main() {
    Domain::DomainPrimitive<std::string> value("Hello");
    std::string emailStr = "email@gmail.com";
    AvancedLibrary::Email email{emailStr};
    auto unpakedValue = email.unpack();
    std::cout << unpakedValue << std::endl;
    Domain::CreateEntityProps<AvancedLibrary::UserProps> userProps{.props = AvancedLibrary::UserProps{"name"}};
    AvancedLibrary::User user = AvancedLibrary::User(userProps);
    auto usrProps = user.getProps();
    std::cout << user.getId() << std::endl;
    // BasicalLibrary::BookLibraryManager bookLibray;
    return 0;
}