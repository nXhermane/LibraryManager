#pragma once
#include <string>
#include <chrono>
#include <vector>
namespace AvancedLibrary
{
    class Book
    {
        struct Review
        {
            std::string reviewer;
            int rating; // 1-5
            std::string comment;
            std::chrono::system_clock::time_point date;
        };

    private:
        std::string title;
        std::string author;
        std::string isbn;
        int publicationYear;
        bool available{true};
        std::vector<Review> reviews;

    public:
        Book(std::string isbn, std::string title, std::string author, int year);

        // Getters
        const std::string &getISBN() const { return isbn; }
        const std::string &getTitle() const { return title; }
        const std::string &getAuthor() const { return author; }
        int getYear() const { return publicationYear; }
        bool isAvailable() const { return available; }
        const std::vector<Review> &getReviews() const { return reviews; }

        // Function
        void borrow();
        void returnBook();
        void addReview(const std::string &reviewer, int rating, const std::string &comment);
        double getAverageRating() const;
    };
}