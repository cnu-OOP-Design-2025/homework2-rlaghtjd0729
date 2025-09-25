#include "homework2-1.h"

/* 정수 계산을 위한 네임스페이스와 함수 정의 */
namespace IntOperations {
    int add(int num1, int num2) {
        return num1 + num2;
    }

    int subtract(int num1, int num2) {
        return num1 - num2;
    }

    int multiply(int num1, int num2) {
        return num1 * num2;
    }

    int divide(int num1, int num2) {
        return num1 / num2;
    }
}

/* 실수 계산을 위한 네임스페이스와 함수 정의 */
namespace FloatOperations {
    float add(float num1, float num2) {
        return num1 + num2;
    }

    float subtract(float num1, float num2) {
        return num1 - num2;
    }

    float multiply(float num1, float num2) {
        return num1 * num2;
    }

    float divide(float num1, float num2) {
        return num1 / num2;
    }
}