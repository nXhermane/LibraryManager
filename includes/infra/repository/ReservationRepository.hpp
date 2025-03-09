#pragma once
#include <string>
#include <vector>

#include "domain/entities/Reservation.hpp"
#include "shared/infra/Repository.hpp"
namespace AvancedLibrary {

    class ReservationRepository : public Infra::Repository<ReservationProps, Reservation> {
       public:
        ReservationRepository();
        void save(Reservation&) override;
        void remove(std::string&) override;
        Reservation getById(std::string&) const override;
        std::vector<Reservation> getAll() const override;
    };
}  // namespace AvancedLibrary