#include <iostream>
/*
 * 05. 题目要求：
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 */

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void PrintList(SqList L) {
    std::cout << "Current List: ";
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << ' ';
    }
    std::cout << "\nList Length: " << L.length << "\n";
}

void Del_Duplicates(SqList &L) {
    if (L.length == 0) return;

    int k = 1;
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] != L.data[k - 1]) {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}


int main() {
    SqList L = {{1, 2, 2, 2, 2, 3, 4, 5}, 8};
    PrintList(L);
    std::cout << "Start to delete duplicate elements. \n";
    Del_Duplicates(L);
    PrintList(L);

    return 0;
}
