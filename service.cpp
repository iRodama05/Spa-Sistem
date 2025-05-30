#include "Service.h"

// Constructor
Service::Service(const std::string& name, int dur, double bPrice)
    : serviceName(name), duration(dur), basePrice(bPrice), appointmentTime("") {}

// Destructor virtual
Service::~Service() {}

// Setters
void Service::setAppointmentTime(const std::string& time) {
    appointmentTime = time;
}

// Getters
std::string Service::getServiceName() const {
    return serviceName;
}

int Service::getDuration() const {
    return duration;
}

double Service::getBasePrice() const {
    return basePrice;
}

std::string Service::getAppointmentTime() const {
    return appointmentTime;
}
