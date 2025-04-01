#include <iostream>
#include <string>

#include "header/HospitalSystem.h"

using namespace std;

int main() {
    HospitalSystem hospitalSystem;  // Main hospital system object
    bool running = true;

    // Main menu loop
    while (running) {
        cout << "\n====== Hospital System UI ======\n";
        cout << "1. Register Patient\n";
        cout << "2. Transfer Patient\n";
        cout << "3. Assign Doctor to Patient\n";
        cout << "4. Assign Nurse to Patient\n";
        cout << "5. Generate Financial Report\n";
        cout << "6. Add Doctor\n";
        cout << "7. Add Nurse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {  // ✅ Register new patient
                string info, condition;
                int hospitalID, doctorID;

                cout << "Enter patient info: ";
                cin.ignore();              // clear input buffer
                getline(cin, info);        // read full line

                cout << "Enter hospital ID: ";
                cin >> hospitalID;

                cout << "Enter medical condition: ";
                cin.ignore();              // clear buffer again
                getline(cin, condition);

                cout << "Enter attending doctor ID: ";
                cin >> doctorID;

                int patientID = hospitalSystem.registerPatient(
                    info, hospitalID, condition, doctorID);
                if (patientID != -1) {
                    cout << "Patient registered successfully! Patient ID: "
                         << patientID << endl;
                }
                break;
            }
            case 2: {  // ✅ Transfer patient to another branch
                int patientID, newBranch;

                cout << "Enter patient ID: ";
                cin >> patientID;

                cout << "Enter new branch ID: ";
                cin >> newBranch;

                if (hospitalSystem.transferPatient(patientID, newBranch)) {
                    cout << "Patient transferred successfully!" << endl;
                }
                break;
            }
            case 3: {  // ✅ Assign multiple doctors to patient (consultation)
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                hospitalSystem.AssignDoctorToPatient(patientID);
                break;
            }
            case 4: {  // ✅ Assign nurse to patient
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                hospitalSystem.nurseAssignPatient(patientID);
                break;
            }
            case 5: {  // ✅ Generate financial report for all pharmacies
                hospitalSystem.generateFinancialReport();
                break;
            }
            case 6: {  // ✅ Add new doctor to a branch
                int branchID, staffID;
                string name;

                cout << "Enter branch ID: ";
                cin >> branchID;
                cout << "Enter doctor ID: ";
                cin >> staffID;
                cout << "Enter doctor name: ";
                cin.ignore();
                getline(cin, name);

                hospitalSystem.addDoctor(branchID, staffID, name);
                break;
            }
            case 7: {  // ✅ Add new nurse to a branch
                int branchID, staffID;
                string name;

                cout << "Enter branch ID: ";
                cin >> branchID;
                cout << "Enter nurse ID: ";
                cin >> staffID;
                cout << "Enter nurse name: ";
                cin.ignore();
                getline(cin, name);

                hospitalSystem.addNurse(branchID, staffID, name);
                break;
            }
            case 8: {  // ✅ Exit the program
                running = false;
                cout << "Exiting the system. Goodbye!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}