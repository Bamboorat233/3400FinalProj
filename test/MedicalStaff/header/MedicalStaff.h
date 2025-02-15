#ifndef MedicalStaff_H
#define MedicalStaff_H
#include <string>

class MedicalStaff {
    protected:
        int staffID;
        std::string name;
        int assignedHospital;

    public:
        MedicalStaff(int id, std::string n, int h);

        MedicalStaff();

        MedicalStaff(const MedicalStaff& staff);

        void setAssignedHospital(int h);

        int getAssignedHospital() const;

        void setStaffID(int id);

        int getStaffID() const;

        std::string getName() const;

        void setName(std::string n);

        ~MedicalStaff();
};

#endif // MedicalStaff_H