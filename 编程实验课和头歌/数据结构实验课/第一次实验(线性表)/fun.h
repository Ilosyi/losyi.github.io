#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct {  //顺序表（顺序结构）的定义
    ElemType* elem;
    int length;
    int listsize;
}SqList;
typedef struct {  //线性表的集合类型定义
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
}LISTS;
LISTS Lists;      //线性表集合的定义Lists

status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList& L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L, int i, ElemType& e);
int LocateElem(SqList L, ElemType e);
status PriorElem(SqList L, ElemType e, ElemType& pre);
status NextElem(SqList L, ElemType e, ElemType& next);
status ListInsert(SqList& L, int i, ElemType e);
status ListTraverse(SqList L);
status ListDelete(SqList& L, int i, ElemType& e);
status  SaveList(SqList L, char FileName[]);
status  LoadList(SqList& L, char FileName[]);
status AddList(LISTS& Lists, char ListName[]);
status RemoveList(LISTS& Lists, char ListName[]);
int LocateList(LISTS Lists, char ListName[]);

status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{

    /********** Begin *********/
    if (!L.elem)//如果线性表为空
    {
        L.elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else {
        return INFEASIBLE;
    }
    /********** End **********/
}
status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        return OK;
    }
    else return INFEASIBLE;

    /********** End **********/
}
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem)
    {
        L.length = 0;
        return OK;
    }
    else return INFEASIBLE;
    /********** End **********/
}
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem)
    {
        return INFEASIBLE;
    }
    else {
        if (L.length == 0) return TRUE;
        else return FALSE;
    }

    /********** End **********/
}
status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else return L.length;

    /********** End **********/
}
status GetElem(SqList L, int i, ElemType& e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {
        if (i<1 || i>L.length) return ERROR;
        else {
            e = L.elem[i - 1];
            return OK;
        }
    }

    /********** End **********/
}
int LocateElem(SqList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else
    {
        int flag = -1;
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
            {
                flag = i; break;
            }
        }
        if (flag == -1) return ERROR;
        else return flag + 1;
    }

    /********** End **********/
}
status PriorElem(SqList L, ElemType e, ElemType& pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {
        for (int i = 1; i < L.length; i++)
        {
            if (L.elem[i] == e) {
                pre = L.elem[i - 1];
                return OK;
            }
        }
        return ERROR;
    }
    /********** End **********/
}
status NextElem(SqList L, ElemType e, ElemType& next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {
        for (int i = 0; i < L.length - 1; i++)
        {
            if (L.elem[i] == e) {
                next = L.elem[i + 1];
                return OK;
            }
        }
        return ERROR;
    }
    /********** End **********/
}
status ListInsert(SqList& L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {

        if (i<1 || i>L.length + 1) return ERROR;

        else {

            L.length++;
            if (L.length >= L.listsize) //记得扩容！
            {
                L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType*) * (L.listsize + LISTINCREMENT));
            }
            for (int j = L.length - 1; j >= i; j--)
            {
                L.elem[j] = L.elem[j - 1];
            }
            L.elem[i - 1] = e;
            return OK;
        }
    }

    /********** End **********/
}
status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {

        for (int i = 0; i < L.length; i++)
        {
            printf("%d", L.elem[i]);
            if (i != L.length - 1) printf(" ");
        }
        return OK;
    }

    /********** End **********/
}
status ListDelete(SqList& L, int i, ElemType& e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L.elem) return INFEASIBLE;
    else {
        if (i <= 0 || i >= L.length + 1) return ERROR;
        else {
            if (i == L.length)
            {
                e = L.elem[i - 1];
                L.length--;
                return OK;
            }
            else
            {
                e = L.elem[i - 1];
                for (int j = i - 1; j <= L.length - 2; j++)
                {
                    L.elem[j] = L.elem[j + 1];
                }
                L.length--;
                return OK;
            }
        }
    }

    /********** End **********/
}

status  SaveList(SqList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    FILE* fp;
    fp = fopen(FileName, "w");
    if (!L.elem) return INFEASIBLE;
    else {
        for (int i = 0; i < L.length; i++) {
            fprintf(fp, "%d", L.elem[i]);
            if (i != L.length - 1) {
                fprintf(fp, " ");
            }
        }
        fclose(fp);
        return OK;

        /********** End **********/
    }
}
status  LoadList(SqList& L, char FileName[])
{        // 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。

         // 请在这里补充代码，完成本关任务
         /********** Begin *********/
    FILE* fp;
    fp = fopen(FileName, "r");
    if (L.elem) return INFEASIBLE;
    else
    {
        L.elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;

        ElemType data;
        while (fscanf(fp, "%d", &data) != EOF) {
            if (L.length >= L.listsize) {
                L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType) * (
                    L.listsize + LISTINCREMENT));
                L.listsize += LISTINCREMENT;
            }
            L.elem[L.length++] = data;
        }

        fclose(fp);
        return OK;
        /********** End **********/
    }
}
status AddList(LISTS& Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据由后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (Lists.length > 9) return ERROR;
    else {
        strcpy(Lists.elem[Lists.length].name, ListName);
        Lists.elem[Lists.length].L.elem = NULL;
        InitList(Lists.elem[Lists.length].L);
        Lists.length++;
        return OK;
    }
    /********** End **********/
}
status RemoveList(LISTS& Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = -1;
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            flag = i;
            break;
        }
    }
    if (flag != -1)
    {
        for (int i = flag; i < Lists.length - 1; i++) {
            Lists.elem[i] = Lists.elem[i + 1];
        }
        Lists.length--;
        return OK;
    }
    else return ERROR;
        /********** End **********/
}
int LocateList(LISTS Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = -1;
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            flag = i + 1;
            break;
        }
    }
    if (flag == -1) return 0;
    else return flag;
    /********** End **********/
}
