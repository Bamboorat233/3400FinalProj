#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H

#include <C:\Program Files\MySQL\mysql-connector-c++-9.2.0-winx64\include\mysqlx\xdevapi.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "../../Doctor/header/Doctor.h"
#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"
#include "../../Pharmacy/header/Pharmacy.h"

// This class handles MySQL connection and queries for the hospital system
class ConnectMySQL {
   private:
    std::string host;
    int port;
    std::string user;
    std::string password;
    std::string dbName;

    mysqlx::Session* session; // Pointer to active database session

   public:
    // Constructor to initialize connection parameters
    ConnectMySQL(const std::string& host, int port, const std::string& user,
                 const std::string& password, const std::string& dbName);

    // Destructor closes the session if connected
    ~ConnectMySQL();

    // Connect to the MySQL server
    bool connect();

    // Close the session and clean up
    void close();

    // Get a reference to a specific table
    mysqlx::Table getTable(const std::string& tableName);

    // Check if connection is active
    bool isConnected() const;

    // Insert new patient into database
    void insertPatient(int patientID, const std::string& info, int hospitalID,
                       const std::string& medicalCondition,
                       int attendingDoctorID);

    // Update patient info during transfer to another branch
    void movePatientToDiffBranch(int patientID, const std::string& info,
                                 int hospitalID,
                                 const std::string& medicalCondition,
                                 int attendingDoctorID);

    // Print all patients (debugging purpose)
    void queryAllPatient();

    // Query hospital branch ID by index
    int queryHospitalBranch(int i);

    // Query pharmacy ID by index (from HospitalBranch table)
    int queryPharmacy(int i);

    // Get the maximum patient ID (latest registered)
    int queryLastPatientID();

    // Check if a doctor exists
    bool doctorExists(int doctorID);

    // Load all patients from the database
    std::unordered_map<int, Patient> loadAllPatients();

    // Load all pharmacies
    std::vector<Pharmacy> loadAllPharmacies();

    // Load all hospital branches
    std::vector<HospitalBranch> loadAllHospitalBranches();

    // Add new doctor (inserts to MedicalStaff and Doctor tables)
    void addDoctor(int staffID, const std::string& name, int assignedHospital);

    // Add new nurse (inserts to MedicalStaff and Nurse tables)
    void addNurse(int staffID, const std::string& name, int assignedHospital);

    // Add new pharmacy
    void addPharmacy(int pharmacyID, double totalBill = 0.0);

    // Update total bill for a pharmacy
    void updatePharmacyBill(int pharmacyID, double newTotalBill);
};

#endif  // CONNECTMYSQL_H
