#include <iostream>

/*
 * 10. 题目要求：
 * 【2010 统考真题】
 * 设将 n（n > 1）个整数存放到一维数组 R 中。
 * 设计一个在时间和空间两方面都尽可能高效的算法。
 * 将 R 中保存的序列循环左移 p（0 < p < n）个位置，
 * 即将 R 中的数据由 (X0, X1, ..., Xn-1)
 * 变换为 (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。
 *
 * 要求：
 * 1. 给出算法的基本设计思想。
 * 2. 根据设计思想，采用 C 或 C++ 或 Java 语言描述算法，关键之处给出注释。
 * 3. 说明所设计算法的时间复杂度和空间复杂度。
 */

void PrintArray(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << R[i] << ' ';
    }
    std::cout << '\n';
}

void ReverseArray(int R[], int from, int to) {
    for (int i = 0;i < (to - from + 1) / 2; ++i) {
        const int temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

void LeftRotate(int R[], int n, int p) {
    if (n <= 1 || p <= 0 || p >= n) {
        return;
    }

    /*
     * 基本设计思想：
     * 将数组分为前 p 个元素和后 n-p 个元素两部分，记为 AB。
     * 循环左移 p 位后应变为 BA。
     * 先分别逆置 A 和 B，得到 reverse(A) reverse(B)，
     * 再整体逆置，即可得到 BA。
     */
    ReverseArray(R, 0, p - 1);
    ReverseArray(R, p, n - 1);
    ReverseArray(R, 0, n - 1);
}

int main() {
    int R[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int p = 3;

    PrintArray(R, n);
    LeftRotate(R, n, p);
    PrintArray(R, n);

    return 0;
}
