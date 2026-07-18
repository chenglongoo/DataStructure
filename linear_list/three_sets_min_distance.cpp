#include <climits>
#include <iostream>

/*
 * 14. 题目要求：
 * 【2020 统考真题】
 * 定义三元组 (a, b, c)（a、b、c 均为整数）的距离：
 * D = |a-b| + |b-c| + |c-a|。
 *
 * 给定 3 个非空整数集合 S1、S2 和 S3，按升序分别存储在 3 个数组中。
 * 请设计一个尽可能高效的算法，计算并输出所有可能的三元组
 * (a, b, c)（a 属于 S1，b 属于 S2，c 属于 S3）中的最小距离。
 *
 * 例如：
 * S1 = {-1, 0, 9}，S2 = {-25, -10, 10, 11}，S3 = {2, 9, 17, 30, 41}，
 * 则最小距离为 2，相应的三元组为 (9, 10, 9)。
 *
 * 要求：
 * 1. 给出算法的基本设计思想。
 * 2. 根据设计思想，采用 C 语言或 C++ 语言描述算法，关键之处给出注释。
 * 3. 说明所设计算法的时间复杂度和空间复杂度。
 */

int abs_(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

bool IsMin(int a, int b, int c) {
    if (a <= b && a <= c) return true;
    return false;
}

int MinDistance(int A[], int n1, int B[], int n2, int C[], int n3) {
    /*
     * 基本设计思想：
     * 使用三个指针分别指向三个升序数组的当前元素。
     * 每次计算当前三元组的距离并更新最小值，
     * 然后移动当前三个元素中最小值所在数组的指针，
     * 直到任一数组扫描结束。
     */

    int i = 0, j = 0, k = 0;
    int D_min = INT_MAX, D;
    while (i < n1 && j < n2 && k < n3) {
        D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
        if (D < D_min) D_min = D;
        if (D_min == 0) return 0;

        if (IsMin(A[i], B[j], C[k])) ++i;
        else if (IsMin(B[j], A[i], C[k])) ++j;
        else ++k;
    }
    return D_min;
}

int main() {
    int S1[] = {-1, 0, 9};
    int S2[] = {-25, -10, 10, 11};
    int S3[] = {2, 9, 17, 30, 41};
    int n1 = 3, n2 = 4, n3 = 5;

    std::cout << "Minimum distance: " << MinDistance(S1, n1, S2, n2, S3, n3) << '\n';

    return 0;
}
