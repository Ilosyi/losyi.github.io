#define _CRT_SECURE_NO_WARNINGS
#include"fun.h"
void main(void) {
	ALGraph G[10];
	int k = 0; 
	int i = 0;
	VertexType V[21];
	KeyType VR[100][2];
	char FileName[] = "C:\\Users\\muke\\Desktop\\图读写测试.txt";
	int op = 1;
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Graphs based on adjacency tables \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateCraph       11. DFSTraverse\n");
		printf("    	  2. DestroyGraph      12. BFSTraverse\n");
		printf("    	  3. LocateVex         13. VerticesSetLessThanK\n");
		printf("    	  4. PutVex            14. ShortestPathLength\n");
		printf("    	  5. FirstAdjVex       15. ConnectedComponentsNums\n");
		printf("    	  6. NextAdjVex        16. SaveGraph\n");
		printf("    	  7. InsertVex         17. LoadGraph\n");
		printf("    	  8. DeleteVex         18. ChangeGrapth\n");
		printf("    	  9. InsertArc         19. PrintTable\n");
		printf("    	  10. DeleteArc        20. ListTrabverse\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			i = 0;
			do {
				scanf("%d%s", &V[i].key, V[i].others);
			} while (V[i++].key != -1);
			i = 0;
			do {
				scanf("%d%d", &VR[i][0], &VR[i][1]);
			} while (VR[i++][0] != -1);
			if (CreateCraph(G[k], V, VR) == ERROR) printf("输入数据错，无法创建");
			else printf("创建成功!");
			getchar(); getchar();
			break;
		case 2:
			printf("\n----DestroyList功能待实现！\n");
			getchar(); getchar();
			break;
		case 3:
			printf("\n----ClearList功能待实现！\n");
			getchar(); getchar();
			break;
		case 4:
			printf("\n----ListEmpty功能待实现！\n");
			getchar(); getchar();
			break;
		case 5:
			printf("\n----ListLength功能待实现！\n");
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

			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()
