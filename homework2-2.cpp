#include <iostream>
#include <string>
#include "homework2-2.h"
#include <cstring>

void fillStudentRecord(StudentStruct *students, int *numOfStudent) {
    addStudent(students, numOfStudent, "Alice", 1001, 90.7f, 91.0f);
    addStudent(students, numOfStudent, "Bob", 1002, 68.5f, 74.8f);
    addStudent(students, numOfStudent, "Charlie", 1003, 84.2f, 72.8f);
    addStudent(students, numOfStudent, "David", 1004, 63.7f, 77.6f);
    addStudent(students, numOfStudent, "Eva", 1005, 97.0f, 89.6f);
    addStudent(students, numOfStudent, "Frank", 1006, 83.0f, 62.2f);
    addStudent(students, numOfStudent, "Grace", 1007, 74.6f, 96.0f);
    addStudent(students, numOfStudent, "Hannah", 1008, 89.5f, 82.4f);
    addStudent(students, numOfStudent, "Ian", 1009, 98.4f, 91.3f);
    addStudent(students, numOfStudent, "Jane", 1010, 65.6f, 84.0f);
    addStudent(students, numOfStudent, "Kevin", 1011, 91.7f, 83.1f);
    addStudent(students, numOfStudent, "Laura", 1012, 78.2f, 61.7f);
    addStudent(students, numOfStudent, "Mike", 1013, 81.8f, 69.6f);
    addStudent(students, numOfStudent, "Nina", 1014, 83.6f, 69.6f);
    addStudent(students, numOfStudent, "Oscar", 1015, 63.9f, 98.7f);
    addStudent(students, numOfStudent, "Paula", 1016, 67.4f, 81.2f);
    addStudent(students, numOfStudent, "Quinn", 1017, 98.3f, 79.8f);
    addStudent(students, numOfStudent, "Rachel", 1018, 89.0f, 67.7f);
    addStudent(students, numOfStudent, "Steve", 1019, 89.4f, 96.6f);
    addStudent(students, numOfStudent, "Tina", 1020, 95.1f, 76.8f);
    addStudent(students, numOfStudent, "Uma", 1021, 91.7f, 77.2f);
    addStudent(students, numOfStudent, "Victor", 1022, 93.8f, 77.3f);
    addStudent(students, numOfStudent, "Wendy", 1023, 86.2f, 96.7f);
    addStudent(students, numOfStudent, "Xander", 1024, 90.2f, 73.3f);
    addStudent(students, numOfStudent, "Yvonne", 1025, 87.3f, 98.6f);
    addStudent(students, numOfStudent, "Zack", 1026, 85.8f, 70.8f);
    addStudent(students, numOfStudent, "Amber", 1027, 74.2f, 98.1f);
    addStudent(students, numOfStudent, "Brian", 1028, 79.2f, 69.2f);
    addStudent(students, numOfStudent, "Cathy", 1029, 86.1f, 82.2f);
    addStudent(students, numOfStudent, "Derek", 1030, 73.1f, 100.0f);
    addStudent(students, numOfStudent, "Elena", 1031, 62.1f, 84.8f);
    addStudent(students, numOfStudent, "Fred", 1032, 65.4f, 60.7f);
    addStudent(students, numOfStudent, "Gina", 1033, 97.7f, 91.7f);
    addStudent(students, numOfStudent, "Harry", 1034, 66.0f, 60.3f);
    addStudent(students, numOfStudent, "Isla", 1035, 89.7f, 62.7f);
    addStudent(students, numOfStudent, "Jack", 1036, 95.9f, 95.1f);
    addStudent(students, numOfStudent, "Kara", 1037, 91.4f, 86.9f);
    addStudent(students, numOfStudent, "Liam", 1038, 74.8f, 60.1f);
    addStudent(students, numOfStudent, "Mona", 1039, 77.8f, 76.8f);
    addStudent(students, numOfStudent, "Noah", 1040, 86.8f, 90.3f);
    addStudent(students, numOfStudent, "Olivia", 1041, 77.3f, 69.2f);
    addStudent(students, numOfStudent, "Peter", 1042, 97.4f, 75.3f);
    addStudent(students, numOfStudent, "Queen", 1043, 78.5f, 74.6f);
    addStudent(students, numOfStudent, "Ron", 1044, 96.0f, 78.3f);
    addStudent(students, numOfStudent, "Sara", 1045, 91.0f, 66.1f);
    addStudent(students, numOfStudent, "Tom", 1046, 90.7f, 61.4f);
    addStudent(students, numOfStudent, "Ursula", 1047, 66.1f, 68.0f);
    addStudent(students, numOfStudent, "Vince", 1048, 65.1f, 89.8f);
    addStudent(students, numOfStudent, "Will", 1049, 66.9f, 67.4f);
    addStudent(students, numOfStudent, "Zoe", 1050, 78.1f, 76.0f);
}

