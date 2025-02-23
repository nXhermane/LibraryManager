#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <variant>
namespace Domain {
    using AggregateID = std::variant<std::string, int>;

    struct BaseEntityProps {
        AggregateID id;
        std::chrono::time_point<std::chrono::system_clock> createdAt;
        std::chrono::time_point<std::chrono::system_clock> updatedAt;
    };

    template <typename T>
    class PropsWrapper {
       private:
        T props;
        std::chrono::time_point<std::chrono::system_clock>& updatedAtRef;

       public:
        explicit PropsWrapper(T initialProps, std::chrono::time_point<std::chrono::system_clock>& updatedAt);
        T& get() const;
        template <typename FieldType>
        void set(FieldType T::*field, const FieldType& newValue);
        const T& read() const;
    };

    template <typename T>
    struct CreateEntityProps {
        std::optional<AggregateID> id;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> createdAt;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> updatedAt;
        T props;
    };

    template <class T>
    class Entity {
       private:
        const AggregateID id;
        const std::chrono::time_point<std::chrono::system_clock> createdAt;
        std::chrono::time_point<std::chrono::system_clock> updatedAt;
        PropsWrapper<T> props;

        void validateProps(const T& newProps);

       protected:
        virtual void validate() const = 0;
        bool _isValid = false;
        bool _isDeleted = false;

       public:
        struct GetPropsResult : BaseEntityProps, T {};

        explicit Entity(CreateEntityProps<T>& entityProps);
        bool equals(const Entity<T>& entity) const;
         std::string getId() const;
        

        GetPropsResult getProps() const;
        bool isValid() const;

        static bool isEntity(const void* obj);
    };

}  // namespace Domain

#include "Entity.tpp"