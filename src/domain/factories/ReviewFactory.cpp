#include <chrono>

#include "Entity.hpp"
#include "Result.hpp"
#include "domain/entities/Review.hpp"
#include "domain/factories/ReviewFactory.hpp"
namespace AvancedLibrary {
    ReviewFactory::ReviewFactory() {}
    Core::Result<Review> ReviewFactory::create(CreateReviewProps& createProps) {
        return Core::Result<Review>::encapsultate<Review>([&createProps]() -> Review {
            Domain::CreateEntityProps<ReviewProps> entityProps{
                std::nullopt, std::nullopt, std::nullopt,
                ReviewProps{createProps.rating, createProps.comment, false, std::chrono::system_clock::now(),
                            createProps.user, createProps.book}};
            return Review{entityProps};
        });
    }
}  // namespace AvancedLibrary