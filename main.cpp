#include <iostream>
#include "PersonalizedMassage.h"

int main() {
    std::cout << "SPA Service Management System" << std::endl;
    std::cout << "-----------------------------" << std::endl << std::endl;

    // Escenario 1: Cliente nuevo, masaje largo
    std::cout << "Scenario 1: New Client, Long Massage (75 minutes)" << std::endl;
    PersonalizedMassage massage1("Personalized therapeutic massage", 75, 1400.00);
    massage1.setAppointmentTime("3:00 PM"); 
    
    
    massage1.calculateFinalPrice();
    massage1.displayBookingDetails();
    std::cout << std::endl;

    // Escenario 2: Cliente recurrente, masaje de duración estándar
    std::cout << "Scenario 2: Returning Client, Standard Massage (60 minutes)" << std::endl;
    PersonalizedMassage massage2("Personalized therapeutic massage", 60, 1200.00);
    massage2.setAppointmentTime("4:00 PM");
    massage2.setIsReturningClient(true);
    
    massage2.calculateFinalPrice();
    massage2.displayBookingDetails();
    std::cout << std::endl;

    return 0;
}