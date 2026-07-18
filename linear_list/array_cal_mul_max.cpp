#include <iostream>

/*
 * 15. 题目要求：
 * 【2025 统考真题】
 * 有两个长度均为 n 的一维整型数组 A 和 res。
 * 对数组 A 中的每个元素 A[i]，
 * 计算 A[i] 与 A[j]（0 <= i <= j <= n-1）乘积的最大值，并将其保存到 res[i] 中。
 *
 * 例如：
 * 当 A[] = {1, 4, -9, 6} 时，得到 res[] = {6, 24, 81, 36}。
 *
 * 现给定数组 A，设计一个时间和空间上尽可能高效的算法 calMulMax，求 res 中各元素的值。
 * 函数原型为：
 * void calMulMax(int A[], int res[], int n)
 *
 * 要求：
 * 1. 给出算法的基本设计思想。
 * 2. 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3. 说明所设计算法的时间复杂度和空间复杂度。
 */

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
}

void calMulMax(int A[], int res[], int n) {
    /*
     * 基本设计思想：
     * 对于固定的 A[i]，需要在 A[i..n-1] 中选择一个 A[j] 使乘积最大。
     * 若 A[i] 为非负数，应选择后缀中的最大值相乘；
     * 若 A[i] 为负数，应选择后缀中的最小值相乘。
     * 因此从右向左扫描数组，同时维护当前位置右侧后缀的最大值和最小值。
     */
    if (n <= 0) {
        return;
    }

    int suffixMax = A[n - 1];
    int suffixMin = A[n - 1];

    for (int i = n - 1; i >= 0; --i) {
        if (A[i] > suffixMax) suffixMax = A[i];
        if (A[i] < suffixMin) suffixMin = A[i];

        if (A[i] >= 0) {
            res[i] = A[i] * suffixMax;
        } else {
            res[i] = A[i] * suffixMin;
        }
    }
}

int main() {
    int A[] = {1, 4, -9, 6};
    int res[] = {0, 0, 0, 0};
    int n = 4;

    calMulMax(A, res, n);
    PrintArray(res, n);

    return 0;
}
