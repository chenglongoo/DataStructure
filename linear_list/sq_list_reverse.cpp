#include <iostream>

/*
 * 题目要求：
 * 设计一个高效算法，将顺序表 L 的所有元素逆置。
 * 要求算法的空间复杂度为 O(1)。
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

void Reverse(SqList &L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

int main() {
    SqList L = {{1, 2, 3, 4, 5, 6}, 6};

    PrintList(L);
    Reverse(L);
    PrintList(L);

    return 0;
}
