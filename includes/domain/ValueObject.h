#pragma once
#include <type_traits>
#include <string>

namespace Domain
{
    // Domain Primitive value  encapsulate the base type of domain such as int , bool, char, double, float, etc.
    template <typename T>
    class DomainPrimitive
    {
    public:
        static_assert(std::is_arithmetic_v<T> || std::is_same_v<T, std::string>, "DomainPrimitive must be a primitive type (int, double, string, char)");
        explicit DomainPrimitive(const T &value);
        T getValue() const;

    private:
        T _value;
    };

    template <typename T>
    class ValueObject
    {
    protected:
        T props;
        virtual void validate(const T &props) const = 0;

    public:
        explicit ValueObject(const T &props);
        bool isValid() const;
        bool equals(const ValueObject<T> &vo) const;
        T unpack() const;
        static bool isValueObject(const void *obj);
    };
} // namespace Core
