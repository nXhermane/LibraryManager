#include "domain/entities/Review.hpp"
#include "infra/mappers/ReviewMapper.hpp"

namespace AvancedLibrary {
    ReviewMapper::ReviewMapper() {}

    ReviewPersistenceDto ReviewMapper::toPersistence(const Review& review) const {
        ReviewPersistenceDto reviewDto{review.getId(),
                                       review.getCreatedAt(),
                                       review.getUpdatedAt(),
                                       review.getProps().comment,
                                       review.getProps().rating,
                                       review.getProps().modified,
                                       Utils::timePointToString(review.getProps().date),
                                       review.getProps().userId};
        return reviewDto;
    }
}  // namespace AvancedLibrary