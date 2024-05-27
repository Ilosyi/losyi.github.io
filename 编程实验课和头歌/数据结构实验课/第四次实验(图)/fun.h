#include"def.h"
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    int flag = 1;
    // 检查V和VR的正确性
    int n = 0;
    int m = 0;
    for (int i = 0; V[i].key != -1; i++)
    {
        n++;
    }
    for (int i = 0; VR[i][0] != -1; i++)
    {
        m++;
    }
    if (n > MAX_VERTEX_NUM) return ERROR;//顶点数目是否正确

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (V[i].key == V[j].key) {
                return ERROR; // 存在重复的顶点信息
            }
        }
    }

    // 初始化图的顶点数和边数
    G.vexnum = n;
    G.arcnum = m;

    // 根据V中的顶点信息构建图的顶点集合
    for (int i = 0; i < n; ++i) {
        G.vertices[i].data = V[i];   //头节点数组
        G.vertices[i].firstarc = NULL; // 初始化邻接表的边指针为空
    }

    // 根据VR中的边信息构建图的边集合
    for (int k = 0; k < m; ++k) {
        int v1 = -1, v2 = -1;
        // 在顶点集合中查找VR中的顶点
        for (int i = 0; i < n; ++i) {
            if (V[i].key == VR[k][0]) {
                v1 = i;
            }
            if (V[i].key == VR[k][1]) {
                v2 = i;
            }
        }
        // 如果顶点不存在，返回错误
        if (v1 == -1 || v2 == -1) {
            return ERROR;
        }
        if (v1 == v2) 
        { 
            G.arcnum--;
            continue; }
        flag = 1;
        // 检查是否已经存在这条边，对于无向图只需检查一条边
        ArcNode* p = G.vertices[v1].firstarc;
        while (p != NULL) {
            if (p->adjvex == v2) {
                G.arcnum--;
                flag = 0;
                break;// 边已存在
            }
            p = p->nextarc;
        }
        // 创建边结点，并将其插入到v1的邻接表中
        if (!flag) continue;
        ArcNode* arcNode = (ArcNode*)malloc(sizeof(ArcNode));
        arcNode->adjvex = v2;
        arcNode->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = arcNode;
        // 对于无向图，还需要将边反向插入到v2的邻接表中
            arcNode = (ArcNode*)malloc(sizeof(ArcNode));
            arcNode->adjvex = v1;
            arcNode->nextarc = G.vertices[v2].firstarc;
            G.vertices[v2].firstarc = arcNode;
    }

    return OK; // 构造图成功
}
status DestroyGraph(ALGraph& G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode* p = G.vertices[i].firstarc;
        while (p)
        {
            ArcNode* q = p;
            p=p->nextarc;
            free(q);
        }
        G.vertices[i].firstarc = NULL;
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
}
int LocateVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{

    int pos = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
status PutVex(ALGraph& G, KeyType u, VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    if (LocateVex(G, value.key) != -1) return ERROR;
    int pos = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1) return ERROR;
    else 
    {
        G.vertices[pos].data = value;
        return OK;
    }

}
int FirstAdjVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{

    int pos = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            if (G.vertices[i].firstarc)
            {
                pos = G.vertices[i].firstarc->adjvex;
                break;
            }
        }
    }
    return pos;
}
int NextAdjVex(ALGraph G, KeyType v, KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    int pos = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)//如果i的关键字为v
        {
            ArcNode* p = G.vertices[i].firstarc;
            while (p)//且存在邻接顶点
            {
                int j = p->adjvex;
                if (G.vertices[j].data.key == w)//如果邻接顶点的关键字为w
                {
                    if (p->nextarc)
                    {
                        pos = p->nextarc->adjvex;
                        return pos;
                    }
                    else return -1;//w是v最后一个邻接顶点
                }
                else p = p->nextarc;
            }
            return -1;//没有找到邻接顶点w
        }
    }
    return -1;//没有找到v
}
status InsertVex(ALGraph& G, VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 判断顶点个数是否已满
    if (G.vexnum >= MAX_VERTEX_NUM) {
        return ERROR;
    }
    // 检查关键字是否重复
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v.key) {
            return ERROR;
        }
    }
    // 插入新顶点
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;

    return OK;
}
