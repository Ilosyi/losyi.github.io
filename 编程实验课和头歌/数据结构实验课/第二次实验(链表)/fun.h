#define _CRT_SECURE_NO_WARNINGS
#include"def.h"
status InitList(LinkList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if (L != NULL) return INFEASIBLE;
    else {
        L = ((LinkList)malloc(sizeof(LNode)));
        L->next = NULL;
        L->data = 0;
        return OK;
    }
}
status DestroyList(LinkList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if (L != NULL)
    {
        LinkList p = L;
        LinkList q = NULL;
        while (p)
        {
            q = p->next;
            free(p);
            p = q;
        }
        L = NULL;
        return OK;
    }
    else return INFEASIBLE;
}
status ClearList(LinkList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if (L != NULL)
    {
        LinkList p = L->next;
        LinkList q = NULL;
        while (p)
        {
            q = p->next;
            free(p);
            p = q;
        }
        L->next = NULL;
        return OK;
    }
    else return INFEASIBLE;
}
status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        if (L->next == NULL) return TRUE;
        else return FALSE;
    }
    else return INFEASIBLE;
}
int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if (L != NULL)
    {
        int length = 0;
        LinkList p = L->next;
        while (p)
        {
            length++;
            p = p->next;
        }
        return length;
    }
    else return INFEASIBLE;
}
status GetElem(LinkList L, int i, ElemType& e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        if (i < 1) return ERROR;
        int count = 0;
        LinkList p = L;
        while (p && count < i)
        {
            p = p->next;
            count++;
        }
        if (count != i || !p) return ERROR;
        else {
            e = p->data;
            return OK;
        }
    }
    else return INFEASIBLE;
}
status LocateElem(LinkList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if (L != NULL)
    {
        int i = 0;
        LinkList p = L;
        while (p)
        {
            p = p->next;
            i++;
            while (p)
            {
                p = p->next;
                i++;
                if (p && p->data == e) return i;
            }
            return ERROR;
        }
    }
    else return INFEASIBLE;
}
status PriorElem(LinkList L, ElemType e, ElemType& pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        LinkList p = L, q=p->next;
        while (q)
        {
            q = p->next;
            if (q && p != L && q->data == e)
            {
                pre = p->data;
                return OK;
            }
            p = q;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}
status NextElem(LinkList L, ElemType e, ElemType& next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        LinkList p = L->next, q;
        while (p)
        {
            q = p->next;
            if (q && p->data == e)
            {
                next = q->data;
                return OK;
            }
            p = q;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}
status ListInsert(LinkList& L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        int count = 1;
        LinkList p = L, q = L->next;
        while (p)
        {
            if (i < 1) break;
            if (count == i)
            {
                LinkList NewNode = (LinkList)malloc(sizeof(LNode));;
                p->next = NewNode;
                NewNode->next = q;
                NewNode->data = e;
                return OK;
            }
            p = q;
            if (p == NULL) break;
            q = q->next;
            count++;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}
status ListDelete(LinkList& L, int i, ElemType& e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        int count = 1;
        LinkList p = L, q = L->next;
        while (q)
        {
            if (i < 1) break;
            if (count == i)
            {
                p->next = q->next;
                e = q->data;
                free(q);
                return OK;
            }
            p = q;
            q = q->next;
            count++;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}
status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if (L != NULL)
    {
        LinkList p = L->next;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        return OK;
    }
    else return INFEASIBLE;
}
status SaveList(LinkList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if (L != NULL)
    {
        FILE* fp = fopen(FileName, "w");
        LinkList p = L->next;
        while (p)
        {
            fprintf(fp, "%d ", p->data);
            p = p->next;
        }
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}
status LoadList(LinkList& L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if (L == NULL)
    {
        L = ((LinkList)malloc(sizeof(LNode)));
        L->next = NULL;
        FILE* fp = fopen(FileName, "r");
        LinkList p = L;
        ElemType e;
        while (fscanf(fp, "%d", &e) != EOF)
        {
            LinkList newNode = (LinkList)malloc(sizeof(LNode));
            newNode->data = e;
            newNode->next = p->next;
            p->next = newNode;
            p = p->next; // 移动到新节点
        }
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}
