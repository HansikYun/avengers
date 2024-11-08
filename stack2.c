#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc을 사용하기 위해 포함

typedef int element;        // 스택 원소(element)의 자료형을 int로 정의 

typedef struct stackNode {  // 스택의 노드를 구조체로 정의
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;             // 스택의 top 노드를 지정하기 위해 포인터 top 선언

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
    return top == NULL;  // 공백 여부를 간결하게 반환
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

    if (temp == NULL) {  // 메모리 할당 실패 처리
        printf("메모리 할당 실패\n");
        return;
    }

    temp->data = item;
    temp->link = top;    // 삽입 노드를 top의 위에 연결
    top = temp;          // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
    element item;
    stackNode* temp = top;

    if (isStackEmpty()) {  // 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {               // 스택이 공백 리스트가 아닌 경우
        item = temp->data;
        top = temp->link;  // top 위치를 삭제 노드 아래로 이동
        free(temp);        // 삭제된 노드의 메모리 반환
        return item;       // 삭제된 원소 반환
    }
}

// 스택의 top 원소를 검색하는 연산
element peek() {
    if (isStackEmpty()) {  // 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {               // 스택이 공백 리스트가 아닌 경우
        return top->data;  // 현재 top의 원소 반환
    }
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] \n");  // 줄 바꿈 추가
}

int main(void) {
    element item;
    top = NULL;
    printf("\n** 연결 스택 연산 **\n");
    printStack();

    push(11);    printStack();     // 11 삽입
    push(22);    printStack();     // 22 삽입
    push(33);    printStack();     // 33 삽입

    item = peek(); printStack();    // 현재 top의 원소 출력
    printf("peek => %d\n", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d\n", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d\n", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d\n", item);

    getchar();
    return 0;
}
