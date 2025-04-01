#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H

#include <string>

// Base class for medical personnel (Doctor and Nurse)
class MedicalStaff {
   private:
    int staffID;             // Unique ID for the staff member
    std::string name;        // Staff name
    int assignedHospital;    // ID of the hospital the staff is assigned to

   public:
    // Default constructor
    MedicalStaff();

    // Constructor with parameters
    MedicalStaff(int id, const std::string& name, int hospital);

    // Copy constructor
    MedicalStaff(const MedicalStaff& other);

    // Move constructor
    MedicalStaff(MedicalStaff&& other) noexcept;

    // Destructor
    ~MedicalStaff();

    // Copy assignment operator
    MedicalStaff& operator=(const MedicalStaff& other);

    // Move assignment operator
    MedicalStaff& operator=(MedicalStaff&& other) noexcept;

    // Getters
    int getStaffID() const;
    std::string getName() const;
    int getAssignedHospital() const;

    // Setters
    void setStaffID(int id);
    void setName(const std::string& name);
    void setAssignedHospital(int hospital);
};

#endif  // MEDICALSTAFF_H
