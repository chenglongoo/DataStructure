#include <iostream>
/*
 * 07. 题目要求：
 * 已知在一维数组 A[m+n] 中依次存放两个线性表：
 * (a1, a2, a3, ..., am) 和 (b1, b2, b3, ..., bn)。
 * 编写一个函数，将数组中两个顺序表的位置互换，
 * 即将 (b1, b2, b3, ..., bn) 放在 (a1, a2, a3, ..., am) 的前面。
 */

#define MaxSize 50

typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int length;
} SqList;

void PrintList(SqList L) {
    std::cout << "Current List: ";
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << " ";
    }
    std::cout << "\nCurrent Length:" << L.length << std::endl;
}

void ReverseList(SqList &L, int left, int right) {
    while (left < right) {
        int tmp = L.data[left];
        L.data[left++] = L.data[right];
        L.data[right--] = tmp;
    }
}

bool Exchange(SqList &L, int m, int n) {
    if (m <= 0 || n <= 0 || m + n > L.length) {
        std::cout << "Error: invalid m or n.\n";
        return false;
    }

    ReverseList(L, 0, m + n - 1);
    ReverseList(L, 0, n - 1);
    ReverseList(L, n, m + n - 1);
    return true;
}

int main() {
    SqList L = {{1, 2, 3, 4, 5, 8, 9, 10}, 8};
    int m = 5, n = 3;

    PrintList(L);
    Exchange(L, m, n);
    PrintList(L);

    return 0;
}
