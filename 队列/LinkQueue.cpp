#include <iostream>

using namespace std;

// 链式队列存储结构
struct LinkNode {
    int data;
    struct LinkNode *next;
};

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

// 初始化队列
void initQueue(LinkQueue &Q) {
    Q.rear = new LinkNode();
    Q.front = Q.rear;
    Q.front->next = NULL;
}

// 入队
bool enQueue(LinkQueue &Q, int element) {
    LinkNode *newNode = new LinkNode();
    newNode->data = element;
    newNode->next = NULL;
    Q.rear->next = newNode;
    Q.rear = newNode;
    return true;
}

// 出队
int deQueue(LinkQueue &Q) {
    if (Q.front == Q.rear) return -1;
    LinkNode *tmpNode = Q.front->next;
    int result = tmpNode->data;
    Q.front->next = Q.front->next->next;
    if (tmpNode == Q.rear) Q.front = Q.rear;
    delete tmpNode;
    return result;
}

// 获取队头元素
int getHead(LinkQueue Q) {
    return Q.front->next->data;
}

// 输出队列
void printQueue(LinkQueue Q) {
    LinkNode *tmpFront = Q.front->next;
    while (tmpFront != NULL) {
        cout << tmpFront->data << ", ";
        tmpFront = tmpFront->next;
    }
    cout << endl;
}

int main() {
    LinkQueue Q;
    // 测试初始化队列
    initQueue(Q);
    // 测试入队
    for (int i = 0; i < 10; i++)
        enQueue(Q, i);
    printQueue(Q);
    // 测试出队和获取队头元素
    cout << deQueue(Q) << endl;
    cout << deQueue(Q) << endl;
    cout << getHead(Q) << endl;
    printQueue(Q);
}

