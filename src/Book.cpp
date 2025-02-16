#include "Book.h"
#include <stdexcept>
#include <numeric>
namespace AvancedLibrary
{

    Book::Book(std::string isbn, std::string title, std::string author, int year) : isbn(std::move(isbn)), title(std::move(title)), author(std::move(author)), publicationYear(year) {}

    void Book::borrow()
    {
        if (!available)
            throw std::runtime_error("This books isn't available.");
        available = false;
    }
    void Book::returnBook()
    {
        if (available)
            throw std::runtime_error("This books is already in library.");
        available = true;
    }
    void Book::addReview(const std::string &reviewer, int rating, const std::string &comment)
    {
        if (rating < 1 || rating > 5)
            throw std::invalid_argument("Rating must be between 1 and 5.");
        reviews.push_back({reviewer, rating, comment, std::chrono::system_clock::now()});
    }
    double Book::getAverageRating() const
    {
        double sum = std::accumulate(reviews.begin(), reviews.end(), 0.0, [](double acc, const Review &review) -> double
                                     { return acc + review.rating; });
        return sum / reviews.size();
    }
}