#ifndef PHARMACY_H
#define PHARMACY_H

#include <iostream>

// Pharmacy class used to track billing in the hospital system
class Pharmacy {
   private:
    int pharmacyID;       // Unique ID for the pharmacy
    double totalBill;     // Total bill amount recorded

   public:
    // Constructor with parameters
    Pharmacy(int id, double totalBill);

    // Copy constructor
    Pharmacy(const Pharmacy& other);

    // Move constructor
    Pharmacy(Pharmacy&& other) noexcept;

    // Move assignment operator
    Pharmacy& operator=(Pharmacy&& other) noexcept;

    // Add bill amount to total
    void addBill(double amount);

    // Get total bill
    double getTotalBill() const;

    // Set total bill manually
    void setTotalBill(double amount);

    // Get pharmacy ID
    int getPharmacyID() const;

    // Set pharmacy ID
    void setpharmacyID(int id);

    // Destructor
    ~Pharmacy();
};

#endif  // PHARMACY_H
