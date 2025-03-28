#include <iostream>

#include "header/ConnectMySQL.h"

ConnectMySQL::ConnectMySQL(const std::string& host, int port,
                           const std::string& user, const std::string& password,
                           const std::string& dbName)
    : host(host),
      port(port),
      user(user),
      password(password),
      dbName(dbName),
      session(nullptr) {}

ConnectMySQL::~ConnectMySQL() { close(); }

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

bool ConnectMySQL::isConnected() const { return session != nullptr; }

void ConnectMySQL::insertPatient(int patientID, const std::string& info,
                                 int hospitalID,
                                 const std::string& medicalCondition,
                                 int attendingDoctorID) {
    try {
        session->getSchema(dbName)
            .getTable("Patient")
            .insert("patientID", "personalInfo", "currentHospitalID",
                    "medicalCondition", "attendingDoctorID")
            .values(patientID, info, hospitalID, medicalCondition,
                    attendingDoctorID)
            .execute();
        std::cout << "Patient inserted!" << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "Insert patient failed: " << err.what() << std::endl;
    }
}

void ConnectMySQL::movePatientToDiffBranch(int patientID,
                                           const std::string& info,
                                           int hospitalID,
                                           const std::string& medicalCondition,
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
        std::cerr << "Query doctors failed: " << err.what() << std::endl;
    }
}

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
        return -1;  // 表示未找到

    } catch (const mysqlx::Error& err) {
        std::cerr << "Query hospital branches failed: " << err.what()
                  << std::endl;
        return -1;  // 表示失败
    }
}

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
        return -1;  // 表示未找到

    } catch (const mysqlx::Error& err) {
        std::cerr << "Query hospital branches failed: " << err.what()
                  << std::endl;
        return -1;  // 表示失败
    }
}

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
        return -1;  // 如果表为空，返回初始值 -1（下一位将是 0）
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to query last patient ID: " << err.what()
                  << std::endl;
        return -1;  // 出错时返回初始 ID
    }
}

bool ConnectMySQL::doctorExists(int doctorID) {
    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("Doctor")
                                    .select("staffID")
                                    .where("staffID = :id")
                                    .bind("id", doctorID)
                                    .execute();

        // 如果能 fetch 出来一行，说明存在
        return res.fetchOne();  // 非空即 true
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] doctorExists failed: " << err.what() << std::endl;
        return false;
    }
}

std::unordered_map<int, Patient> ConnectMySQL::loadAllPatients() {
    std::unordered_map<int, Patient> result;

    try {
        auto table = session->getSchema(dbName).getTable("Patient");

        mysqlx::RowResult res =
            table
                .select("patientID", "personalInfo", "currentHospitalID",
                        "medicalCondition", "attendingDoctorID")
                .execute();

        for (mysqlx::Row row : res) {
            int id = row[0].get<int>();
            std::string info = row[1].get<std::string>();
            int hospitalID = row[2].get<int>();
            std::string condition = row[3].get<std::string>();
            int doctorID = row[4].get<int>();

            // 创建 Patient 实例（根据你的 Patient 构造函数）
            Patient p(id, info, hospitalID);
            p.setAttendingDoctor(doctorID);
            p.updateCondition(condition);
            result.emplace(id, std::move(p));
        }
    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load patients: " << err.what()
                  << std::endl;
    }

    return result;
}

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

            result.emplace_back(
                id, bill);  // 假设 Pharmacy 构造函数是 Pharmacy(int, double)
        }

    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load pharmacies: " << err.what()
                  << std::endl;
    }

    return result;
}

std::vector<HospitalBranch> ConnectMySQL::loadAllHospitalBranches() {
    std::vector<HospitalBranch> result;

    try {
        mysqlx::RowResult res = session->getSchema(dbName)
                                    .getTable("HospitalBranch")
                                    .select("branchID")
                                    .execute();

        for (mysqlx::Row row : res) {
            int id = row[0].get<int>();
            result.emplace_back(
                id);  // 假设 HospitalBranch 构造函数是 HospitalBranch(int)
        }

    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to load hospital branches: " << err.what()
                  << std::endl;
    }

    return result;
}

void ConnectMySQL::addDoctor(int staffID, const std::string& name,
                             int assignedHospital) {
    try {
        auto schema = session->getSchema(dbName);

        // 先插入 MedicalStaff
        schema.getTable("MedicalStaff")
            .insert("staffID", "name", "assignedHospital")
            .values(staffID, name, assignedHospital)
            .execute();

        // 再插入 Doctor（只需 staffID）
        schema.getTable("Doctor").insert("staffID").values(staffID).execute();

        std::cout << "Doctor added: ID = " << staffID << std::endl;

    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to add doctor: " << err.what()
                  << std::endl;
    }
}

void ConnectMySQL::addNurse(int staffID, const std::string& name,
                            int assignedHospital) {
    try {
        auto schema = session->getSchema(dbName);

        // 插入到 MedicalStaff 表
        schema.getTable("MedicalStaff")
            .insert("staffID", "name", "assignedHospital")
            .values(staffID, name, assignedHospital)
            .execute();

        // 插入到 Nurse 表
        schema.getTable("Nurse").insert("staffID").values(staffID).execute();

        std::cout << "Nurse added: ID = " << staffID << std::endl;

    } catch (const mysqlx::Error& err) {
        std::cerr << "[ERROR] Failed to add nurse: " << err.what() << std::endl;
    }
}
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
        std::cerr << "[ERROR] Failed to add pharmacy: " << err.what()
                  << std::endl;
    }
}
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
        std::cerr << "[ERROR] Failed to update pharmacy bill: " << err.what()
                  << std::endl;
    }
}
