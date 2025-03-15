#pragma once
#include <string>

#include "domain/entities/Reservation.hpp"
namespace AvancedLibrary {
    struct ReservationPersistenceDto {
        std::string id;
        std::string createdAt;
        std::string updatedAt;
        std::string reservationDate;
        std::string notificationDate;
        std::string userId;
        std::string bookId;
        unsigned queuePosition;
        ReservationStatus status;
    };
}  // namespace AvancedLibrary