#include <iostream>

#define MaxSize 50

using namespace std;

// 顺序栈存储结构
typedef struct {
    int *data; // 动态数组
    int top; // 顺序栈栈顶位置
} SqStack;

// 初始化顺序表
void initStack(SqStack &S) {
    S.data = new int[MaxSize];
    S.top = -1;
}

// 获取第一个元素
int top(SqStack &S) {
    return S.data[S.top];
}

// 入栈
bool push(SqStack &S, int element) {
    if (S.top == MaxSize) return false;
    S.data[++S.top] = element;
    return true;
}

// 判空
bool empty(SqStack &S) {
    return S.top == -1;
}

// 出栈
int pop(SqStack &S) {
    if (empty(S)) return -1;
    return S.data[S.top--];
}

int main() {
    SqStack S;
    initStack(S);
    for(int i = 0 ; i < 10; i++)
        push(S, i);
    for (int i = 0; i < 10; i++)
        cout << pop(S) << ", ";
    cout << endl;
}