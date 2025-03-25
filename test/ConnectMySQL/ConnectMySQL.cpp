#include "ConnectMySQL.h"
#include <iostream>

ConnectMySQL::ConnectMySQL(const std::string& host,
                           int port,
                           const std::string& user,
                           const std::string& password,
                           const std::string& dbName)
    : host(host), port(port), user(user), password(password), dbName(dbName), session(nullptr) {}

ConnectMySQL::~ConnectMySQL() {
    close();
}

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

void ConnectMySQL::close() {
    if (session) {
        session->close();
        delete session;
        session = nullptr;
        std::cout << "[INFO] Disconnected." << std::endl;
    }
}

mysqlx::Table ConnectMySQL::getTable(const std::string& tableName) {
    return session->getSchema(dbName).getTable(tableName);
}

bool ConnectMySQL::isConnected() const {
    return session != nullptr;
}

void ConnectMySQL::insertPatient(int patientID, const std::string& info, int hospitalID, const std::string& medicalCondition, int attendingDoctorID) {
    try {
        session->getSchema(dbName)
            .getTable("Patient")
            .insert("patientID", "personalInfo", "currentHospitalID", "medicalCondition", "attendingDoctorID")
            .values(patientID, info, hospitalID, medicalCondition, attendingDoctorID)
            .execute();
        std::cout << "Patient inserted!" << std::endl;
    }
    catch (const mysqlx::Error& err) {
        std::cerr << "Insert patient failed: " << err.what() << std::endl;
    }
}

void ConnectMySQL::updatePatient(int patientID, const std::string& info, int hospitalID, const std::string& medicalCondition, int attendingDoctorID) {
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


void ConnectMySQL::queryAllPatient() {
    try {
        mysqlx::RowResult res = session->getSchema(dbName).getTable("Patient").select("*").execute();
        for (mysqlx::Row row : res) {
            std::cout << "PatientID: " << row[0] << std::endl;
            std::cout << "PersonalInfo: " << row[1] << std::endl;
            std::cout << "CurrentHospitalID: " << row[2] << std::endl;
            
        }
    }
    catch (const mysqlx::Error& err) {
        std::cerr << "Query doctors failed: " << err.what() << std::endl;
    }
}