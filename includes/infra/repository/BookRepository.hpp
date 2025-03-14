#pragma once
#include <string>
#include <vector>

#include "domain/entities/Book.hpp"
#include "infra/dtos/BookPersistenceDto.hpp"
#include "shared/infra/JsonStoreService.hpp"
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
    class JsonBookRepository : public Infra::Repository<BookProps, Book> {
       private:
        std::vector<BookPersistenceDto> store;
        Infra::JsonStoreService jsonStore;
        void loadFromFile();
        void saveToFile();

       public:
        JsonBookRepository(std::string &);

        void save(Book &) override;
        void remove(std::string &id) override;
        Book getById(std::string &id) const override;
        std::vector<Book> getAll() const override;
    };
}  // namespace AvancedLibrary