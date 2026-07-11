#include <iostream>
/*
 * 06. 题目要求：
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
    ElemType data[MaxSize];
    int length;
} SqList;

void PrintSqList(SqList L) {
    std::cout << "Current List: ";
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << " ";
    }
    std::cout << "\nCurrent Length: " << L.length << std::endl;
}

SqList Merge(SqList L1, SqList L2) {
    SqList res_L;
    res_L.length = 0;

    if (L1.length + L2.length > MaxSize) {
        std::cout << "Error: result list overflow.\n";
        return res_L;
    }

    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] <= L2.data[j]) {
            res_L.data[k++] = L1.data[i++];
        } else {
            res_L.data[k++] = L2.data[j++];
        }
    }

    while (i < L1.length) {
        res_L.data[k++] = L1.data[i++];
    }

    while (j < L2.length) {
        res_L.data[k++] = L2.data[j++];
    }
    res_L.length = k;
    return res_L;
}

int main() {
    SqList L1 = {{1, 3, 4, 5, 6}, 5}, L2 = {{1, 2, 4, 5, 8}, 5};
    SqList merged_list = Merge(L1, L2);
    PrintSqList(merged_list);

    return 0;
}

