#pragma once
#include <chrono>
#include <memory>
#include <string>

#include "Entity.hpp"
#include "User.hpp"
namespace AvancedLibrary {
    class Book;
    class User;
    struct ReviewProps {
        int rating;
        std::string comment;
        bool modified;
        std::chrono::time_point<std::chrono::system_clock> date;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
    };

    class Review : public Domain::Entity<ReviewProps> {
       public:
        Review(Domain::CreateEntityProps<ReviewProps>& reviewProps);
        void validate() const override;
        void update(int rating, std::string& comment);
        bool canModify() const;
        
        // Static value
        static const int minRating{1};
        static const int maxRating{5};
    };
}  // namespace AvancedLibrary