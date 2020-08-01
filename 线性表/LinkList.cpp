#include <iostream>

using namespace std;

// 单链表存储结构
struct LNode {
    int data;
    struct LNode *next;
};

// 头插法建立单链表
LNode *listHeadInsert() {
    // 初始化头节点
    LNode *L = new LNode();
    L->next = NULL;
    // 插入元素
    for (int i = 0; i < 10; i++) {
        // 初始化新节点
        LNode *newNode = new LNode();
        newNode->data = i;
        // 将新节点的next指向L的next，更新L的next为新节点
        newNode->next = L->next;
        L->next = newNode;
    }
    return L;
}

// 尾插法建立单链表
LNode *listTailInsert() {
    // 初始化头节点
    LNode *L, *tailNode = new LNode();
    L->next = NULL;
    tailNode = L; // tailNode代表当前最后一个节点位置
    for (int i = 0; i < 10; i++) {
        // 初始化新节点
        LNode *newNode = new LNode();
        newNode->data = i;
        // 设置新节点的next为NULL，将tailNode的next指向新节点，将新节点设置为tailNode
        newNode->next = NULL;
        tailNode->next = newNode;
        tailNode = newNode;
    }
    return L;
}

// 获取链表长度
int length(LNode *L) {
    LNode *tmpL = L->next;
    int count = 0;
    while (tmpL != NULL) {
        count += 1;
        tmpL = tmpL->next;
    }
    return count;
}

// 通过下标（index）查找元素
int getElement(LNode *L, int index) {
    if (L->next == NULL || length(L) < index) return -1;
    LNode *tmpL = L->next;
    int count = 0;
    while (tmpL != NULL) {
        if (count == index) return tmpL->data;
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 查找元素，返回该元素下标
int locateElement(LNode *L, int element) {
    if (length(L) == 0) return -1;
    LNode *tmpL = L->next;
    int count = 0;
    while (tmpL != NULL) {
        if (tmpL->data == element) return count;
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 插入元素, 根据下标（index）插入元素
// 1, 2, 3, 4, 5, 6 在index为3的位置插入10后： 1, 2, 3, 10, 4, 5, 6
int listInsert(LNode *L, int index, int element) {
    if (length(L) < index) return -1;
    LNode *tmpL = L->next;
    int count = 0;
    while (tmpL->next != NULL) {
        if (count + 1 == index) {
            // 初始化新节点
            LNode *newNode = new LNode();
            newNode->data = element;
            // 将新节点指向第index个元素，将第index-1个的元素的next指向新节点
            newNode->next = tmpL->next;
            tmpL->next = newNode;
            return 1;
        }
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 删除元素，根据下标（index）删除元素
// 1, 2, 3, 4, 5, 6 删除下标为3的元素：1, 2, 3, 5, 6
int listDelete(LNode *L, int index) {
    if (length(L) < index) return -1;
    LNode *tmpL = L->next;
    int count = 0;
    while (tmpL->next != NULL) {
        if (count + 1 == index) {
            LNode *tmpNode = tmpL->next;
            // 将第index-1个节点的next指向要删除节点的下一个节点，然后释放要删除节点的空间
            tmpL->next = tmpL->next->next;
            delete tmpNode;
            return 1;
        }
        count += 1;
        tmpL = tmpL->next;
    }
    return -1;
}

// 输出链表
void printList(LNode *L) {
    LNode *tmpL = L->next;
    while (tmpL != NULL) {
        cout << tmpL->data << ", ";
        tmpL = tmpL->next;
    }
    cout << endl;
}

int main() {
    // 测试头插法
    LNode *headInsertList = listHeadInsert();
    printList(headInsertList);
    // 测试尾插法
    LNode *tailInsertList = listTailInsert();
    printList(tailInsertList);
    // 测试length，getElement，locateElement
    cout << "length: " << length(tailInsertList) << endl;
    cout << "getElement: " << getElement(tailInsertList, 2) << endl;
    cout << "locateElement: " << locateElement(tailInsertList, 5) << endl;
    // 测试插入
    listInsert(tailInsertList, 4, 200);
    printList(tailInsertList);
    // 测试删除
    listDelete(tailInsertList, 2);
    printList(tailInsertList);
}