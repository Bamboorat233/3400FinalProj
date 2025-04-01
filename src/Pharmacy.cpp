#include "header/Pharmacy.h"

// Constructor: initialize ID and total bill
Pharmacy::Pharmacy(int id, double totalBill)
    : pharmacyID(id), totalBill(totalBill) {}

// Copy constructor
Pharmacy::Pharmacy(const Pharmacy& other)
    : pharmacyID(other.pharmacyID), totalBill(other.totalBill) {}

// Move constructor
Pharmacy::Pharmacy(Pharmacy&& other) noexcept
    : pharmacyID(other.pharmacyID), totalBill(other.totalBill) {
    // Reset moved-from object
    other.pharmacyID = 0;
    other.totalBill = 0.0;
}

// Move assignment operator
Pharmacy& Pharmacy::operator=(Pharmacy&& other) noexcept {
    if (this != &other) {
        pharmacyID = other.pharmacyID;
        totalBill = other.totalBill;

        other.pharmacyID = 0;
        other.totalBill = 0.0;
    }
    return *this;
}

// Add bill amount to total
void Pharmacy::addBill(double amount) {
    totalBill += amount;
}

// Return total bill
double Pharmacy::getTotalBill() const {
    return totalBill;
}

// Set total bill manually
void Pharmacy::setTotalBill(double amount) {
    totalBill = amount;
}

// Get pharmacy ID
int Pharmacy::getPharmacyID() const {
    return pharmacyID;
}

// Set pharmacy ID
void Pharmacy::setpharmacyID(int id) {
    pharmacyID = id;
}

// Destructor
Pharmacy::~Pharmacy() {
    // Optional: log for destruction
    // std::cout << "Pharmacy " << pharmacyID << " is destroyed." << std::endl;
}
