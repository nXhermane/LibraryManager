#pragma once
#include <memory>

#include "Factory.hpp"
#include "Result.hpp"
#include "domain/entities/Reservation.hpp"
#include "domain/entities/User.hpp"
namespace AvancedLibrary {
    struct CreateReservationProps {
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
        unsigned queuePosition;
    };
    class ReservationFactory : public Core::Factory<ReservationProps, Reservation, CreateReservationProps> {
       public:
        ReservationFactory();
        Core::Result<Reservation> create(CreateReservationProps &) override;
    };
}  // namespace AvancedLibrary