#pragma once
#include <string>

#include "domain/entities/Reservation.hpp"
#include "shared/infra/InfraMapper.hpp"
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
    class ReservationMapper : public Infra::InfraMapper<ReservationProps, Reservation, ReservationPersistenceDto> {
       public:
        ReservationMapper();
        ReservationPersistenceDto toPersistence(const Reservation &) const override;
        Reservation toDomain(const ReservationPersistenceDto &) const ;
    };
}  // namespace AvancedLibrary