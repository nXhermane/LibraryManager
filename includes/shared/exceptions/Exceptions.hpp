#pragma once
#include <stdexcept>
#include <string>

class ArgumentNotProvidedException : public std::invalid_argument {
   public:
    explicit ArgumentNotProvidedException(const std::string &message) : std::invalid_argument(message) {}
};
class EmptyStringExcepiton : public std::invalid_argument {
   public:
    explicit EmptyStringExcepiton(const std::string &message) : std::invalid_argument(message) {}
};
class InvalidArgumentFormat : public std::invalid_argument {
   public:
    explicit InvalidArgumentFormat(const std::string &message) : std::invalid_argument(message) {}
};