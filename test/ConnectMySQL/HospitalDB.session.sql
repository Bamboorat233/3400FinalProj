CREATE TABLE MedicalStaff (
    staffID INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    assignedHospital INT
);

--@block
CREATE TABLE Doctor (
    staffID INT PRIMARY KEY,
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID) ON DELETE CASCADE
);

--@block
CREATE TABLE Nurse (
    staffID INT PRIMARY KEY,
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID) ON DELETE CASCADE
);

--@block
CREATE TABLE HospitalBranch (
    branchID INT PRIMARY KEY
    -- 可以根据需要添加更多字段
);

--@block
CREATE TABLE Pharmacy (
    pharmacyID INT PRIMARY KEY,
    totalBill DOUBLE DEFAULT 0.0
);

--@block
CREATE TABLE Patient (
    patientID INT PRIMARY KEY,
    currentHospitalID INT,
    personalInfo TEXT,
    medicalCondition TEXT,
    attendingDoctorID INT,
    FOREIGN KEY (currentHospitalID) REFERENCES HospitalBranch(branchID),
    FOREIGN KEY (attendingDoctorID) REFERENCES Doctor(staffID)
);

--@block
-- 医生所属医院
ALTER TABLE MedicalStaff
ADD FOREIGN KEY (assignedHospital) REFERENCES HospitalBranch(branchID);

-- 医院账单（药房）
CREATE TABLE PharmacyBill (
    branchID INT,
    pharmacyID INT,
    amount DOUBLE,
    PRIMARY KEY (branchID, pharmacyID),
    FOREIGN KEY (branchID) REFERENCES HospitalBranch(branchID),
    FOREIGN KEY (pharmacyID) REFERENCES Pharmacy(pharmacyID)
);

--@block
CREATE TABLE DoctorPatient (
    doctorID INT,
    patientID INT,
    PRIMARY KEY (doctorID, patientID),
    FOREIGN KEY (doctorID) REFERENCES Doctor(staffID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
CREATE TABLE NursePatient (
    nurseID INT,
    patientID INT,
    PRIMARY KEY (nurseID, patientID),
    FOREIGN KEY (nurseID) REFERENCES Nurse(staffID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
CREATE TABLE Treatment (
    id INT AUTO_INCREMENT PRIMARY KEY,
    patientID INT,
    treatment TEXT,
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
CREATE TABLE ConsultingDoctor (
    patientID INT,
    doctorID INT,
    PRIMARY KEY (patientID, doctorID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID),
    FOREIGN KEY (doctorID) REFERENCES Doctor(staffID)
);


-- Inital data Nessary for the system to work properly
--@block
INSERT INTO HospitalBranch (branchID) VALUES
(1), (2), (3), (4), (5);
--@block
INSERT INTO Pharmacy (pharmacyID, totalBill) VALUES
(1, 0.0), (2, 0.0), (3, 0.0), (4, 0.0), (5, 0.0),
(6, 0.0), (7, 0.0), (8, 0.0), (9, 0.0), (10, 0.0),
(11, 0.0), (12, 0.0), (13, 0.0), (14, 0.0), (15, 0.0),
(16, 0.0), (17, 0.0), (18, 0.0), (19, 0.0), (20, 0.0);
