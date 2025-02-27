#include <format>
#include <stdexcept>

#include "Entity.hpp"
#include "Exceptions.hpp"
#include "Guard.hpp"
#include "Review.hpp"
namespace AvancedLibrary {

    Review::Review(Domain::CreateEntityProps<ReviewProps>& entityProps) : Domain::Entity<ReviewProps>(entityProps) {
        validate();
    }
    void Review::validate() const {
        this->_isValid = false;
        if (Core::Guard::inRange(getProps().rating, minRating, maxRating).succeeded) {
            throw ArgumentOutOfRangeException(
                std::format("The rating may be in this interval : {} - {}", minRating, maxRating));
        }
        if (Core::Guard::isEmpty(getProps().comment).succeeded) {
            throw EmptyStringExcepiton("The comment cannot be empty.");
        }
        this->_isValid = true;
    }
    void Review::update(int rating, std::string& comment) {
        if (!canModify()) throw std::runtime_error("The Review cannot be modify.");
        props.set(&ReviewProps::rating, rating);
        props.set(&ReviewProps::comment, comment);
        validate();
        props.set(&ReviewProps::modified, true);
    }
    bool Review::canModify() const { return !getProps().modified; }

}  // namespace AvancedLibrary