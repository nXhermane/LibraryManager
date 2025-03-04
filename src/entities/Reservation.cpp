#include <chrono>
#include <optional>
#include <stdexcept>

#include "Entity.hpp"
#include "Reservation.hpp"
namespace AvancedLibrary {
    Reservation::Reservation(Domain::CreateEntityProps<ReservationProps>& entityProps)
        : Domain::Entity<ReservationProps>(entityProps) {
        if (!props.get().reservationDate.has_value()) {
            props.modify(
                &ReservationProps::reservationDate,
                [](std::optional<std::chrono::time_point<std::chrono::system_clock>>& reservationDate) -> void {
                    reservationDate = std::chrono::system_clock::now();
                });
        }
        validate();
    }
    void Reservation::validate() const {
        _isValid = false;
        // Validation code
        _isValid = true;
    }
    void Reservation::notify() {
        if (props.get().status != WAITING)
            throw std::runtime_error("The revervation must be on Waiting State to be able to notify the user.");
        props.set(&ReservationProps::status, ReservationStatus::NOTIFIED);
        props.modify(&ReservationProps::notificationDate, [](std::optional<std::chrono::time_point<std::chrono::system_clock>> & notificationDate) -> void {notificationDate = std::chrono::system_clock::now(); });
    }
}  // namespace AvancedLibrary