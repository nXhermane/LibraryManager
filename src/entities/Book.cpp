#include "Book.hpp"
#include "Entity.hpp"
#include "Guard.hpp"
namespace AvancedLibrary {
    // constructor
    Book::Book(Domain::CreateEntityProps<BookProps>& entityProps) : Domain::Entity<BookProps>(entityProps) {}
    
    void Book::validate() const {
    
    }
    
}  // namespace AvancedLibrary