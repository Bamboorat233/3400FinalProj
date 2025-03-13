#include "Patient.h"
#include <iostream>

void testPatient() {
    std::cout << "Testing Patient class...\n";

    // 创建患者对象
    Patient patient1(2001, "John Doe, 30, Male", 101);

    // 更新病情
    patient1.updateCondition("Flu with mild fever");

    // 添加治疗方案
    patient1.addTreatment("Antibiotics");
    patient1.addTreatment("Rest and hydration");

    // 设置主治医生
    patient1.setAttendingDoctor(501);

    // 添加会诊医生
    patient1.addConsultingDoctor(601);
    patient1.addConsultingDoctor(602);

    // 移除会诊医生
    patient1.removeConsultingDoctor(601);

    // 转移院区
    patient1.transferHospital(102);

    // 显示患者信息
    patient1.displayInfo();
}

int main() {
    testPatient();
    return 0;
}
