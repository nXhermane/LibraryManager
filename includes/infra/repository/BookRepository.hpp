#pragma once
#include <vector>

#include "domain/entities/Book.hpp"
#include "shared/infra/Repository.hpp"
namespace AvancedLibrary {
    class BookRepository : public Infra::Repository<BookProps, Book> {
       public:
        BookRepository();

        void save(Book &) override;
        void remove(std::string &id) override;
        Book getById(std::string &id) const override;
        std::vector<Book> getAll() const override;
    };
}  // namespace AvancedLibrary