/* Return student ID */
int findBestStudentInMidterm(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return -1;
    float maxMidterm = -1.0f;
    int bestStudentId = -1;
    for (int i = 0; i < numOfStudent; ++i) {
        if ((*(students + i)).record.midterm > maxMidterm) {
            maxMidterm = (students + i)->record.midterm;
            bestStudentId = (students + i)->id;
        }
    }
    return bestStudentId;
}

/* Return student ID */
int findBestStudentInFinal(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return -1;
    float maxFinal = -1.0f;
    int bestStudentId = -1;
    for (int i = 0; i < numOfStudent; ++i) {
        if (students[i].record.final > maxFinal) {
            maxFinal = students[i].record.final;
            bestStudentId = students[i].id;
        }
    }
    return bestStudentId;
}

/* Return student ID */
int findBestStudent(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return -1;
    float maxTotalScore = -1.0f;
    int bestStudentId = -1;
    for (int i = 0; i < numOfStudent; ++i) {
        float currentTotal = students[i].record.midterm + students[i].record.final;
        if (currentTotal > maxTotalScore) {
            maxTotalScore = currentTotal;
            bestStudentId = students[i].id;
        }
    }
    return bestStudentId;
}

/* Return Index */
int findStudentByStudentID(StudentStruct* students, int numOfStudent, int id) {
    for (int i = 0; i < numOfStudent; ++i) {
        if ((*(students + i)).id == id) {
            return i;
        }
    }
    return -1;
}

void modifyRecord(StudentStruct *students, int numOfStudent, const StudentStruct& student) {
    int idx = findStudentByStudentID(students, numOfStudent, student.id);
    if (idx >= 0) {
        students[idx].record.midterm = student.record.midterm;
        students[idx].record.final = student.record.final;
    }
}

void addStudent(StudentStruct *students, int *numOfStudent, const char* name, int id, float midterm, float final) {
    int idx = findStudentByStudentID(students, *numOfStudent, id);
    if (idx < 0) {
        strcpy(students[*numOfStudent].name, name);
        students[*numOfStudent].id = id;
        students[*numOfStudent].record.midterm = midterm;
        students[*numOfStudent].record.final = final;
        (*numOfStudent)++;
    }
}

void deleteStudent(StudentStruct* students, int *numOfStudent, int id) {
    int idx = findStudentByStudentID(students, *numOfStudent, id);
    if (idx >= 0) {
        for (int i = idx; i < *numOfStudent - 1; ++i) {
            students[i] = students[i + 1];
        }
        (*numOfStudent)--;
    }
}

float getMidtermAverage(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < numOfStudent; ++i) {
        sum += students[i].record.midterm;
    }
    return sum / numOfStudent;
}

float getFinalAverage(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < numOfStudent; ++i) {
        sum += students[i].record.final;
    }
    return sum / numOfStudent;
}

float getTotalAverage(StudentStruct* students, int numOfStudent) {
    if (numOfStudent <= 0) return 0.0f;
    float sumTotal = 0.0f;
    for (int i = 0; i < numOfStudent; ++i) {
        sumTotal += students[i].record.midterm + students[i].record.final;
    }
    return (sumTotal / numOfStudent) / 2.0f;
}

void printStudentInfo(StudentStruct* students, int numOfStudent, int id) {
    int idx = findStudentByStudentID(students, numOfStudent, id);
    if (idx >= 0) {
        std::cout << "Name: " << (students + idx)->name 
                  << ", ID: " << students[idx].id << std::endl;
    }
}