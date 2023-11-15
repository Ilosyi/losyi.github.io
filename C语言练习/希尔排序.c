void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    
    // 根据希尔排序的步长序列，不断缩小间隔gap
    for (gap = len / 2; gap > 0; gap /= 2) {
        // 对每个间隔gap内的元素进行插入排序
        for (i = gap; i < len; i++) {
            temp = arr[i]; // 当前待比较的元素值
            // 在间隔为gap的元素序列中进行插入排序
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j]; // 向后移动元素
            }
            arr[j + gap] = temp; // 插入合适位置
        }
    }
}
