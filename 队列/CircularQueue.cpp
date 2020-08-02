#include <iostream>

#define MaxSize 10

using namespace std;

typedef struct {
    int *data;
    int front, rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q) {
    Q.data = new int[MaxSize];
    Q.front = Q.rear = 0;
}

// 判断队列为空
bool empty(SqQueue &Q) {
    return Q.front == Q.rear;
}

// 入队
bool enQueue(SqQueue &Q, int element) {
    if ((Q.rear + 1 % MaxSize) == Q.front) return false;
    Q.data[Q.rear] = element;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
int deQueue(SqQueue &Q) {
    if (empty(Q)) return -1;
    int result = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return result;
}

// 获取队头元素
int getHead(SqQueue Q) {
    if (empty(Q)) return -1;
    return Q.data[Q.front];
}

// 输出队列
void printQueue(SqQueue Q) {
    for (int i = Q.front; i < Q.rear + 1; i++)
        cout << Q.data[i] << ", ";
    cout << endl;
}

int main() {
    SqQueue Q;
    // 测试初始化队列
    InitQueue(Q);
    // 测试入队
    for (int i = 0; i < 5; i++)
        enQueue(Q, i);
    printQueue(Q);
    // 测试出队和获取队头元素
    cout << deQueue(Q) << endl;
    cout << deQueue(Q) << endl;
    cout << getHead(Q) << endl;
    printQueue(Q);
}