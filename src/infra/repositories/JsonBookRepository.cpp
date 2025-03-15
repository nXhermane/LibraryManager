#include "infra/repository/BookRepository.hpp"
#include "shared/infra/JsonStoreService.hpp"

namespace AvancedLibrary {
    JsonBookRepository::JsonBookRepository(std::string &path) : jsonStore(path) { loadFromFile(); }

}  // namespace AvancedLibrary