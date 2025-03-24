#include "../HospitalSystem/header/HospitalSystem.h"

int main() {
    HospitalSystem system;

    system.initializeSystem();

    // 注册两个新患者
    int pid1 = system.registerPatient("小明，男，35岁");
    int pid2 = system.registerPatient("小红，女，28岁");

    // 转移患者到其他院区
    system.transferPatient(pid1, 2);
    system.transferPatient(pid2, 3);

    // 注册一个额外药房
    system.addPharmacy(Pharmacy(21));

    // 添加医生和护士
    Doctor d1(501, "赵医生", 1);
    Nurse n1(601, "王护士", 1);
    system.addDoctor(1, d1);
    system.addNurse(1, n1);

    // 财务报告
    system.generateFinancialReport();

    return 0;
}
