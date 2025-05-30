#ifndef PERSONALIZEDMASSAGE_H
#define PERSONALIZEDMASSAGE_H

#include "Service.h"
#include <string>

class PersonalizedMassage : public Service {
private:
    bool isReturningClient;
    double calculatedFinalPrice;

    // Constantes para la lógica de cálculo de precios
    static const double SURCHARGE_THRESHOLD_DURATION;
    static const double SURCHARGE_AMOUNT; // [cite: 8]
    static const double DISCOUNT_RATE;    // [cite: 9]

public:
    // Constructores
    PersonalizedMassage(const std::string& name, int dur, double bPrice);
    PersonalizedMassage(const std::string& name, int dur, double bPrice, bool isReturning);

    // Setter para el estado del cliente
    void setIsReturningClient(bool isReturning);

    // Override
    double calculateFinalPrice() override;
    void displayBookingDetails() const override;
};

#endif