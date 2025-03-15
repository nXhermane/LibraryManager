#pragma once
#include <string>
#include <vector>

#include "domain/entities/Book.hpp"
#include "shared/infra/Repository.hpp"
#include "infra/dtos/BookPersistenceDto.hpp"
namespace AvancedLibrary {
    class BookRepository : public Infra::Repository<BookProps, Book> {
       public:
        BookRepository();

        void save(Book &) override;
        void remove(std::string &id) override;
        Book getById(std::string &id) const override;
        std::vector<Book> getAll() const override;
    };
    class JsonBookRepository : public Infra::Repository<BookProps, Book> {
        private: 
        std::string filename;
        std::vector<BookPersistenceDto> store;
        
       public:
        JsonBookRepository();

        void save(Book &) override;
        void remove(std::string &id) override;
        Book getById(std::string &id) const override;
        std::vector<Book> getAll() const override;
    };
}  // namespace AvancedLibrary