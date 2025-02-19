#include <stdexcept>
#include "ValueObject.h"

namespace Domain
{
    template <typename T>
    DomainPrimitive<T>::DomainPrimitive(const T &value) : _value(value)
    {
        if (_value == T{})
        {
            throw std::invalid_argument("The value must be empty.");
        }
    };

    template <typename T>
    T DomainPrimitive<T>::getValue() const
    {
        return _value;
    }
    template <typename T>
    ValueObject<T>::ValueObject(const T &props) : props(props)
    {
        if (props == T{})
        {
            throw std::invalid_argument("The ValueObject props must be empty.");
        }
        validate(props);
    }

    template <typename T>
    bool ValueObject<T>::isValid() const
    {
        try
        {
            validate(props);
            return true;
        }
        catch (const std::exception &e)
        {
            return false;
        }
    }
    template <typename T>
    bool ValueObject<T>::equals(const ValueObject<T> &vo) const
    {
        return props == vo.props;
    }

    template <typename T>
    T ValueObject<T>::unpack() const
    {
        return props;
    }
    template <typename T>
    bool ValueObject<T>::isValueObject(const void *obj)
    {
        return dynamic_cast < const ValueObject<T> * (obj) != nullptr;
    }

    template class DomainPrimitive<int>;
    template class DomainPrimitive<double>;
    template class DomainPrimitive<std::string>;

    template class ValueObject<int>;
    template class ValueObject<double>;
    template class ValueObject<std::string>;

}
