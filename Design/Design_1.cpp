#include <vector>
#include <string>
#include <unordered_map>

// 药房类
class Pharmacy {
public:
    Pharmacy(int id);
    void addBill(double amount);   // 记录账单
    double getTotalBill() const;   // 获取总账单
private:
    int pharmacyID;
    double totalBill;
};

// 医护人员基类
class MedicalStaff {
protected:
    int staffID;
    std::string name;
    int assignedHospital;
};

// 医生类
class Doctor : public MedicalStaff {
public:
    bool assignPatient(int patientID);  // 分配患者
    void releasePatient(int patientID); // 解除患者
private:
    std::vector<int> assignedPatients; // 负责的患者ID列表
};

// 护士类
class Nurse : public MedicalStaff {
public:
    bool assignPatient(int patientID);  // 分配患者
    void releasePatient(int patientID); // 解除患者
private:
    std::vector<int> assignedPatients; // 最多2个患者
};

// 患者类
class Patient {
public:
    Patient(int id, std::string info);
    void updateCondition(std::string condition); // 更新病情
    void addTreatment(std::string treatment);    // 添加治疗方案
    void transferHospital(int newHospitalID);    // 转移院区
private:
    int patientID;
    int currentHospitalID;
    std::string personalInfo;
    std::string medicalCondition;
    std::vector<std::string> treatments;
    int attendingDoctorID;  // 主治医生
    std::vector<int> consultingDoctors;  // 会诊医生
};

// 医院院区类
class HospitalBranch {
public:
    // 患者管理
    bool admitPatient(Patient& p, int doctorID); // 接收患者
    bool dischargePatient(int patientID);        // 出院结算
    
    // 资源管理
    bool assignDoctor(int patientID);      // 分配主治医生
    bool assignNurse(int patientID);       // 分配护士
    
    // 药品采购
    void purchaseMedication(int pharmacyID, double amount); // 药品采购
    
    // 状态查询
    int getAvailableBeds() const;          // 获取剩余床位
    void displayDailyReport() const;       // 生成日报表
    
private:
    int branchID;
    std::vector<Patient> patients;        // 当前患者（最多20）
    std::vector<Doctor> doctors;          // 至少3名医生
    std::vector<Nurse> nurses;            // 至少5名护士
    std::unordered_map<int, double> pharmacyBills; // 药房账单
};

// 医院管理系统核心类
class HospitalSystem {
public:
    // 系统初始化
    void initializeSystem();  // 初始化5个院区、药房、医护人员
    
    // 患者流程
    int registerPatient(std::string info);          // 登记新患者
    bool transferPatient(int patientID, int newBranch); // 转院
    
    // 医护管理
    void addDoctor(int branchID, Doctor doc);       // 添加医生
    void addNurse(int branchID, Nurse nrs);         // 添加护士
    
    // 药品管理
    void addPharmacy(Pharmacy pharma);              // 注册药房
    
    // 财务系统
    void generateFinancialReport() const;           // 生成财务报告
    
private:
    std::vector<HospitalBranch> branches;  // 5个院区
    std::vector<Pharmacy> pharmacies;      // 20个药房
    std::unordered_map<int, Patient> allPatients; // 所有患者
    static int nextPatientID;             // 患者ID生成器
};