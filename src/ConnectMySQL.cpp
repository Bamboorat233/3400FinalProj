#include <iostream>
#include "header/ConnectMySQL.h"

// Constructor: stores database connection settings
ConnectMySQL::ConnectMySQL(const std::string& host, int port,
                           const std::string& user, const std::string& password,
                           const std::string& dbName)
    : host(host),
      port(port),
      user(user),
      password(password),
      dbName(dbName),
      session(nullptr) {}

// Destructor: ensures the session is properly closed
ConnectMySQL::~ConnectMySQL() {
    close();
}

// Attempt to connect to the MySQL server
bool ConnectMySQL::connect() {
    try {
        std::cout << "[INFO] Connecting to MySQL..." << std::endl;
        session = new mysqlx::Session(mysqlx::SessionOption::HOST, host,
                                      mysqlx::SessionOption::PORT, port,
                                      mysqlx::SessionOption::USER, user,
                                      mysqlx::SessionOption::PWD, password);
        std::cout << "[INFO] Connected to MySQL." << std::endl;
        return true;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Connection failed: " << err.what() << std::endl;
        return false;
    }
}

// Close and delete the active session
void ConnectMySQL::close() {
    if (session) {
        session->close();
        delete session;
        session = nullptr;
        std::cout << "[INFO] Disconnected." << std::endl;
    }
}

// Return a table object from schema
mysqlx::Table ConnectMySQL::getTable(const std::string& tableName) {
    return session->getSchema(dbName).getTable(tableName);
}

// Check if connected
bool ConnectMySQL::isConnected() const {
    return session != nullptr;
}

// Insert new patient into Patient table
void ConnectMySQL::insertPatient(int patientID, const std::string& info,
                                 int hospitalID, const std::string& medicalCondition,
                                 int attendingDoctorID) {
    try {
        session->getSchema(dbName)
            .getTable("Patient")
            .insert("patientID", "personalInfo", "currentHospitalID",
                    "medicalCondition", "attendingDoctorID")
            .values(patientID, info, hospitalID, medicalCondition, attendingDoctorID)
            .execute();
        std::cout << "Patient inserted!" << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "Insert patient failed: " << err.what() << std::endl;
    }
}

// Update patient info (e.g. transfer to new branch)
void ConnectMySQL::movePatientToDiffBranch(int patientID, const std::string& info,
                                           int hospitalID, const std::string& medicalCondition,
                                           int attendingDoctorID) {
    try {
        session->getSchema(dbName)
            .getTable("Patient")
            .update()
            .set("personalInfo", info)
            .set("currentHospitalID", hospitalID)
            .set("medicalCondition", medicalCondition)
            .set("attendingDoctorID", attendingDoctorID)
            .where("patientID = :id")
            .bind("id", patientID)
            .execute();
        std::cout << "Patient updated!" << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "Update patient failed: " << err.what() << std::endl;
    }
}

// Query and print all patient records
void ConnectMySQL::queryAllPatient() {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("Patient")
                                    .select("*")
                                    .execute();
        for (mysqlx::Row row : res) {
            std::cout << "PatientID: " << row[0] << std::endl;
            std::cout << "PersonalInfo: " << row[1] << std::endl;
            std::cout << "CurrentHospitalID: " << row[2] << std::endl;
        }
    } catch (const mysqlx::Error& err) {
        std::cerr << "Query patients failed: " << err.what() << std::endl;
    }
}

// Return branchID at index i
int ConnectMySQL::queryHospitalBranch(int i) {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("HospitalBranch")
                                    .select("branchID")
                                    .execute();

        int count = 0;
        for (mysqlx::Row row : res) {
            if (count == i) {
                return row[0].get<int>();
            }
            ++count;
        }

        std::cerr << "[WARN] Index out of range: " << i << std::endl;
        return -1;
    } catch (const mysqlx::Error& err) {
        std::cerr << "Query hospital branches failed: " << err.what() << std::endl;
        return -1;
    }
}

// Return pharmacyID at index i
int ConnectMySQL::queryPharmacy(int i) {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("HospitalBranch")
                                    .select("Pharmacy")
                                    .execute();

        int count = 0;
        for (mysqlx::Row row : res) {
            if (count == i) {
                return row[0].get<int>();
            }
            ++count;
        }

        std::cerr << "[WARN] Index out of range: " << i << std::endl;
        return -1;
    } catch (const mysqlx::Error& err) {
        std::cerr << "Query pharmacy failed: " << err.what() << std::endl;
        return -1;
    }
}

