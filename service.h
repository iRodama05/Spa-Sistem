#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream> 

class Service {
protected:
    std::string serviceName;
    int duration; // en minutos
    double basePrice;
    std::string appointmentTime;

public:
    // Constructor
    Service(const std::string& name, int dur, double bPrice);


    virtual ~Service();

    // Setters
    void setAppointmentTime(const std::string& time);

    // Getters
    std::string getServiceName() const;
    int getDuration() const;
    double getBasePrice() const;
    std::string getAppointmentTime() const;

    virtual double calculateFinalPrice() = 0; 
    virtual void displayBookingDetails() const = 0;
};

#endif