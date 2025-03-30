#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <string>
#include <unordered_map>
#include <vector>

#include "../../Doctor/header/Doctor.h"
#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"
#include "../../Pharmacy/header/Pharmacy.h"

class HospitalSystem {
   private:
    std::vector<HospitalBranch> branches;
    std::vector<Pharmacy> pharmacies;
    std::unordered_map<int, Patient> allPatients;
    static int nextPatientID;

   public:
    HospitalSystem();

    void initializeSystem();
    int registerPatient(std::string info);
    bool transferPatient(int patientID, int newBranch);
    void addDoctor(int branchID, Doctor&& doc);
    void addNurse(int branchID, Nurse&& nrs);
    void addPharmacy(Pharmacy&& pharma);
    void generateFinancialReport() const;
    void AssignDoctorToPatient(int patientID, int staffID);
    void nurseAssignPatient(int staffID, int patientID);
    void nurseReleasePatient(int staffID, int patientID);
};

#endif  // HOSPITAL_SYSTEM_H
