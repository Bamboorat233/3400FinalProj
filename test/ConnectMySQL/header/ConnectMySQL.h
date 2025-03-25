#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H

#include <string>
#include <C:\Program Files\MySQL\mysql-connector-c++-9.2.0-winx64\include\mysqlx\xdevapi.h>

class ConnectMySQL {
private:
    std::string host;
    int port;
    std::string user;
    std::string password;
    std::string dbName;

    mysqlx::Session* session;

public:
    ConnectMySQL(const std::string& host,
                 int port,
                 const std::string& user,
                 const std::string& password,
                 const std::string& dbName);

    ~ConnectMySQL();

    bool connect();
    void close();

    mysqlx::Schema& getSchema();
    mysqlx::Table getTable(const std::string& tableName);

    bool isConnected() const;

    void insertPatient(int patientID, const std::string& info, int hospitalID, const std::string& medicalCondition, int attendingDoctorID);

    void updatePatient(int patientID, const std::string& info, int hospitalID, const std::string& medicalCondition, int attendingDoctorID);

    void queryAllPatient();
};

#endif // CONNECTMYSQL_H
