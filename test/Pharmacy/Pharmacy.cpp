#include "header/Pharmacy.h"

// 构造函数实现
Pharmacy::Pharmacy(int id) : pharmacyID(id), totalBill(0.0) {}

Pharmacy::Pharmacy() : pharmacyID(NULL), totalBill(NULL) {}

Pharmacy::Pharmacy(const Pharmacy& other) : pharmacyID(other.pharmacyID), totalBill(other.totalBill) {}

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
    std::cout << "Pharmacy " << pharmacyID << " is destroyed." << std::endl;
}