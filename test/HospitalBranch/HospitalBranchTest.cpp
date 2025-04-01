#include "header/HospitalBranch.h"
#include "../../Patient/header/Patient.h"
#include "../../Doctor/header/Doctor.h"
#include "../../Nurse/header/Nurse.h"

int main() {
    // Create hospital branch object (ID = 1)
    HospitalBranch branch(1);

    // Create doctors (at least 3)
    Doctor d1(101, "Dr. Smith", 1);
    Doctor d2(102, "Dr. Johnson", 1);
    Doctor d3(103, "Dr. Brown", 1);

    // Create nurses (at least 5)
    Nurse n1(201, "Nurse Emily", 1);
    Nurse n2(202, "Nurse Olivia", 1);
    Nurse n3(203, "Nurse Ava", 1);
    Nurse n4(204, "Nurse Sophia", 1);
    Nurse n5(205, "Nurse Mia", 1);

    // Add doctors and nurses to the hospital branch
    branch.addDoctor(std::move(d1));
    branch.addDoctor(std::move(d2));
    branch.addDoctor(std::move(d3));
    
    branch.addNurse(std::move(n1));
    branch.addNurse(std::move(n2));
    branch.addNurse(std::move(n3));
    branch.addNurse(std::move(n4));
    branch.addNurse(std::move(n5));
    

    // Create patients
    Patient p1(301, "Tom", 1);
    Patient p2(302, "Alice", 1);

    // Admit patients
    branch.admitPatient(p1, 101);  // Admit Tom with Dr. Smith
    branch.admitPatient(p2, 102);  // Admit Alice with Dr. Johnson

    // Assign doctor and nurse
    branch.assignDoctor(301);
    branch.assignNurse(301);

    // Medication purchase
    branch.purchaseMedication(1, 800.0);
    branch.purchaseMedication(2, 500.0);

    // Display daily report
    branch.displayDailyReport();

    // Discharge patient
    branch.dischargePatient(301);
    branch.displayDailyReport();

    return 0;
}
