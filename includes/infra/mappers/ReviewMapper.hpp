#pragma once
#include <string>

#include "domain/entities/Review.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct ReviewPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string comment;
        unsigned rating;
        bool modified;
        std::string date;
        std::string userId;
        std::string bookId;
    };
    class ReviewMapper : public Infra::InfraMapper<ReviewProps, Review, ReviewPersistenceDto> {
       public:
        ReviewMapper();
        ReviewPersistenceDto toPersistence(Review &) const override;
        Review toDomain(ReviewPersistenceDto &) const override;
    };
}  // namespace AvancedLibrary