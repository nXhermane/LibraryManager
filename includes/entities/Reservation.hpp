#pragma once
#include <Entity.hpp>
#include <chrono>
#include <memory>

#include "Book.hpp"
#include "User.hpp"
namespace AvancedLibrary {
    enum ReservationStatus { WAITING, NOTIFIED, EXPIRED, COMPLETED };
    struct ReservationProps {
        std::chrono::time_point<std::chrono::system_clock> reservationDate;
        std::chrono::time_point<std::chrono::system_clock> notificationDate;
        std::shared_ptr<User> user;
        std::shared_ptr<Book> book;
        int queuePosition;
    };
    class Reservation : public Domain::Entity<ReservationProps> {
       public:
        Reservation(Domain::CreateEntityProps<ReservationProps>& entityProps);
        void validate() const override;
        void notify();
        void expire();
        void updateQueuePosition(int newPosition);
        bool isExpired();
    };
}  // namespace AvancedLibrary