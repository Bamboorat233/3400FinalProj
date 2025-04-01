#ifndef HOSPITAL_BRANCH_H
#define HOSPITAL_BRANCH_H

#include <unordered_map>
#include <vector>

#include "../../Doctor/header/Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"

// This class represents a single hospital branch in the network.
// It manages patients, doctors, nurses, and pharmacy billing.
class HospitalBranch {
   private:
    int branchID;  // Unique branch ID

    std::vector<Patient> patients;     // Patient list (max 20)
    std::vector<Doctor> doctors;       // Doctor list (at least 3)
    std::vector<Nurse> nurses;         // Nurse list (at least 5)
    std::unordered_map<int, double> pharmacyBills;  // Pharmacy billing record

   public:
    // Constructor
    HospitalBranch(int id);

    // Get a reference to a doctor by index
    Doctor& getDoctor(int index);

    // Patient management
    bool admitPatient(Patient& p, int doctorID);  // Admit patient with doctor
    int dischargePatient(int patientID);          // Discharge patient with fee check
    bool assignDoctor(int patientID);             // Assign doctor to patient
    bool assignNurse(int patientID);              // Assign nurse to patient
    bool nurseRelease(int patientID);             // Release nurse from patient

    // Pharmacy operations
    void purchaseMedication(int pharmacyID, double amount);  // Record medication purchase

    // Branch status
    int getAvailableBeds() const;     // Return available bed count
    void displayDailyReport() const;  // Display daily summary

    // Initialization helpers for HospitalSystem
    void addDoctor(Doctor doc);       // Add doctor to branch
    void addNurse(Nurse nrs);         // Add nurse to branch
};

#endif  // HOSPITAL_BRANCH_H
