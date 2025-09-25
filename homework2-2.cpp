#include <iostream>
#include <string>
#include "homework2-2.h"

void populateStudentRecords(StudentStruct *allStudents, int *totalStudents) {
    addStudent(allStudents, totalStudents, "Alice", 1001, 90.7f, 91.0f);
    addStudent(allStudents, totalStudents, "Bob", 1002, 68.5f, 74.8f);
    addStudent(allStudents, totalStudents, "Charlie", 1003, 84.2f, 72.8f);
    addStudent(allStudents, totalStudents, "David", 1004, 63.7f, 77.6f);
    addStudent(allStudents, totalStudents, "Eva", 1005, 97.0f, 89.6f);
    addStudent(allStudents, totalStudents, "Frank", 1006, 83.0f, 62.2f);
    addStudent(allStudents, totalStudents, "Grace", 1007, 74.6f, 96.0f);
    addStudent(allStudents, totalStudents, "Hannah", 1008, 89.5f, 82.4f);
    addStudent(allStudents, totalStudents, "Ian", 1009, 98.4f, 91.3f);
    addStudent(allStudents, totalStudents, "Jane", 1010, 65.6f, 84.0f);
    addStudent(allStudents, totalStudents, "Kevin", 1011, 91.7f, 83.1f);
    addStudent(allStudents, totalStudents, "Laura", 1012, 78.2f, 61.7f);
    addStudent(allStudents, totalStudents, "Mike", 1013, 81.8f, 69.6f);
    addStudent(allStudents, totalStudents, "Nina", 1014, 83.6f, 69.6f);
    addStudent(allStudents, totalStudents, "Oscar", 1015, 63.9f, 98.7f);
    addStudent(allStudents, totalStudents, "Paula", 1016, 67.4f, 81.2f);
    addStudent(allStudents, totalStudents, "Quinn", 1017, 98.3f, 79.8f);
    addStudent(allStudents, totalStudents, "Rachel", 1018, 89.0f, 67.7f);
    addStudent(allStudents, totalStudents, "Steve", 1019, 89.4f, 96.6f);
    addStudent(allStudents, totalStudents, "Tina", 1020, 95.1f, 76.8f);
    addStudent(allStudents, totalStudents, "Uma", 1021, 91.7f, 77.2f);
    addStudent(allStudents, totalStudents, "Victor", 1022, 93.8f, 77.3f);
    addStudent(allStudents, totalStudents, "Wendy", 1023, 86.2f, 96.7f);
    addStudent(allStudents, totalStudents, "Xander", 1024, 90.2f, 73.3f);
    addStudent(allStudents, totalStudents, "Yvonne", 1025, 87.3f, 98.6f);
    addStudent(allStudents, totalStudents, "Zack", 1026, 85.8f, 70.8f);
    addStudent(allStudents, totalStudents, "Amber", 1027, 74.2f, 98.1f);
    addStudent(allStudents, totalStudents, "Brian", 1028, 79.2f, 69.2f);
    addStudent(allStudents, totalStudents, "Cathy", 1029, 86.1f, 82.2f);
    addStudent(allStudents, totalStudents, "Derek", 1030, 73.1f, 100.0f);
    addStudent(allStudents, totalStudents, "Elena", 1031, 62.1f, 84.8f);
    addStudent(allStudents, totalStudents, "Fred", 1032, 65.4f, 60.7f);
    addStudent(allStudents, totalStudents, "Gina", 1033, 97.7f, 91.7f);
    addStudent(allStudents, totalStudents, "Harry", 1034, 66.0f, 60.3f);
    addStudent(allStudents, totalStudents, "Isla", 1035, 89.7f, 62.7f);
    addStudent(allStudents, totalStudents, "Jack", 1036, 95.9f, 95.1f);
    addStudent(allStudents, totalStudents, "Kara", 1037, 91.4f, 86.9f);
    addStudent(allStudents, totalStudents, "Liam", 1038, 74.8f, 60.1f);
    addStudent(allStudents, totalStudents, "Mona", 1039, 77.8f, 76.8f);
    addStudent(allStudents, totalStudents, "Noah", 1040, 86.8f, 90.3f);
    addStudent(allStudents, totalStudents, "Olivia", 1041, 77.3f, 69.2f);
    addStudent(allStudents, totalStudents, "Peter", 1042, 97.4f, 75.3f);
    addStudent(allStudents, totalStudents, "Queen", 1043, 78.5f, 74.6f);
    addStudent(allStudents, totalStudents, "Ron", 1044, 96.0f, 78.3f);
    addStudent(allStudents, totalStudents, "Sara", 1045, 91.0f, 66.1f);
    addStudent(allStudents, totalStudents, "Tom", 1046, 90.7f, 61.4f);
    addStudent(allStudents, totalStudents, "Ursula", 1047, 66.1f, 68.0f);
    addStudent(allStudents, totalStudents, "Vince", 1048, 65.1f, 89.8f);
    addStudent(allStudents, totalStudents, "Will", 1049, 66.9f, 67.4f);
    addStudent(allStudents, totalStudents, "Zoe", 1050, 78.1f, 76.0f);
}

