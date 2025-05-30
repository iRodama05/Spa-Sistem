#include "PersonalizedMassage.h"
#include <iostream>
#include <iomanip> 


const double PersonalizedMassage::SURCHARGE_THRESHOLD_DURATION = 60.0;
const double PersonalizedMassage::SURCHARGE_AMOUNT = 200.0;
const double PersonalizedMassage::DISCOUNT_RATE = 0.10; 

// Constructor 1
PersonalizedMassage::PersonalizedMassage(const std::string& name, int dur, double bPrice)
    : Service(name, dur, bPrice), isReturningClient(false), calculatedFinalPrice(0.0) {}

// Constructor 2
PersonalizedMassage::PersonalizedMassage(const std::string& name, int dur, double bPrice, bool isReturning)
    : Service(name, dur, bPrice), isReturningClient(isReturning), calculatedFinalPrice(0.0) {}

// Setter para el estado del cliente
void PersonalizedMassage::setIsReturningClient(bool isReturning) {
    isReturningClient = isReturning;
}

// Implementación de calculateFinalPrice
double PersonalizedMassage::calculateFinalPrice() {
    calculatedFinalPrice = basePrice;
    
    // Aplicar recargo si la duración excede los 60 minutos
    if (duration > SURCHARGE_THRESHOLD_DURATION) {
        calculatedFinalPrice += SURCHARGE_AMOUNT;
    }

    // Aplicar descuento si es un cliente recurrente 
    if (isReturningClient) {
        calculatedFinalPrice -= calculatedFinalPrice * DISCOUNT_RATE;
    }
    
    return calculatedFinalPrice;
}

// Implementación de displayBookingDetails
void PersonalizedMassage::displayBookingDetails() const {
    // Configurar formato para moneda (2 decimales)
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Service: " << getServiceName() << std::endl;
    std::cout << "Duration: " << getDuration() << " minutes" << std::endl;
    std::cout << "Base Price: $" << getBasePrice() << std::endl;
    if (!appointmentTime.empty()) {
        std::cout << "Time: " << getAppointmentTime() << std::endl;
    }

    // Notas sobre recargos y descuentos
    bool surchargeWasApplied = (duration > SURCHARGE_THRESHOLD_DURATION);

    if (isReturningClient) { // Mostrar tipo de cliente si es relevante para el formato de salida
        std::cout << "Client Type: Returning Client" << std::endl;
    }

    if (surchargeWasApplied) {
        std::cout << "Note: Duration exceeds " << static_cast<int>(SURCHARGE_THRESHOLD_DURATION) 
                  << " minutes. Surcharge applied: $" << SURCHARGE_AMOUNT << std::endl; // [cite: 11]
    }

    if (isReturningClient) {
        std::cout << "Note: Returning client discount applied: " << static_cast<int>(DISCOUNT_RATE * 100) << "%" << std::endl;
    }
    
    std::cout << "Final Price: $" << calculatedFinalPrice << std::endl;
    std::cout << "Booking Confirmed" << std::endl;
    std::cout << "========================================" << std::endl;
}