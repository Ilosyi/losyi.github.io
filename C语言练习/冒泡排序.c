#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int temp;
    int lastSwap = n - 1; // 初始化最后一次交换位置为数组的最后一个元素
    for (int i = 0; i < n - 1; i++) {
        int newLastSwap = -1; // 初始化新的最后一次交换位置为-1，用于判断是否有交换发生
        for (int j = 0; j < lastSwap; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换arr[j]和arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                newLastSwap = j; // 更新最后一次交换的位置
            }
        }
        // 如果没有数据交换，说明整个数组已经有序，可以提前退出排序
        if (newLastSwap == -1) {
            break;
        }
        lastSwap = newLastSwap; // 更新最后一次交换的位置
    }
}
