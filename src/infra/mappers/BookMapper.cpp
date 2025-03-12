#include "infra/mappers/BookMapper.hpp"
#include <algorithm>
#include "domain/entities/Book.hpp"
namespace AvancedLibrary {
    BookMapper::BookMapper() {}
    BookPersisitanceDto BookMapper::toPersistence(const Book& book) const  {
        BookPersisitanceDto bookDto{book.getId(), book.getCreatedAt(), book.getUpdatedAt(), book.getIsbn(), book.getTitle(), book.getAuthor(), book.getYear(), book.getStatus(), book.getCategories()};
        auto reviews {book.getReviews()};
        bookDto.reviewIds.reserve(reviews.size());
        std::transform(reviews.begin(), reviews.end(), bookDto.reviewIds.begin(), [](const Review& review) {
            return review.getId();
        });
        return bookDto;
    };
}