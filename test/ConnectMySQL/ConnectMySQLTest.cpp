#include <iostream>

#include "ConnectMySQL.h"

int main() {
    std::cout << "[TEST] connecting to database..." << std::endl;

    // 创建连接对象
    ConnectMySQL db("localhost", 33060, "root", "2002", "hospitaldb");

    // 连接数据库
    if (!db.connect()) {
        std::cerr << "[TEST ERROR] failed to connect to database" << std::endl;
        return 1;
    }

    std::cout << "[TEST] database connected successfully" << std::endl;

    // 更新患者信息
    std::cout << "[TEST] updating patient data..." << std::endl;
    db.updatePatient(1, "Bob, Male, 30", 2, "diabetes", 1001);

    // 测试查询所有患者
    std::cout << "[TEST] querying all patient data..." << std::endl;
    db.queryAllPatient();

    // 关闭连接
    db.close();

    std::cout << "[TEST] test finished" << std::endl;
    return 0;
}
