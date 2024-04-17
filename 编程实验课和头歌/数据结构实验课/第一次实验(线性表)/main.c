#define _CRT_SECURE_NO_WARNINGS
#include "fun.h"
void main(void) {
	SqList L;  int op = 1;
	L.elem = NULL;
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       7. LocateElem\n");
	printf("    	  2. DestroyList	8. PriorElem\n");
	printf("    	  3. ClearList      9. NextElem \n");
	printf("    	  4. ListEmpty      10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem        12. ListTrabverse\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	while (op) {

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
			if(ClearList(L) == OK) printf("线性表已清除！\n");
			else printf("线性表清除失败！\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE) printf("线性表为空！\n");
			else if (ListEmpty(L) == FALSE) printf("线性表不为空!\n");
			else printf("线性表不存在!");
			getchar(); getchar();
			break;
		case 5:
			if (ListLength(L) == INFEASIBLE) printf("线性表不存在");
			else printf("线性表的长度为%d", ListLength(L));
			getchar(); getchar();
			break;
		case 6:
			printf("\n----GetElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 7:
			printf("\n----LocateElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 8:
			printf("\n----PriorElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 9:
			printf("\n----NextElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 10:
			printf("\n----ListInsert功能待实现！\n");
			getchar(); getchar();
			break;
		case 11:
			printf("\n----ListDelete功能待实现！\n");
			getchar(); getchar();
			break;
		case 12:  
			if (!ListTraverse(L)) printf("线性表是空表！\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}
