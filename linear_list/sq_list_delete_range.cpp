#include <iostream>
/*
 * 04. 题目要求：
 * 从顺序表中删除其值在给定值 s 和 t 之间（包含 s 和 t，要求 s < t）的所有元素。
 * 若 s 或 t 不合理，或顺序表为空，则显示出错信息并退出运行。
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

bool Del_Range(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t) {
        std::cout << "Error: invalid range or empty list.\n";
        return false;
    }

    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] < s || L.data[i] > t) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

int main() {
    SqList L = {{12, 3, 5, 6, 9, 10, 20}, 7};
    ElemType s = 5;
    ElemType t = 10;

    PrintList(L);
    if (Del_Range(L, s, t)) {
        std::cout << "Del Done\n";
        PrintList(L);
    } else {
        std::cout << "Del FAILED\n";
    }

    return 0;
}