// Query the max patientID (latest registered patient)
int ConnectMySQL::queryLastPatientID() {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("Patient")
                                    .select("MAX(patientID)")
                                    .execute();

        if (mysqlx::Row row = res.fetchOne()) {
            if (!row[0].isNull()) {
                return row[0].get<int>();
            }
        }
        return -1;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to query last patient ID: " << err.what() << std::endl;
        return -1;
    }
}

// Check whether a doctor with given ID exists
bool ConnectMySQL::doctorExists(int doctorID) {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("Doctor")
                                    .select("staffID")
                                    .where("staffID = :id")
                                    .bind("id", doctorID)
                                    .execute();

        return res.fetchOne();
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] doctorExists failed: " << err.what() << std::endl;
        return false;
    }
}

// Load all patients into a map
std::unordered_map<int, Patient> ConnectMySQL::loadAllPatients() {
    std::unordered_map<int, Patient> result;

    try {
        auto table = session->getSchema(dbName).getTable("Patient");

        mysqlx::RowResult res = table
            .select("patientID", "personalInfo", "currentHospitalID",
                    "medicalCondition", "attendingDoctorID")
            .execute();

        for (mysqlx::Row row : res) {
            int id = row[0].get<int>();
            std::string info = row[1].get<std::string>();
            int hospitalID = row[2].get<int>();
            std::string condition = row[3].get<std::string>();
            int doctorID = row[4].get<int>();

            Patient p(id, info, hospitalID);
            p.setAttendingDoctor(doctorID);
            p.updateCondition(condition);

            result.emplace(id, std::move(p));
        }
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load patients: " << err.what() << std::endl;
    }

    return result;
}

// Load all pharmacies from the database
std::vector<Pharmacy> ConnectMySQL::loadAllPharmacies() {
    std::vector<Pharmacy> result;

    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("Pharmacy")
                                    .select("pharmacyID", "totalBill")
                                    .execute();

        for (mysqlx::Row row : res) {
            int id = row[0].get<int>();
            double bill = row[1].get<double>();
            result.emplace_back(id, bill);
        }
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load pharmacies: " << err.what() << std::endl;
    }

    return result;
}

// Load all hospital branches
std::vector<HospitalBranch> ConnectMySQL::loadAllHospitalBranches() {
    std::vector<HospitalBranch> result;

    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("HospitalBranch")
                                    .select("branchID")
                                    .execute();

        for (mysqlx::Row row : res) {
            int id = row[0].get<int>();
            result.emplace_back(id);
        }
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load hospital branches: " << err.what() << std::endl;
    }

    return result;
}

// Insert new doctor into MedicalStaff and Doctor tables
void ConnectMySQL::addDoctor(int staffID, const std::string& name,
                             int assignedHospital) {
    try {
        auto schema = session->getSchema(dbName);

        schema.getTable("MedicalStaff")
            .insert("staffID", "name", "assignedHospital")
            .values(staffID, name, assignedHospital)
            .execute();

        schema.getTable("Doctor")
            .insert("staffID")
            .values(staffID)
            .execute();

        std::cout << "Doctor added: ID = " << staffID << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to add doctor: " << err.what() << std::endl;
    }
}

// Insert new nurse into MedicalStaff and Nurse tables
void ConnectMySQL::addNurse(int staffID, const std::string& name,
                            int assignedHospital) {
    try {
        auto schema = session->getSchema(dbName);

        schema.getTable("MedicalStaff")
            .insert("staffID", "name", "assignedHospital")
            .values(staffID, name, assignedHospital)
            .execute();

        schema.getTable("Nurse")
            .insert("staffID")
            .values(staffID)
            .execute();

        std::cout << "Nurse added: ID = " << staffID << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to add nurse: " << err.what() << std::endl;
    }
}

// Add a new pharmacy record
void ConnectMySQL::addPharmacy(int pharmacyID, double totalBill) {
    try {
        session->getSchema(dbName)
            .getTable("Pharmacy")
            .insert("pharmacyID", "totalBill")
            .values(pharmacyID, totalBill)
            .execute();

        std::cout << "Pharmacy added: ID = " << pharmacyID
                  << ", TotalBill = " << totalBill << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to add pharmacy: " << err.what() << std::endl;
    }
}

// Update a pharmacy's total bill
void ConnectMySQL::updatePharmacyBill(int pharmacyID, double newTotalBill) {
    try {
        session->getSchema(dbName)
            .getTable("Pharmacy")
            .update()
            .set("totalBill", newTotalBill)
            .where("pharmacyID = :id")
            .bind("id", pharmacyID)
            .execute();

        std::cout << "Pharmacy bill updated: ID = " << pharmacyID
                  << ", New Total = " << newTotalBill << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to update pharmacy bill: " << err.what() << std::endl;
    }
}
