#pragma once
#include "domain/entities/Review.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct ReviewPersistenceDto {};
    class ReviewMapper : public Infra::InfraMapper<ReviewProps, Review, ReviewPersistenceDto> {
       public:
        ReviewMapper();
        ReviewPersistenceDto toPersistence(Review &) const override;
        Review toDomain(ReviewPersistenceDto &) const override;
    };
}  // namespace AvancedLibrary