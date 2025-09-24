#include "homework2-1.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "homework2-2.h"
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif

// 함수는 그대로 두었습니다.
// 정수형 계산기
namespace IntCalc {
    int add(int a, int b) {
        return a + b;
    }
    int subtract(int a, int b) {
        return a - b;
    }
    int multiply(int a, int b) {
        return a * b;
    }
    int divide(int a, int b) {
        if (b == 0) {
            return 0;
        }
        return a / b;
    }
}

// 실수형 계산기
namespace FloatCalc {
    float add(float a, float b) {
        return a + b;
    }
    float subtract(float a, float b) {
        return a - b;
    }
    float multiply(float a, float b) {
        return a * b;
    }
    float divide(float a, float b) {
        if (b == 0.0f) {
            return 0.0f;
        }
        return a / b;
    }
}
