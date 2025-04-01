-- Create table for all medical staff (both doctors and nurses)
CREATE TABLE MedicalStaff (
    staffID INT PRIMARY KEY,                  -- Unique ID for staff
    name VARCHAR(100) NOT NULL,               -- Staff name
    assignedHospital INT                      -- Hospital branch ID (foreign key added later)
);

--@block
-- Create table for doctors (extends MedicalStaff)
CREATE TABLE Doctor (
    staffID INT PRIMARY KEY,                  -- Inherits from MedicalStaff
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID) ON DELETE CASCADE
);

--@block
-- Create table for nurses (extends MedicalStaff)
CREATE TABLE Nurse (
    staffID INT PRIMARY KEY,                  -- Inherits from MedicalStaff
    FOREIGN KEY (staffID) REFERENCES MedicalStaff(staffID) ON DELETE CASCADE
);

--@block
-- Create table for hospital branches
CREATE TABLE HospitalBranch (
    branchID INT PRIMARY KEY                  -- Unique ID for each hospital branch
    -- More fields can be added as needed
);

--@block
-- Create table for pharmacy records
CREATE TABLE Pharmacy (
    pharmacyID INT PRIMARY KEY,               -- Unique ID for each pharmacy
    totalBill DOUBLE DEFAULT 0.0              -- Total billing amount
);

--@block
-- Create table for patients
CREATE TABLE Patient (
    patientID INT PRIMARY KEY,                -- Unique patient ID
    currentHospitalID INT,                    -- Currently assigned hospital
    personalInfo TEXT,                        -- Patient's personal information
    medicalCondition TEXT,                    -- Current medical condition
    attendingDoctorID INT,                    -- Assigned primary doctor
    FOREIGN KEY (currentHospitalID) REFERENCES HospitalBranch(branchID),
    FOREIGN KEY (attendingDoctorID) REFERENCES Doctor(staffID)
);

--@block
-- Link assignedHospital in MedicalStaff to HospitalBranch
ALTER TABLE MedicalStaff
ADD FOREIGN KEY (assignedHospital) REFERENCES HospitalBranch(branchID);

--@block
-- Table to track medication bills paid by hospital branches to pharmacies
CREATE TABLE PharmacyBill (
    branchID INT,                             -- Hospital branch making purchase
    pharmacyID INT,                           -- Pharmacy from which medication was purchased
    amount DOUBLE,                            -- Purchase amount
    PRIMARY KEY (branchID, pharmacyID),
    FOREIGN KEY (branchID) REFERENCES HospitalBranch(branchID),
    FOREIGN KEY (pharmacyID) REFERENCES Pharmacy(pharmacyID)
);

--@block
-- Many-to-many relationship between doctors and their assigned patients
CREATE TABLE DoctorPatient (
    doctorID INT,
    patientID INT,
    PRIMARY KEY (doctorID, patientID),
    FOREIGN KEY (doctorID) REFERENCES Doctor(staffID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
-- Many-to-many relationship between nurses and their assigned patients
CREATE TABLE NursePatient (
    nurseID INT,
    patientID INT,
    PRIMARY KEY (nurseID, patientID),
    FOREIGN KEY (nurseID) REFERENCES Nurse(staffID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
-- Table to store treatments for each patient
CREATE TABLE Treatment (
    id INT AUTO_INCREMENT PRIMARY KEY,
    patientID INT,
    treatment TEXT,                           -- Description of the treatment
    FOREIGN KEY (patientID) REFERENCES Patient(patientID)
);

--@block
-- Table to store consulting doctors for each patient
CREATE TABLE ConsultingDoctor (
    patientID INT,
    doctorID INT,
    PRIMARY KEY (patientID, doctorID),
    FOREIGN KEY (patientID) REFERENCES Patient(patientID),
    FOREIGN KEY (doctorID) REFERENCES Doctor(staffID)
);

--@block
-- Insert initial 5 hospital branches (required by system)
INSERT INTO HospitalBranch (branchID) VALUES
(1), (2), (3), (4), (5);

--@block
-- Insert initial 20 pharmacies with zero billing
INSERT INTO Pharmacy (pharmacyID, totalBill) VALUES
(1, 0.0), (2, 0.0), (3, 0.0), (4, 0.0), (5, 0.0),
(6, 0.0), (7, 0.0), (8, 0.0), (9, 0.0), (10, 0.0),
(11, 0.0), (12, 0.0), (13, 0.0), (14, 0.0), (15, 0.0),
(16, 0.0), (17, 0.0), (18, 0.0), (19, 0.0), (20, 0.0);
