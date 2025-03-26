cmake_minimum_required(VERSION 3.10)

# 项目名称
project(HospitalSystemTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

# 编译选项
add_compile_options(-g)

# ========== 修改这里为你的 路径 ==========
# 包含头文件目录
include_directories(
    header
    "C:/Program Files/MySQL/mysql-connector-c++-9.2.0-winx64/include"
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/ConnectMySQL/header/ConnectMySQL.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/header/Doctor.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/header/MedicalStaff.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Patient/header/Patient.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Nurse/header/Nurse.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/HospitalBranch/header/HospitalBranch.h
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Pharmacy/header/Pharmacy.h
)

# 库文件目录
link_directories(
    "C:/Program Files/MySQL/mysql-connector-c++-9.2.0-winx64/lib64/vs14"
    
)

# ========== 设置源代码路径（推荐使用相对路径） ==========
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/HospitalSystemTest.cpp
    ${CMAKE_SOURCE_DIR}/HospitalSystem.cpp
)

# 创建可执行文件
add_executable(HospitalSystemTest
    ${SOURCE_FILES}
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/MedicalStaff.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/Doctor.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Patient/Patient.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Nurse/Nurse.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/HospitalBranch/HospitalBranch.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Pharmacy/Pharmacy.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/ConnectMySQL/ConnectMySQL.cpp
)

# 链接 MySQL 和 SSL 相关静态库
target_link_libraries(HospitalSystemTest
    "C:/Program Files/MySQL/mysql-connector-c++-9.2.0-winx64/lib64/vs14/mysqlcppconnx.lib"
    "C:/Program Files/MySQL/mysql-connector-c++-9.2.0-winx64/lib64/vs14/libcrypto.lib"
    "C:/Program Files/MySQL/mysql-connector-c++-9.2.0-winx64/lib64/vs14/libssl.lib"
)
    
    
