#pragma once
#include <memory>
#include <string>

#include "Factory.hpp"
#include "Result.hpp"
#include "domain/entities/Review.hpp"
#include "domain/entities/User.hpp"
namespace AvancedLibrary {
    struct CreateReviewProps {
        unsigned rating;
        std::string comment;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
    };
    class ReviewFactory : public Core::Factory<ReviewProps, Review, CreateReviewProps> {
       public:
        ReviewFactory();
        Core::Result<Review> create(CreateReviewProps&) override;
    };
}  // namespace AvancedLibrary