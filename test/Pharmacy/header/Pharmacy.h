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
        Pharmacy(const Pharmacy& other);
        
        // 添加账单金额
        void addBill(double amount);
        
        // 获取当前总账单
        double getTotalBill() const;
        void setTotalBill(double amount);
        
        // 获取和设置药房ID
        int getPharmacyID() const;
        void setpharmacyID(int id);

        Pharmacy(Pharmacy&& other) noexcept;               // ✅ 移动构造
        Pharmacy& operator=(Pharmacy&& other) noexcept;    // ✅ 移动赋值

        // 析构函数
        ~Pharmacy();
};

#endif // PHARMACY_H
