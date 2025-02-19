#pragma once 
#include <string>
#include "ValueObject.h"
namespace AvancedLibrary
{
    class Email: public Domain::ValueObject<std::string>{ 
     public: 
   explicit  Email(std::string& email);
    protected: 
     void  validate(const std::string& email) const  ;
    };
    
} // namespace AvancedLibrary
