# Hospital Management System

## Introduction

This is a simple C++ hospital management system that integrates a **MySQL database** using the **MySQL Connector C++ API**. The system supports various functionalities such as registering patients, transferring patients between branches, assigning doctors and nurses, generating financial reports, and adding new doctors and nurses.

## Features

1. **Register Patient**: Add new patients to the system with details including info, hospital ID, medical condition, and attending doctor ID.
2. **Transfer Patient**: Transfer patients between different hospital branches.
3. **Assign Doctor to Patient**: Automatically assign consulting doctors to a patient based on the branch.
4. **Assign Nurse to Patient**: Automatically assign nurses to a patient based on the branch.
5. **Generate Financial Report**: Display a summary of pharmacy bills for each branch.
6. **Add Doctor**: Add a new doctor to a specific hospital branch.
7. **Add Nurse**: Add a new nurse to a specific hospital branch.

## Dependencies

- **MySQL Connector C++** (Version: 9.2.0)
- **MySQL Server**
- **C++ Standard Library**
- **G++ Compiler** (or other compatible C++ compiler)

## Setup

1. Install MySQL Server and MySQL Connector C++.
2. Ensure the Connector library is properly linked during compilation.
3. Configure the database connection in `HospitalSystem.cpp`:
   ```cpp
   HospitalSystem::HospitalSystem()
       : db("localhost", 33060, "root", "2002", "hospitaldb") {}
   ```
   Modify the connection details as per your local database setup.

## Compilation
move CMakeLists.txt into src directory and run the following commands:
```bash
cd /src
# create build directory
mkdir build
# Go to the build directory
cd build
# Generate Makefile
cmake -G "MinGW Makefiles" ..
# Compile code
mingw32-make
```

## Usage

Run the compiled executable:

```bash
./HospitalSystemTest
```

Follow the menu-based UI to interact with the system.

## Database Structure

The system interacts with a MySQL database consisting of the following tables:

- `Patient`
- `Doctor`
- `Nurse`
- `Pharmacy`
- `HospitalBranch`

Ensure the tables are created and structured as expected by the `ConnectMySQL` class functions.

## Example Tables Creation (SQL)

```sql
CREATE TABLE MedicalStaff (
    staffID INT PRIMARY KEY,
    name VARCHAR(100),
    assignedHospital INT
);

CREATE TABLE Doctor (
    staffID INT PRIMARY KEY,
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID)
);

CREATE TABLE Nurse (
    staffID INT PRIMARY KEY,
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID)
);

CREATE TABLE Patient (
    patientID INT PRIMARY KEY,
    personalInfo TEXT,
    currentHospitalID INT,
    medicalCondition TEXT,
    attendingDoctorID INT
);

CREATE TABLE Pharmacy (
    pharmacyID INT PRIMARY KEY,
    totalBill DOUBLE
);

CREATE TABLE HospitalBranch (
    branchID INT PRIMARY KEY
);
```

##

### 6. 多文件编译
示例：跨文件夹多文件编译 <Doctor>
1. 在Doctor文件夹内创建CMakeLists.txt文件
```bash
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(DoctorTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-g)

include_directories(
    header
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/header
)

add_executable(DoctorTest
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/MedicalStaff.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/Doctor.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/DoctorTest.cpp
)
```
2. 生成build文件夹
```bash
# 新建文件夹build
mkdir build
# 进入文件夹
cd build
# 生成Makefile
cmake -G "MinGW Makefiles" ..
# 编译代码
mingw32-make
```
=======
