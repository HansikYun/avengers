#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int top = -1;

typedef int element; // 스택 원소의 자료형을 int로 정의
element stack[SIZE]; // 1차원 배열 스택 선언

//스택이 공백인지 확인하는 연산
int stackEmpty(void) {
    return top == -1;
}

//스택이 가득 찼는지 확인하는 연산
int stackFull(void) {
    return top == SIZE - 1;
}

//스택의 top에 원소를 삽입하는 연산
void push(element item) {
    if (stackFull()) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    stack[++top] = item; // top을 증가시킨 후 현재 top에 원소 삽입
}

//스택에서 top에서 원소를 삭제하는 연산
element pop(void) {
    if (stackEmpty()) { // 스택이 공백 상태인 경우
        printf("스택이 비어있습니다.\n");
        return 0;
    }
    return stack[top--]; // 현재 top의 원소를 삭제한 후 top 감소
}

//스택의 top 원소를 검색하는 연산
element peek() {
    if (stackEmpty()) { // 스택이 공백 상태인 경우
        printf("스택은 비어있습니다.\n");
        return 0;
    }
    return stack[top]; // 현재 top의 원소 확인
}

// 스택의 원소를 출력하는 연산
void printStack() {
    int i;
    printf("\n 스택 [ ");
    for (i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("] ");
}

int main(void) {
    element item;
    printf("\n** 순차 스택 연산 **\n");
    printStack();
    push(1);  printStack(); // 1 삽입
    push(2);  printStack(); // 2 삽입
    push(3);  printStack(); // 3 삽입

    item = peek();  printStack(); // 현재 top의 원소 출력
    printf("peek => %d\n", item);

    item = pop();  printStack(); // 삭제
    printf("\t pop  => %d\n", item);

    item = pop();  printStack(); // 삭제
    printf("\t pop  => %d\n", item);

    item = pop();  printStack(); // 삭제
    printf("\t pop  => %d\n", item);

    getchar();
    return 0;
}
