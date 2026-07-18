#include <cstring>
#include <iostream>
#include <cstdlib>

/*
 * 13. 题目要求：
 * 【2018 统考真题】
 * 给定一个含 n（n >= 1）个整数的数组，请设计一个在时间上尽可能高效的算法，
 * 找出数组中未出现的最小正整数。
 *
 * 例如：
 * 数组 {-5, 3, 2, 3} 中未出现的最小正整数是 1；
 * 数组 {1, 2, 3} 中未出现的最小正整数是 4。
 *
 * 要求：
 * 1. 给出算法的基本设计思想。
 * 2. 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3. 说明你所设计算法的时间复杂度和空间复杂度。
 */

int FirstMissingPositive(int A[], int n) {
    /*
     * 要求在时间上尽可能高效，因此采用空间换时间的办法。分配一个用于标记的数组B[n]，用来记录A中是否出现了1~n个整数，
     * B[0]对应正整数1，B[n-1]对应正整数n，初始化B中全部为0。A中含有n个整数，因此可能返回值是1~n+1，当A中n个数恰好为1~n时返回n+1.
     * 当数组A中出现了小于或等于0或大于n的值时，会导致1~n中出现空余位置，返回结果必然在1~n中，因此对于A中出现了小于或等于0或大于n的值，可以不采取任何操作。
     */
    int i, *B;
    B = (int *) malloc (sizeof(int) * n);
    if (B == nullptr) {
        return -1;
    }
    memset(B, 0, sizeof(int) * n);
    for (i=0; i<n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            B[A[i] - 1] = 1;
        }
    }
    for (i=0; i<n; ++i) {
        if (B[i]==0) {
            break;
        }
    }
    free(B);
    return i + 1;
}

int main() {
    int A[] = {-5, 3, 2, 3};
    int n = 4;

    std::cout << "First missing positive: " << FirstMissingPositive(A, n) << '\n';

    return 0;
}
