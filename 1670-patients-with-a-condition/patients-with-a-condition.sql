SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%'      -- starts with DIAB1
   OR conditions LIKE '% DIAB1%'    -- has DIAB1 after a space
ORDER BY patient_id;
