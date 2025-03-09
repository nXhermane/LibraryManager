#pragma once
#include "domain/entities/Book.hpp"
#include "shared/infra/InfraMapper.hpp"

namespace AvancedLibrary {
    struct BookPersisitanceDto {};

    class BookMapper : public Infra::InfraMapper<BookProps, Book, BookPersisitanceDto> {
       public:
        BookMapper();
        BookPersisitanceDto toPersistence(Book &) const override;
        Book toDomain(BookPersisitanceDto &) const override;
    };
}  // namespace AvancedLibrary