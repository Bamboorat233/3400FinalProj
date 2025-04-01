#include <iostream>
#include <string>

#include "header/HospitalSystem.h"

using namespace std;

int main() {
    HospitalSystem hospitalSystem;
    bool running = true;

    while (running) {
        cout << "\n====== Hospital System UI ======\n";
        cout << "1. Register Patient\n";
        cout << "2. Transfer Patient\n";
        cout << "3. Assign Doctor to Patient\n";
        cout << "4. Assign Nurse to Patient\n";
        cout << "5. Generate Financial Report\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {  // 注册病人
                string info, condition;
                int hospitalID, doctorID;

                cout << "Enter patient info: ";
                cin.ignore();
                getline(cin, info);

                cout << "Enter hospital ID: ";
                cin >> hospitalID;

                cout << "Enter medical condition: ";
                cin.ignore();
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
            case 2: {  // 转移病人
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
            case 3: {  // 为病人分配医生
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                hospitalSystem.AssignDoctorToPatient(patientID);
                break;
            }
            case 4: {  // 为病人分配护士
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;

                hospitalSystem.nurseAssignPatient(patientID);
                break;
            }
            case 5: {  // 生成财务报告
                hospitalSystem.generateFinancialReport();
                break;
            }
            case 6: {  // 添加医生
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
            case 7: {  // 添加护士
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
            case 8: {  // 退出系统
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
