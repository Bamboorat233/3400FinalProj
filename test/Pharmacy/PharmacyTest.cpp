#include "header/Pharmacy.h"
#include <iostream>

void testPharmacy() {
    std::cout << "Testing Pharmacy class..." << std::endl;

    // 测试默认构造函数
    Pharmacy defaultPharmacy;
    std::cout << "Default Pharmacy ID: " << defaultPharmacy.getPharmacyID() << ", Total Bill: " << defaultPharmacy.getTotalBill() << std::endl;

    // 测试带参数构造函数
    Pharmacy pharmacy1(101);
    std::cout << "Pharmacy1 ID: " << pharmacy1.getPharmacyID() << ", Total Bill: " << pharmacy1.getTotalBill() << std::endl;

    // 测试设置 ID
    pharmacy1.setpharmacyID(202);
    std::cout << "Updated Pharmacy1 ID: " << pharmacy1.getPharmacyID() << std::endl;

    // 测试添加账单
    pharmacy1.addBill(100.50);
    pharmacy1.addBill(200.75);
    std::cout << "Pharmacy1 Total Bill after adding amounts: " << pharmacy1.getTotalBill() << std::endl;

    // 测试拷贝构造函数
    Pharmacy pharmacy2(pharmacy1);
    std::cout << "Pharmacy2 (copied from Pharmacy1) ID: " << pharmacy2.getPharmacyID() << ", Total Bill: " << pharmacy2.getTotalBill() << std::endl;

    // 修改 pharmacy2 的总账单，确保不会影响 pharmacy1
    pharmacy2.setTotalBill(500.25);
    std::cout << "Pharmacy2 Updated Total Bill: " << pharmacy2.getTotalBill() << std::endl;
    std::cout << "Pharmacy1 Total Bill should remain unchanged: " << pharmacy1.getTotalBill() << std::endl;
}

int main() {
    testPharmacy();
    return 0;
}
