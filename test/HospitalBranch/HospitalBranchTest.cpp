#include "../../HospitalBranch/header/HospitalBranch.h"
#include "../../Patient/header/Patient.h"
#include "../../Doctor/header/Doctor.h"
#include "../../Nurse/header/Nurse.h"

int main() {
    // 创建院区对象（ID = 1）
    HospitalBranch branch(1);

    // 创建医生（至少3人）
    Doctor d1(101, "张医生", 1);
    Doctor d2(102, "王医生", 1);
    Doctor d3(103, "李医生", 1);

    // 创建护士（至少5人）
    Nurse n1(201, "赵护士", 1);
    Nurse n2(202, "钱护士", 1);
    Nurse n3(203, "孙护士", 1);
    Nurse n4(204, "李护士", 1);
    Nurse n5(205, "周护士", 1);

    // 使用系统函数添加医生和护士
    branch.addDoctor(d1);
    branch.addDoctor(d2);
    branch.addDoctor(d3);

    branch.addNurse(n1);
    branch.addNurse(n2);
    branch.addNurse(n3);
    branch.addNurse(n4);
    branch.addNurse(n5);

    // 创建患者
    Patient p1(301, "小明", 1);
    Patient p2(302, "小红", 1);

    // 接收患者
    branch.admitPatient(p1, 101);  // 用张医生接收小明
    branch.admitPatient(p2, 102);  // 用王医生接收小红

    // 分配医护
    branch.assignDoctor(301);
    branch.assignNurse(301);

    // 药品采购
    branch.purchaseMedication(1, 800.0);
    branch.purchaseMedication(2, 500.0);

    // 显示日报
    branch.displayDailyReport();

    // 出院操作
    branch.dischargePatient(301);
    branch.displayDailyReport();

    return 0;
}
