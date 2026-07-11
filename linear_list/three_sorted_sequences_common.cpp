#include <algorithm>
#include <iostream>

/*
 * 09. 题目要求：
 * 给定三个序列 A、B、C，长度均为 n，且均为无重复元素的递增序列。
 * 请设计一个时间上尽可能高效的算法，逐行输出同时存在于这三个序列中的所有元素。
 *
 * 例如：
 * 数组 A 为 {1, 2, 3}，数组 B 为 {2, 3, 4}，数组 C 为 {-1, 0, 2}，
 * 则输出 2。
 *
 * 要求：
 * 1. 给出算法的基本设计思想。
 * 2. 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3. 说明算法的时间复杂度和空间复杂度。
 */

void PrintCommonElements(int A[], int B[], int C[], int n) {
    // 初步思路：使用三个下标变量从小到大遍历数组。
    // 当三个下标指向的元素相等时，输出并向前推进指针，
    // 否则仅移动小于最大元素的下标变量，直到某个下标变量移出数组范围
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        if (A[i] == B[j] && B[j] == C[k]) {
            std::cout << A[i] << "\n";
            ++i;
            ++j;
            ++k;
        } else {
            int maxNum = std::max(A[i], std::max(B[j], C[k]));
            if (A[i] < maxNum) ++i;
            if (B[j] < maxNum) ++j;
            if (C[k] < maxNum) ++k;
        }
    }
    // 时间复杂度 O(n)，空间复杂度 O(1)。
}

int main() {
    int A[] = {1, 2, 3};
    int B[] = {2, 3, 4};
    int C[] = {-1, 0, 2};
    int n = 3;

    PrintCommonElements(A, B, C, n);

    return 0;
}
