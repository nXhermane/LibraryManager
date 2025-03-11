#pragma once
#include <string>
#include <vector>

#include "domain/entities/Book.hpp"
#include "shared/infra/InfraMapper.hpp"

namespace AvancedLibrary {
    struct BookPersisitanceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string isbn;
        std::string title;
        std::string author;
        unsigned int year;
        BookStatus status;
        std::vector<std::string> categories;
    };

    class BookMapper : public Infra::InfraMapper<BookProps, Book, BookPersisitanceDto> {
       public:
        BookMapper();
        BookPersisitanceDto toPersistence(Book &) const override;
        Book toDomain(BookPersisitanceDto &) const override;
    };
}  // namespace AvancedLibrary