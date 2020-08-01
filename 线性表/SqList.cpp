#include <iostream>

#define MaxSize 50

using namespace std;

// 顺序表存储结构
typedef struct {
    int *data; // 动态数组
    int length; // 顺序表当前长度
} SqList;

// 初始化顺序表
void initList(SqList &L) {
    L.data = new int[MaxSize];
    L.length = 0;
}

// 获取当前顺序表长度
int length(SqList &L) {
    return L.length;
}

// 判空操作
bool empty(SqList &L) {
    return length(L) == 0;
}

// 查找元素，返回该元素下标
int locateElement(SqList &L, int element) {
    for (int i = 0; i < length(L); i++)
        if (L.data[i] == element) return i;
    return -1; // 元素不存在
}

// 通过下标（index）查找元素
int getElement(SqList &L, int index) {
    if (empty(L) || index >= length(L)) 
        return -1; // 查找失败
    return L.data[index];
}

// 插入元素, 根据下标（index）插入元素
// 1, 2, 3, 4, 5, 6 在index为3的位置插入10后： 1, 2, 3, 10, 4, 5, 6
int listInsert(SqList &L, int index, int element) {
    if (length(L) >= MaxSize) return -1; // 超出最大长度
    if (index < 0 || index > MaxSize) return -1; // 下标位置越界
    L.length += 1;
    for (int i = length(L); i > index; i--) // index之后的元素向后移动1位
        L.data[i] = L.data[i - 1];
    L.data[index] = element; // 插入元素
    return 1;
}

// 删除元素，根据下标（index）删除元素
// 1, 2, 3, 4, 5, 6 删除下标为3的元素：1, 2, 3, 5, 6 element = 4
int listDelete(SqList &L, int index, int &element) {
    if (empty(L)) return -1; // 顺序表中没有元素
    if (index < 0 || index > MaxSize) return -1; // 下标位置越界
    element = L.data[index];
    for (int i = index; i < length(L) - 1; i++)
        L.data[i] = L.data[i + 1];
    L.length -= 1;
    return 1;
}

// 输出顺序表
void printList(SqList L) {
    for (int i = 0; i < length(L); i++)
        cout << L.data[i] << ", ";
    cout << endl;
}

// 销毁顺序表
void destoryList(SqList &L) {
    delete [] L.data;
    L.length = 0;
}

int main() {
    SqList L;
    // 测试初始化顺序表
    initList(L);
    // 测试插入数据
    for (int i = 0; i < 10; i++)
        listInsert(L, i, i);
    // 测试输出顺序表
    printList(L);
    // 测试length，locateElement， getElement
    cout << "length: " << length(L) << endl;
    cout << "locateElement 3: " << locateElement(L, 3) << endl;;
    cout << "getElement 3: " << getElement(L, 3) << endl;;
    // 测试删除元素
    int element = -1;
    listDelete(L, 4, element);
    cout << "listDelete: " << element << endl;
    printList(L);
    // 测试销毁操作
    destoryList(L);
}