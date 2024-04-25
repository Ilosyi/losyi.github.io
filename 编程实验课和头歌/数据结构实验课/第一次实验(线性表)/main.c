#define _CRT_SECURE_NO_WARNINGS
#include "fun.h"
void main(void) {
	SqList L;  int op = 1;
	L.elem = NULL;
	ElemType e1, e2, e3, e5, e6, e7; int f, i, m, j,k;
	char filename[80];
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       7. LocateElem\n");
		printf("    	  2. DestroyList    8. PriorElem\n");
		printf("    	  3. ClearList      9. NextElem \n");
		printf("    	  4. ListEmpty      10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem        12. ListTrabverse\n");
		printf("          13.MaxSubArray    14. SubArrayNum\n");
		printf("          15.SortList       16. SaveList\n");
		printf("    	  17.LoadList       18. InitValue\n");
		printf("           0.Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (InitList(L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyList(L) == OK) printf("线性表销毁成功！\n");
			else printf("线性表销毁失败！\n");
			getchar(); getchar();
			break;
		case 3:
			if (ClearList(L) == OK) printf("线性表已清除！\n");
			else printf("线性表清除失败！\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE) printf("线性表为空！\n");
			else if (ListEmpty(L) == FALSE) printf("线性表不为空!\n");
			else printf("线性表不存在!\n");
			getchar(); getchar();
			break;
		case 5:
			if (ListLength(L) == INFEASIBLE) printf("线性表不存在!\n");
			else printf("线性表的长度为%d\n", ListLength(L));
			getchar(); getchar();
			break;
		case 6:
			printf("请输入需要获取的元素位置:\n");
			scanf("%d", &i);
			if (GetElem(L, i, e1) == INFEASIBLE) printf("线性表不存在!\n");
			else if (GetElem(L, i, e1) == ERROR) printf("输入的位置不在线性表有效范围内!\n");
			else printf("该位置的元素值为%d，已保存在e1中\n", e1);
			getchar(); getchar();
			break;
		case 7:
			printf("请输入要查找的元素e:\n");
			scanf("%d", &e2);
			if (LocateElem(L, e2) == INFEASIBLE) printf("线性表不存在!\n");
			else if (LocateElem(L, e2) == ERROR)  printf("该数据不存在!\n");
			else printf("该元素在线性表中第一次出现的位置序号为%d\n", LocateElem(L, e2));
			getchar(); getchar();
			break;
		case 8:
			ElemType e4; ElemType pre;
			printf("请输入需要查找前驱的元素:\n");
			scanf("%d", &e4);
			if (PriorElem(L, e4, pre) == INFEASIBLE) printf("线性表不存在!\n");
			else if (PriorElem(L, e4, pre) == ERROR) printf("前驱不存在!\n");
			else printf("%d的前驱值为%d,已保存在pre中\n", e4, pre);
			getchar(); getchar();
			break;
		case 9:
			ElemType next;
			printf("请输入需要查找后驱的元素e:\n");
			scanf("%d", &e5);
			if (NextElem(L, e5, next) == INFEASIBLE) printf("线性表不存在!\n");
			else if (NextElem(L, e5, next) == ERROR) printf("后驱不存在!\n");
			else printf("%d的后驱值为%d,已保存在next中\n", e5, next);
			getchar(); getchar();
			break;
		case 10:
			printf("请输入要插入的位置（线性表第几个元素之前）和元素值\n");
			scanf("%d%d", &i, &e6);
			f = ListInsert(L, i, e6);
			if (f == INFEASIBLE) printf("线性表不存在!\n");
			else if (f == ERROR) printf("插入位置不正确!\n");
			else printf("插入成功!\n");

			getchar(); getchar();
			break;
		case 11:
			printf("请输入要删除的元素位置(第几个元素)\n");
			scanf("%d", &i);
			m = ListDelete(L, i, e7);
			if (m == INFEASIBLE) printf("线性表不存在!\n");
			else if (m == ERROR) printf("删除位置不正确!\n");
			else printf("删除成功!删除的数据%d已保存在e7中\n", e7);
			getchar(); getchar();
			break;
		case 12:
			j = ListTraverse(L);
			if (j == INFEASIBLE) printf("线性表不存在！\n");
			if (j == OK && !L.length) printf("空线性表\n");
			getchar(); getchar();
			break;
		case 13:
			if (!L.elem) printf("线性表不存在!\n");
			else if (L.length == 0) printf("线性表为空!\n");
			else printf("最大连续子数组和为%d\n", MaxSubArray(L));
			getchar(); getchar();
			break;
		case 14:
			if (!L.elem) printf("线性表不存在!\n");
			else if (L.length == 0) printf("线性表为空!\n");
			else
			{
				printf("请输入目标和K的值:\n");
				scanf("%d", &k);
				printf("和为%d的连续子数组数目为%d\n",k, SubArrayNum(L,k));
			}
			getchar(); getchar();
			break;
		case 15:
			j = SortList(L);
			if (j==INFEASIBLE) printf("线性表不存在!\n");
			else if (j==ERROR) printf("线性表为空!\n");
			else printf("排序已完成!\n");
			getchar(); getchar();
			break;
		case 16:
			strcpy(filename, "C:\\Users\\HUAWEI\\Documents\\线性表写入测试.txt");
			if (SaveList(L, filename) == OK) printf("数据写入完成!\n");
			else printf("写入失败!\n");
			getchar(); getchar();
			break;
		case 17:
			strcpy(filename, "C:\\Users\\HUAWEI\\Documents\\线性表写入测试.txt");
			if (LoadList(L, filename) == OK) printf("数据读入完成!\n");
			else printf("读入失败!\n");
			getchar(); getchar();
			break;
		case 18:
			if (!L.elem) printf("线性表不存在!\n");
			else {
				printf("请连续输入要存入线性表的值(以0结束输入):\n");
				scanf("%d", &e3);
				while (e3 != 0)
				{
					ListInsert(L, L.length + 1, e3);
					scanf("%d", &e3);
				}
				printf("数据已存入线性表!\n");
			}
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}

