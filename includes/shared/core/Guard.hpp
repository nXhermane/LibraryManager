#pragma once
#include <optional>
#include <string>
namespace Core {
    struct GuardResponse {
        bool succeeded;
        std::optional<std::string> message;
    };

    class Guard {
       public:
        template <typename T>
        static GuardResponse isEmpty(const T &value);
        static GuardResponse isNegative(const int &value);
        static GuardResponse combine(const GuardResponse *guardResponses, size_t size);
    };
}  // namespace Core
#include "Guard.tpp"