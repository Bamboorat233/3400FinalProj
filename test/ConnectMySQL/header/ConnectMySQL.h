#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H

#include <C:\Program Files\MySQL\mysql-connector-c++-9.2.0-winx64\include\mysqlx\xdevapi.h>

#include <string>

#include "../../Doctor/header/Doctor.h"
#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"
#include "../../Pharmacy/header/Pharmacy.h"

class ConnectMySQL {
   private:
    std::string host;
    int port;
    std::string user;
    std::string password;
    std::string dbName;

    mysqlx::Session* session;

   public:
    ConnectMySQL(const std::string& host, int port, const std::string& user,
                 const std::string& password, const std::string& dbName);

    ~ConnectMySQL();

    bool connect();
    void close();

    mysqlx::Table getTable(const std::string& tableName);

    bool isConnected() const;

    void insertPatient(int patientID, const std::string& info, int hospitalID,
                       const std::string& medicalCondition,
                       int attendingDoctorID);

    void movePatientToDiffBranch(int patientID, int hospitalID);

    void queryAllPatient();

    int queryHospitalBranch(int i);

    int queryPharmacy(int i);

    int queryLastPatientID();

    bool doctorExists(int doctorID);

    std::unordered_map<int, Patient> loadAllPatients();
    std::vector<Pharmacy> loadAllPharmacies();
    std::vector<HospitalBranch> loadAllHospitalBranches();
    std::vector<Doctor> loadAllDoctors();
    std::vector<Nurse> loadAllNurses();

    void addDoctor(int staffID, const std::string& name, int assignedHospital);
    void addNurse(int staffID, const std::string& name, int assignedHospital);
    void addPharmacy(int pharmacyID, double totalBill = 0.0);
    void updatePharmacyBill(int pharmacyID, double newTotalBill);
};

#endif  // CONNECTMYSQL_H
