#include <stdio.h>
#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct {
	KeyType  key;
	char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode {  //二叉链表结点的定义
	TElemType  data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

typedef struct {
	int pos;
	TElemType data;
} DEF;
