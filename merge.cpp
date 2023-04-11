//
// Created by 15399 on 2023/4/11.
//
// 合并有序数组
#include "Function.h"
void merge() {
    // 读入两个数组
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    int b[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    int c[n + m];
    int i = 0, j = 0, k = 0;

    // 合并
    while (i < n && j < m) {
        if (a[i] < b[j]) { // 从小到大排序
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    // 将a的剩余的元素放入数组
    while (i < n) {
        c[k++] = a[i++];
    }
    // 将b的剩余的元素放入数组
    while (j < m) {
        c[k++] = b[j++];
    }
    for (int i = 0; i < n + m; ++i) {
        std::cout << c[i] << std::endl;
    }
}