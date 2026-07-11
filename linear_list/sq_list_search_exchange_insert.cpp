#include <iostream>
/*
 * 08. 题目要求：
 * 线性表 (a1, a2, a3, ..., an) 中的元素递增有序且按顺序存储于计算机内。
 * 要求设计一个算法，完成用最少时间在表中查找数值为 x 的元素。
 * 若找到，则将其与后继元素位置相交换；
 * 若找不到，则将其插入表中并使表中元素仍然递增有序。
 */

#define MaxSize 50

typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int length;
} SqList;

void PrintList(SqList L) {
    std::cout << "Current List: ";
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.data[i] << " ";
    }
    std::cout << "\nCurrent Length: " << L.length << std::endl;
}

bool SearchExchangeInsert(SqList &L, ElementType x) {
    int low = 0, high = L.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L.data[mid] == x) {
            if (mid != L.length - 1) {
                ElementType temp = L.data[mid];
                L.data[mid] = L.data[mid + 1];
                L.data[mid + 1] = temp;
            }
            return true;
        } else if (L.data[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (L.length >= MaxSize) {
        std::cout << "Error: list is full.\n";
        return false;
    }

    for (int i = L.length; i > low; --i) {
        L.data[i] = L.data[i - 1];
    }
    L.data[low] = x;
    ++L.length;
    return true;
}

int main() {
    SqList L =  {{1, 3, 4, 5, 6, 7, 8, 9}, 8};
    PrintList(L);
    SearchExchangeInsert(L, 10);
    PrintList(L);
    return 0;
}
