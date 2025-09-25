#include <iostream>
#include <cstdlib>
#include "homework2-1.h"
#include "homework2-2.h"
using namespace std;

StudentStruct *studentData = nullptr;
int studentCount = 0;

void printTopStudents() {
    int topMidtermId = findTopMidtermStudent(studentData, studentCount);
    int topFinalId = findTopFinalStudent(studentData, studentCount);
    int topTotalId = findTopOverallStudent(studentData, studentCount);

    cout << "Best Midterm Student:\n";
    printStudentInfo(studentData, studentCount, topMidtermId);

    cout << "Best Final Student:\n";
    printStudentInfo(studentData, studentCount, topFinalId);

    cout << "Best Total Score Student:\n";
    printStudentInfo(studentData, studentCount, topTotalId);
}

void printAverages() {
    float midtermAvg = getMidtermAverage(studentData, studentCount);
    float finalAvg = getFinalAverage(studentData, studentCount);
    float totalAvg = getOverallAverage(studentData, studentCount);

    cout << "# of Student: " << studentCount << endl;
    cout << "Midterm Average: " << midtermAvg << endl;
    cout << "Final Average: " << finalAvg << endl;
    cout << "Overall Average: " << totalAvg << endl;
}

void printAllStudentInfo() {
    for (int id = 1000; id < 1100; ++id) {
        printStudentInfo(studentData, studentCount, id);
    }
}

void runNamespaceTest() {
    cout << "---------------------------" << endl;
    cout << "Namespace Test" << endl;

    // Integer Calculator Test
    cout << "[IntOperations] 10 + 3 = " << IntOperations::add(10, 3) << endl;
    cout << "[IntOperations] 10 - 3 = " << IntOperations::subtract(10, 3) << endl;
    cout << "[IntOperations] 10 * 3 = " << IntOperations::multiply(10, 3) << endl;
    cout << "[IntOperations] 10 / 3 = " << IntOperations::divide(10, 3) << endl;

    cout << "[IntOperations] 10.5 + 3.2 = " << IntOperations::add(10.5, 3.2) << endl;
    cout << "[IntOperations] 10.5 - 3.2 = " << IntOperations::subtract(10.5, 3.2) << endl;
    cout << "[IntOperations] 10.5 * 3.2 = " << IntOperations::multiply(10.5, 3.2) << endl;
    cout << "[IntOperations] 10.5 / 3.2 = " << IntOperations::divide(10.5, 3.2) << endl;


    // Float Calculator Test
    cout << "[FloatOperations] 10 + 3 = " << FloatOperations::add(10, 3) << endl;
    cout << "[FloatOperations] 10 - 3 = " << FloatOperations::subtract(10, 3) << endl;
    cout << "[FloatOperations] 10 * 3 = " << FloatOperations::multiply(10, 3) << endl;
    cout << "[FloatOperations] 10 / 3 = " << FloatOperations::divide(10, 3) << endl;

    cout << "[FloatOperations] 10.5 + 3.2 = " << FloatOperations::add(10.5f, 3.2f) << endl;
    cout << "[FloatOperations] 10.5 - 3.2 = " << FloatOperations::subtract(10.5f, 3.2f) << endl;
    cout << "[FloatOperations] 10.5 * 3.2 = " << FloatOperations::multiply(10.5f, 3.2f) << endl;
    cout << "[FloatOperations] 10.5 / 3.2 = " << FloatOperations::divide(10.5f, 3.2f) << endl;
}

void testScenario1() {
    cout << "---------------------------" << endl;
    cout << "Test 1" << endl;

    printTopStudents();
    printAverages();
    printAllStudentInfo();
}

void testScenario2() {
    cout << "---------------------------" << endl;
    cout << "Test 2" << endl;

    StudentStruct modifiedCharlie("Charlie", 1003, 70.0f, 99.0f);

    int index = findStudentById(studentData, studentCount, modifiedCharlie.id);
    if (index >= 0) {
        updateRecord(studentData, studentCount, modifiedCharlie);
    }

    addStudent(studentData, &studentCount, "Ana", 1051, 88.0f, 65.0f);
    addStudent(studentData, &studentCount, "Suji", 1052, 90.0f, 93.0f);
    addStudent(studentData, &studentCount, "Zhang", 1053, 100.0f, 40.0f);

    printTopStudents();
    printAverages();
    printAllStudentInfo();
}

void testScenario3() {
    cout << "---------------------------" << endl;
    cout << "Test 3" << endl;

    studentCount = 0;
    populateStudentRecords(studentData, &studentCount);

    removeStudent(studentData, &studentCount, 1011);
    removeStudent(studentData, &studentCount, 1029);

    printAllStudentInfo();
}

void runPointerTest(int scenario) {
    const int MAX_STUDENTS = 100;
    studentData = new StudentStruct[MAX_STUDENTS];

    populateStudentRecords(studentData, &studentCount);

    if (studentData == nullptr) {
        return;
    }

    switch (scenario) {
        case 2:
            testScenario1();
            break;
        case 3:
            testScenario2();
            break;
        case 4:
            testScenario3();
            break;
        default:
            testScenario1();
            testScenario2();
            testScenario3();
            break;
    }
    delete[] studentData;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int select = atoi(argv[1]);
        switch (select) {
            case 1:
                runNamespaceTest();
                return 0;
            case 2:
            case 3:
            case 4:
                runPointerTest(select);
                return 0;
        }
    }
    runNamespaceTest();
    runPointerTest(0);

    return 0;
}