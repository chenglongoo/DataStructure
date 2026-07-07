#include <iostream>

/*
 * 题目要求：
 * 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补。
 * 若顺序表为空，则显示出错信息并退出运行。
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

bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0) {
        return false;
    }

    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }

    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

int main() {
    SqList L = {{12, 5, 20, 3, 9}, 5};
    ElemType value;

    PrintList(L);

    if (Del_Min(L, value)) {
        std::cout << "Deleted minimum value: " << value << '\n';
        PrintList(L);
    } else {
        std::cout << "Error: empty sequential list.\n";
    }

    return 0;
}
