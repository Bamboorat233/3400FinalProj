#ifndef PHARMACY_H
#define PHARMACY_H

#include <iostream>

class Pharmacy {
    private:
        int pharmacyID;
        double totalBill;

    public:
        // 构造函数
        Pharmacy(int id);
        Pharmacy();
        Pharmacy(const Pharmacy& other);
        
        // 添加账单金额
        void addBill(double amount);
        
        // 获取当前总账单
        double getTotalBill() const;
        void setTotalBill(double amount);
        
        // 获取和设置药房ID
        int getPharmacyID() const;
        void setpharmacyID(int id);

        // 析构函数
        ~Pharmacy();
};

#endif // PHARMACY_H
