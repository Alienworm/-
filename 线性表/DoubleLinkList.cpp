#include <iostream>

using namespace std;

// 双链表存储结构
struct DNode {
    int data;
    struct DNode *prior, *next;
};

// 插入元素, 根据下标（index）插入元素
// 1, 2, 3, 4, 5, 6 在index为3的位置插入10后： 1, 2, 3, 10, 4, 5, 6
int listInsert(DNode *L, int index, int element) {
    // ！！！没有做越界判断
    DNode *tmpL = L->next;
    int count = 0;
    while (tmpL != NULL) {
        if (count == index) {
            // 初始化新节点
            DNode *newNode = new DNode();
            newNode->data = element;
            /*
                1. 将新节点的prior指向当前节点的前驱节点
                2. 将当前节点的前驱节点的next指向新节点
                3. 将新节点的next指向当前节点
                4. 将当前节点的prior指向新节点
            */
            newNode->prior = tmpL->prior;
            tmpL->prior->next = newNode;
            newNode->next = tmpL;
            tmpL->prior = newNode;
            return 1;
        }
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 删除元素，根据下标（index）删除元素
// 1, 2, 3, 4, 5, 6 删除下标为3的元素：1, 2, 3, 5, 6
int listDelete(DNode *L, int index) {
    // ！！！没有做越界判断
    DNode *tmpL = L->next;
    int count = 0;
    while (tmpL != NULL) {
        if (count == index) {
            DNode *tmpNode = tmpL;
            tmpL->next->prior = tmpL->prior;
            tmpL->prior->next = tmpL->next;
            delete tmpNode;
            return 1;
        }
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 输出链表
void printList(DNode *L) {
    DNode *tmpL = L;
    while (tmpL != NULL) {
        cout << tmpL->data << ", ";
        tmpL = tmpL->next;
    }
    cout << endl;
}

int main() {
    DNode *L, *newNode = new DNode();
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prior = L;
    L->next = newNode;
    L->prior = NULL;
    // 测试插入
    for (int i = 0; i < 10; i++)
        listInsert(L, i, i + 1);
    printList(L);
    // 测试删除
    listDelete(L, 5);
    printList(L);
}


