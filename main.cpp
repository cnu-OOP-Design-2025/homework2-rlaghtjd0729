#include <iostream>
#include <iomanip>
#include "homework2-1.h"
#include "homework2-2.h"
#include <cstdlib>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif


void createDirectory(const std::string& path) {
    #ifdef _WIN32
        _mkdir(path.c_str());
    #else
        mkdir(path.c_str(), 0777);
    #endif
}

using namespace std;

StudentStruct *students = nullptr;
int numOfStudent = 0;

void printBestStudentTest1()
{
    int bestMidtermId = findBestStudentInMidterm(students, numOfStudent);
    int bestFinalId = findBestStudentInFinal(students, numOfStudent);
    int bestTotalId = findBestStudent(students, numOfStudent);

    cout << "Best Midterm Student:\n";
    printStudentInfo(students, numOfStudent, bestMidtermId);

    cout << "Best Final Student:\n";
    printStudentInfo(students, numOfStudent, bestFinalId);

    cout << "Best Total Score Student:\n";
    printStudentInfo(students, numOfStudent, bestTotalId);
}

void printAverageTest1()
{
    float midtermAvg = getMidtermAverage(students, numOfStudent);
    float finalAvg = getFinalAverage(students, numOfStudent);
    float totalAvg = getTotalAverage(students, numOfStudent);

    cout << "# of Student: " << numOfStudent << endl;
    cout << fixed << setprecision(3);
    cout << "Midterm Average: " << midtermAvg << endl;
    cout << "Final Average: " << finalAvg << endl;
    cout << "Total Average: " << totalAvg << endl;
    cout.unsetf(ios::fixed);
}

void printStudentList(){
    for(int i = 0; i < numOfStudent; ++i){
        printStudentInfo(students, numOfStudent, (students+i)->id);
    }
}

void doNamespaceTest(){
    cout << "---------------------------" << endl;
    cout << "Namespace Test" << endl;

    // 정수형 계산기 테스트
    cout << "[IntCalc] 10 + 3 = " << IntCalc::add(10, 3) << endl;
    cout << "[IntCalc] 10 - 3 = " << IntCalc::subtract(10, 3) << endl;
    cout << "[IntCalc] 10 * 3 = " << IntCalc::multiply(10, 3) << endl;
    cout << "[IntCalc] 10 / 3 = " << IntCalc::divide(10, 3) << endl;
    cout << endl; // 가독성을 위해 추가

    // 실수형 계산기 테스트
    cout << fixed << setprecision(5);
    cout << "[FloatCalc] 10.5 + 3.2 = " << FloatCalc::add(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 - 3.2 = " << FloatCalc::subtract(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 * 3.2 = " << FloatCalc::multiply(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 / 3.2 = " << FloatCalc::divide(10.5f, 3.2f) << endl;
    cout.unsetf(ios::fixed);
    cout << endl; // 가독성을 위해 추가

    // 정수형 인자로 실수형 함수 호출 테스트
    cout << "[FloatCalc] 10 + 3 = " << FloatCalc::add(10, 3) << endl;
    cout << "[FloatCalc] 10 - 3 = " << FloatCalc::subtract(10, 3) << endl;
    cout << "[FloatCalc] 10 * 3 = " << FloatCalc::multiply(10, 3) << endl;
    cout << fixed << setprecision(5);
    cout << "[FloatCalc] 10 / 3 = " << FloatCalc::divide(10, 3) << endl;
    cout.unsetf(ios::fixed);
}

void doTest1(){
    cout << "---------------------------" << endl;
    cout << "Test 1" << endl;

    printBestStudentTest1();
    printAverageTest1();
    cout << "\n--- Student List ---" << endl;
    printStudentList();
}

void doTest2(){
    cout << "---------------------------" << endl;
    cout << "Test 2" << endl;

    StudentStruct charlie("Charlie", 1003, 70, 99.0);

    int idx = findStudentByStudentID(students, numOfStudent, charlie.id);
    if(idx >= 0)
        modifyRecord(students, numOfStudent, charlie);

    addStudent(students, &numOfStudent, "Ana", 1051, 88, 65);
    addStudent(students, &numOfStudent, "Suji", 1052, 90, 93);
    addStudent(students, &numOfStudent, "Zhang", 1053, 100, 40);

    cout << "\n--- Updated Info ---" << endl;
    printBestStudentTest1(); // Test 1 함수 재사용
    printAverageTest1(); // Test 1 함수 재사용
    cout << "\n--- Updated Student List ---" << endl;
    printStudentList();
}
void doTest3(){
    cout << "---------------------------" << endl;
    cout << "Test 3" << endl;

    deleteStudent(students, &numOfStudent, 1011);
    deleteStudent(students, &numOfStudent, 1029);

    cout << "\n--- After Deletion ---" << endl;
    printStudentList();
}

void doPointerTest(int select){
    const int MAX_STUDENTS = 100;
    students = new StudentStruct[MAX_STUDENTS];
    fillStudentRecord(students, &numOfStudent);

    if(students == nullptr)
        return;

    switch(select){
        case 2:
            doTest1();
            break;
        case 3:
            doTest2();
            break;
        case 4:
            doTest3();
            break;
        default:
            doTest1();
            doTest2();
            doTest3();
            break;
    }
    delete[] students;
    students = nullptr;
}
int main(int argc, char **argv) {
    
    createDirectory("Test");

    if(argc == 2){
        int select = atoi(argv[1]);
        if(select == 1){
            doNamespaceTest();
            return 0;
        } else if(select >= 2 && select <= 4){
            doPointerTest(select);
            return 0;
        }
    }
    doNamespaceTest();
    doPointerTest(0);

    return 0;
}
