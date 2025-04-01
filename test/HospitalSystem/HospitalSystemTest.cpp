#include <iostream>

#include "header/HospitalSystem.h"

int main() {
    try {
        // 初始化系统（会从数据库加载病人、分院、药房）
        HospitalSystem hs;

        std::cout << "\n=== registerPatient ===" << std::endl;
        int patient1 = hs.registerPatient("Alice, Female, 28", 1, "Flu", 1001);
        int patient2 = hs.registerPatient("Bob, Male, 35", 2, "Headache", 1002);

        std::cout << "\n=== transferPatient ===" << std::endl;
        hs.transferPatient(patient1, 3);

        std::cout << "\n=== generateFinancialReport ===" << std::endl;
        hs.generateFinancialReport();

    } catch (const std::exception& e) {
        std::cerr << "[FATAL ERROR] Uncaught exception: " << e.what()
                  << std::endl;
    }

    return 0;
}
