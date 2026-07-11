#include <iostream>

/*
 * 题目要求：
 * 对于长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)，空间复杂度为 O(1) 的算法，
 * 该算法删除顺序表中所有值为 x 的数据元素。
 */

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void PrintList(SqList L) {
    std::cout << "Current list: ";
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.data[i] << ' ';
    }
    std::cout << "\nLength: " << L.length << '\n';
}

void Del_X(SqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            ++k;
        }
    }

    L.length = k;
}

int main() {
    SqList L = {{1, 2, 3, 2, 2, 2, 2}, 7};
    ElemType x = 2;

    PrintList(L);
    Del_X(L, x);
    PrintList(L);

    return 0;
}
