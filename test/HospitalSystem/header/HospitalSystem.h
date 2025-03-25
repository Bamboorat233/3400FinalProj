#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <vector>
#include <unordered_map>
#include <string>
#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Pharmacy/header/Pharmacy.h"
#include "../../Patient/header/Patient.h"
#include "../../Doctor/header/Doctor.h"
#include "../../Nurse/header/Nurse.h"

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
};

#endif // HOSPITAL_SYSTEM_H
