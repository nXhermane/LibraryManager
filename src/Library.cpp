#include "Library.h"
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>
namespace AvancedLibrary
{
    Library::Library(std::vector<std::shared_ptr<Book>> initialBooks)
    {
        for (std::shared_ptr<Book> book : initialBooks)
        {
            books[book->getISBN()] = book;
        }
    }

    void Library::addBook(const std::string &isbn, const std::string &title, const std::string &author, int year)
    {
        if (books.contains(isbn))
            throw std::runtime_error("The books with the same isbn already exist on library.");

        books.insert({isbn, std::make_shared<Book>(isbn, title, author, year)});
    }
    void Library::removeBook(const std::string &isbn)
    {
        if (books.contains(isbn))
            books.erase(isbn);
    }
    std::vector<std::shared_ptr<Book>> Library::findBooks(const std::function<bool(const Book &)> &predicate) const
    {
        std::vector<std::shared_ptr<Book>> result;
        for (std::pair<std::string, std::shared_ptr<Book>> book : books)
        {
            if (predicate((*book.second)))
                result.push_back(book.second);
        }
        return result;
    }
    std::vector<std::shared_ptr<Book>> Library::findByTitle(const std::string &title) const
    {
        return findBooks([&title](const Book &book) -> bool
                         { return book.getTitle().find(title) != std::string::npos ? true : false; });
    }
    std::vector<std::shared_ptr<Book>> Library::findByAuthor(const std::string &author) const
    {
        return findBooks([&author](const Book &book) -> bool
                         { return book.getAuthor() == author; });
    }
    std::optional<std::shared_ptr<Book>> Library::findByIsbn(const std::string &isbn) const
    {
        if (auto it = books.find(isbn); it != books.end())
            return it->second;
        return std::nullopt;
    }
    size_t Library::getTotalBooks() const
    {
        return books.size();
    }
    size_t Library::getAvailableBooks() const
    {
        return std::count_if(books.begin(), books.end(), [](const auto &pair) -> bool
                             { return pair.second->isAvailable(); });
    }
}