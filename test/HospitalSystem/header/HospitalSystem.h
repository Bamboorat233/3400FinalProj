#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <string>
#include <unordered_map>

#include "../../ConnectMySQL/header/ConnectMySQL.h"
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
    ConnectMySQL db;

   public:
    HospitalSystem();
    ~HospitalSystem();
    int registerPatient(const std::string info, int hospitalID,
                        const std::string& medicalCondition,
                        int attendingDoctorID);
    bool transferPatient(int patientID, int newBranch);
    void addDoctor(int branchID, int staffID, const std::string& name);
    void addNurse(int branchID, int staffID, const std::string& name);
    void addPharmacy(Pharmacy&& pharma);
    void generateFinancialReport() const;
    void AssignDoctorToPatient(int patientID);
    void nurseAssignPatient(int patientID);
    void nurseReleasePatient(int staffID, int patientID);
    HospitalBranch getBranch(int branchID);
};

#endif  // HOSPITAL_SYSTEM_H
