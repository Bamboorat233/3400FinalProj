#include "header/HospitalSystem.h"

int main() {
    HospitalSystem system;

    Pharmacy pharmacy1(21);

    system.initializeSystem();

    // Register two new patients
    int pid1 = system.registerPatient("Xiaoming, Male, 35 years old");
    int pid2 = system.registerPatient("Xiaohong, Female, 28 years old");

    // Transfer patients to other branches
    system.transferPatient(pid1, 2);
    system.transferPatient(pid2, 3);

    // Register an additional pharmacy
    system.addPharmacy(std::move(pharmacy1));

    // Add a doctor and a nurse
    Doctor d1(501, "Dr. Zhao", 1);
    Nurse n1(601, "Nurse Wang", 1);
    system.addDoctor(1, std::move(d1));
    system.addNurse(1, std::move(n1));

    // Financial report
    system.generateFinancialReport();

    return 0;
}
