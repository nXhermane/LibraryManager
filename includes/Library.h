#pragma once
#include <unordered_map>
#include <memory>
#include <functional>
#include <optional>
#include "Book.h"
namespace AvancedLibrary
{
    class Library
    {

    public:
        Library(std::vector<std::shared_ptr<Book>> books);

        void addBook(const std::string &isbn, const std::string &title, const std::string &author, int year);
        void removeBook(const std::string &isbn);

        // Recherche
        std::vector<std::shared_ptr<Book>> findBooks(const std::function<bool(const Book &)> &predicate) const;
        std::vector<std::shared_ptr<Book>> findByTitle(const std::string &title) const;
        std::vector<std::shared_ptr<Book>> findByAuthor(const std::string &author) const;
        std::optional<std::shared_ptr<Book>> findByIsbn(const std::string &isbn) const;
        size_t getTotalBooks() const;
        size_t getAvailableBooks() const;

    private:
        std::unordered_map<std::string , std::shared_ptr<Book>> books;
    };
}