#pragma once
#include "domain/entities/Reservation.hpp"
#include "shared/infra/InfraMapper.hpp"
namespace AvancedLibrary {
    struct ReservationPersistenceDto {};
    class ReservationMapper : public Infra::InfraMapper<ReservationProps, Reservation, ReservationPersistenceDto> {
       public:
        ReservationMapper();
        ReservationPersistenceDto toPersistence(Reservation &) const override;
        Reservation toDomain(ReservationPersistenceDto &) const override;
    };
}  // namespace AvancedLibrary