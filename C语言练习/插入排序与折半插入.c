void insertion_sort(int arr[], int len){
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}

void insertSort(int array[], int n) {
    int temp;
    for (int i = 1; i < n; i++) {
        int low = 0;    //初始都在0位置
        int hight = i - 1;
        temp = array[i];   //待排序元素

while (hight >= low) {
            int mid = (low + hight) / 2;
            if (array[mid] > temp) {    //若小于中间值，则在左边范围
                hight = mid - 1;
            }
            else {                      //反之在右边
                low = mid + 1;
            }
        }

for (int j = i - 1; j > hight; j--) {   //从待插入元素的前一位置到已排序部分的末尾
            array[j + 1] = array[j];
        }

array[hight + 1] = temp;
}
}
