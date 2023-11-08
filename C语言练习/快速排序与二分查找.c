#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include<stdlib.h>
int partition(int a[], int left, int right)
{
	int t = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= t)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right && a[left] <= t)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = t;
	return left;
}
void QuickSort(int a[], int left, int right)
{
	int split;
	if (left < right)
	{
		
		split = partition(a, left, right);
		QuickSort(a, left, split - 1);
		QuickSort(a, split + 1, right);
	}
}
int binarySearch(int a[], int x, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == x) {
			return 1;  // 找到了 x
		}
		else if (a[mid] < x) {
			low = mid + 1;  // x 只可能在右半边
		}
		else {
			high = mid - 1;  // x 只可能在左半边
		}
	}
	return 0;  // 未找到 x
}

int isBelong(int a[], int x, int low, int high) {
	if (low > high) {
		return 0;  // 如果 low 大于 high，说明范围为空，直接返回 0
	}
	return binarySearch(a, x, low, high);
}
