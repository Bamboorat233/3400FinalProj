#include "header/Pharmacy.h"

// 构造函数实现
Pharmacy::Pharmacy(int id) : pharmacyID(id), totalBill(0.0) {}

Pharmacy::Pharmacy(const Pharmacy& other) : pharmacyID(other.pharmacyID), totalBill(other.totalBill) {}

// ✅ 移动构造函数
Pharmacy::Pharmacy(Pharmacy&& other) noexcept
    : pharmacyID(other.pharmacyID), totalBill(other.totalBill) {
    other.pharmacyID = 0;
    other.totalBill = 0.0;
}

// ✅ 移动赋值运算符
Pharmacy& Pharmacy::operator=(Pharmacy&& other) noexcept {
    if (this != &other) {
        pharmacyID = other.pharmacyID;
        totalBill = other.totalBill;

        other.pharmacyID = 0;
        other.totalBill = 0.0;
    }
    return *this;
}

// 添加账单金额
void Pharmacy::addBill(double amount) {
    totalBill += amount;
}

// 获取当前总账单
double Pharmacy::getTotalBill() const {
    return totalBill;
}

void Pharmacy::setTotalBill(double amount) {
    totalBill = amount;
}

int Pharmacy::getPharmacyID() const {
    return pharmacyID;
}

void Pharmacy::setpharmacyID(int id) {
    pharmacyID = id;
}



Pharmacy::~Pharmacy() {
    //std::cout << "Pharmacy " << pharmacyID << " is destroyed." << std::endl;
}