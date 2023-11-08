#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
struct Student {
    char name[50];
    float score;
};

// 函数原型
void inputScores(struct Student** students, int n);
void sortScores(struct Student* students, int n);
void outputScores(struct Student* students, int n);
void searchScore(struct Student* students, int n, float score);

int main() {
    int choice;
    int n;
    float searchValue;
    struct Student* students = NULL;

    printf("请输入学生人数：");
    scanf_s("%d", &n);

    students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    while (choice != 5){
        printf("\n请选择操作：\n");
        printf("1. 成绩输入\n");
        printf("2. 成绩排序\n");
        printf("3. 成绩输出\n");
        printf("4. 成绩查找\n");
        printf("5. 退出\n");
        printf("选择: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            inputScores(&students, n);
            break;
        case 2:
            sortScores(students, n);
            break;
        case 3:
            outputScores(students, n);
            break;
        case 4:
            printf("请输入要查找的成绩: ");
           scanf_s("%f", &searchValue);
            searchScore(students, n, searchValue);
            break;
        case 5:
            printf("程序已退出。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } 

    // 释放动态分配的内存
    free(students);

    return 0;
}

// 输入学生姓名和成绩
void inputScores(struct Student** students, int n) {
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个学生的姓名: ", i + 1);
        scanf_s("%s", (*students)[i].name, 20);
            printf("请输入第%d个学生的C语言成绩: ", + 1);
        scanf_s("%f", &(*students)[i].score);
    }
};
// 按成绩排序
void sortScores(struct Student* students, int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].score < students[j + 1].score) {
                // 交换成绩和姓名
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
// 输出学生姓名和成绩
void outputScores(struct Student* students, int n) {
    printf("姓名\t\t成绩\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%.2f\n", students[i].name, students[i].score);
    }
}
// 使用二分查找查找成绩
void searchScore(struct Student* students, int n, float score) {
    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].score == score) {
            printf("找到成绩 %.2f 学生：%s\n", score, students[mid].name);
            found = 1;
            break;
        }
        else if (students[mid].score > score) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("成绩 %.2f 未找到。\n", score);
    }
}