/* Return student ID */
int findTopMidtermStudent(StudentStruct* allStudents, int totalStudents) {
    float highestScore = 0.0f;
    int studentID = 0;

    for (int i = 0; i < totalStudents; i++) {
        if (allStudents[i].record.midterm > highestScore) {
            highestScore = allStudents[i].record.midterm;
            studentID = allStudents[i].id;
        }
    }
    return studentID;
}

/* Return student ID */
int findTopFinalStudent(StudentStruct* allStudents, int totalStudents) {
    float highestScore = 0.0f;
    int studentID = 0;
    for (int i = 0; i < totalStudents; i++) {
        if (allStudents[i].record.final > highestScore) {
            highestScore = allStudents[i].record.final;
            studentID = allStudents[i].id;
        }
    }
    return studentID;
}

/* Return student ID */
int findTopOverallStudent(StudentStruct* allStudents, int totalStudents) {
    float highestScore = 0.0f;
    int studentID = 0;
    for (int i = 0; i < totalStudents; i++) {
        float combinedScore = allStudents[i].record.final + allStudents[i].record.midterm;
        if (combinedScore > highestScore) {
            highestScore = combinedScore;
            studentID = allStudents[i].id;
        }
    }
    return studentID;
}

/* Return Index */
int findStudentById(StudentStruct* allStudents, int totalStudents, int studentId) {
    for (int i = 0; i < totalStudents; i++) {
        if (allStudents[i].id == studentId) {
            return i;
        }
    }
    return -1;
}

void updateRecord(StudentStruct* allStudents, int totalStudents, const StudentStruct& updatedStudent) {
    int index = findStudentById(allStudents, totalStudents, updatedStudent.id);
    if (index >= 0) {
        allStudents[index] = updatedStudent;
    }
}

void addStudent(StudentStruct* allStudents, int* totalStudents, const char* name, int id, float midterm, float final) {
    int index = findStudentById(allStudents, *totalStudents, id);
    if (index < 0) {
        allStudents[*totalStudents] = StudentStruct(name, id, midterm, final);
        ++(*totalStudents);
    }
}

void removeStudent(StudentStruct* allStudents, int* totalStudents, int studentId) {
    int index = findStudentById(allStudents, *totalStudents, studentId);
    if (index >= 0) {
        for (int i = index; i < *totalStudents - 1; i++) {
            allStudents[i] = allStudents[i + 1];
        }
        --(*totalStudents);
    }
}

float getMidtermAverage(StudentStruct* allStudents, int totalStudents) {
    float sum = 0.0f;
    for (int i = 0; i < totalStudents; i++) {
        sum += allStudents[i].record.midterm;
    }
    if (totalStudents == 0) return 0.0f;
    return sum / totalStudents;
}

float getFinalAverage(StudentStruct* allStudents, int totalStudents) {
    float sum = 0.0f;
    for (int i = 0; i < totalStudents; i++) {
        sum += allStudents[i].record.final;
    }
    if (totalStudents == 0) return 0.0f;
    return sum / totalStudents;
}

float getOverallAverage(StudentStruct* allStudents, int totalStudents) {
    float sum = 0.0f;
    for (int i = 0; i < totalStudents; i++) {
        sum += allStudents[i].record.midterm + allStudents[i].record.final;
    }
    if (totalStudents == 0) return 0.0f;
    return (sum / totalStudents) / 2.0f;
}

void printStudentInfo(StudentStruct* allStudents, int totalStudents, int studentId) {
    int index = findStudentById(allStudents, totalStudents, studentId);
    if (index >= 0) {
        std::cout << "Name: " << allStudents[index].name
                  << ", ID: " << allStudents[index].id << std::endl;
    }
}