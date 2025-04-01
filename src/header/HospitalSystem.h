#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <string>
#include <unordered_map>

#include "../../ConnectMySQL/header/ConnectMySQL.h"
#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"
#include "../../Pharmacy/header/Pharmacy.h"

// Main system class to manage multiple hospital branches
class HospitalSystem {
   private:
    std::vector<HospitalBranch> branches;           // 5 hospital branches
    std::vector<Pharmacy> pharmacies;               // 20 pharmacies
    std::unordered_map<int, Patient> allPatients;   // All patient records
    static int nextPatientID;                       // Patient ID generator
    ConnectMySQL db;                                // Database interface

   public:
    HospitalSystem();               // Constructor: initialize system
    ~HospitalSystem();              // Destructor: close DB connection

    // Register a new patient
    int registerPatient(const std::string info, int hospitalID,
                        const std::string& medicalCondition,
                        int attendingDoctorID);

    // Transfer patient to another branch
    bool transferPatient(int patientID, int newBranch);

    // Add doctor to a specific branch
    void addDoctor(int branchID, int staffID, const std::string& name);

    // Add nurse to a specific branch
    void addNurse(int branchID, int staffID, const std::string& name);

    // Register a new pharmacy
    void addPharmacy(Pharmacy&& pharma);

    // Print total bills from all pharmacies
    void generateFinancialReport() const;

    // Assign consulting doctors to patient
    void AssignDoctorToPatient(int patientID);

    // Assign nurse to patient
    void nurseAssignPatient(int patientID);

    // Release nurse from a patient
    void nurseReleasePatient(int staffID, int patientID);

    // Get branch object by ID
    HospitalBranch getBranch(int branchID);
};

#endif  // HOSPITAL_SYSTEM_H
