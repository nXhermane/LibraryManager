#pragma once
#include <set>
#include <vector>

#include "Entity.hpp"
#include "Review.hpp"
namespace AvancedLibrary {
    class Review;
    enum BookStatus { AVAILABLE, RESERVED, BORROWED, MAINTENANCE };
    struct BookProps {
        std::string isbn;
        std::string title;
        std::string author;
        int year;
        BookStatus status;
        std::vector<Review> reviews;
        std::set<std::string> categories;
        int copies;
    };
    class Book : public Domain::Entity<BookProps> {
       public:
        Book(Domain::CreateEntityProps<BookProps>& entityProps);
        void validate() const override;
        void addReview(Review review);
        double getAverageRating() const;
        bool isAvailable() const;
        void addCategory(std::string category);
        void removeCategory(std::string category);
        std::vector<std::string> getCategories() const;
        void updateStatus(BookStatus status);
    };
}  // namespace AvancedLibrary