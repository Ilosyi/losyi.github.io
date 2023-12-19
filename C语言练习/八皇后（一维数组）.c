#include <stdio.h>
#include<math.h>
#define N 8
int queen[N];
bool isSafe(int row, int col) {
    // 检查同一列是否有皇后
    for (int i = 0; i < row; i++) {
        if (queen[i] == col || abs(queen[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

int placeQueen(int row) {
    int count = 0;
    if (row == N) {
        // 所有皇后都已经放置，找到一个解法       
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            // 在当前位置放置皇后
            queen[row] = col;
            // 递归放置下一行的皇后
            count += placeQueen(row + 1);

        }
    }
    return count;
}
int main()
{
    int count = placeQueen(0);
    printf("%d", count);
    return 0;
}
