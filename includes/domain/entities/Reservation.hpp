#pragma once
#include <Entity.hpp>
#include <chrono>
#include <memory>
#include <optional>

#include "domain/entities/Book.hpp"
#include "domain/entities/User.hpp"
namespace AvancedLibrary {
    enum ReservationStatus { WAITING, NOTIFIED, EXPIRED, COMPLETED };
    struct ReservationProps {
        std::optional<std::chrono::time_point<std::chrono::system_clock>> reservationDate;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> notificationDate;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
        unsigned queuePosition;
        ReservationStatus status;
    };
    class Reservation : public Domain::Entity<ReservationProps> {
       public:
        Reservation(Domain::CreateEntityProps<ReservationProps>& entityProps);
        void validate() const override;
        void notify();
        void expire();
        void updateQueuePosition(unsigned newPosition);
        bool isExpired();
    };
}  // namespace AvancedLibrary