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
status DeleteVex(ALGraph& G, KeyType v) {
    int i, j;
    ArcNode* p, * q;
    
    // 定位要删除的结点
    j = LocateVex(G, v);
    if (j == -1) return ERROR;//如果没找到，返回ERROR

    // 删除目标结点所有关联的边
    p = G.vertices[j].firstarc;
    while (p) {
        q = p;
        p = p->nextarc;
        free(q);
        G.arcnum--;
    }

    //顶点数目减一
    G.vexnum--;

    // 移动顶点位置
    for (i = j; i < G.vexnum; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    q = NULL;
    // 更新剩余顶点的边
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p) {
            if (p->adjvex == j) { //被删除的顶点
                if (p == G.vertices[i].firstarc) //如果此时p为i关联的第一条边
                {
                    G.vertices[i].firstarc = p->nextarc;//将i的第一条关联边更新
                    free(p);//释放该边
                    p = G.vertices[i].firstarc;
                }
                else {
                    if (q) {
                        q->nextarc = p->nextarc;
                        free(p);//释放该边
                        p = q->nextarc;
                    }  
                }
            }
            else {
                //如果关联的是j后面的顶点
                if (p->adjvex > j)
                    p->adjvex--;//将其对应的数值减1（因为在数组中向前移动了
                q = p;//q为i上一条关联的边
                p = p->nextarc;//下一条i关联边
            }
        }
    }

    return OK;
}
status InsertArc(ALGraph& G, KeyType v, KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    int i, j;
    i = LocateVex(G, v);
    j= LocateVex(G, w);
    if (i == -1 || j == -1) return ERROR;
    ArcNode* p = G.vertices[i].firstarc;
    while (p)
    {
        if (p->adjvex == j) return ERROR;
        else p = p->nextarc;
    }
    ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode));
    q->adjvex = j;
    q->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = q;

    ArcNode *r = (ArcNode*)malloc(sizeof(ArcNode));
    r->adjvex = i;
    r->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = r;
    G.arcnum ++;
    return OK;
}
status DeleteArc(ALGraph& G, KeyType v, KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    int i, j;
    int flag1=0,flag2=0;
    i = LocateVex(G, v);
    j = LocateVex(G, w);
    if (i == -1 || j == -1) return ERROR;
    ArcNode* p = G.vertices[i].firstarc;
    ArcNode* q = NULL;
    while (p&&!flag1)
    {
        if (p->adjvex == j)
        {
            if (p == G.vertices[i].firstarc) //如果此时p为i关联的第一条边
            {
                G.vertices[i].firstarc = p->nextarc;//将i的第一条关联边更新
                free(p);//释放该边
                p = G.vertices[i].firstarc;
                
            }
            else {
                if (q) {
                    q->nextarc = p->nextarc;
                    free(p);//释放该边
                    p = q->nextarc;
                }
            }
            flag1 = 1;
        }
        else {
            //如果不是，往后遍历
            q = p;//q为i上一条关联的边
            p = p->nextarc;//下一条i关联边
        }
    } 
    p = G.vertices[j].firstarc;
    q = NULL;
    while (p&&!flag2)
    {
        if (p->adjvex == i)
        {
            if (p == G.vertices[j].firstarc) //如果此时p为i关联的第一条边
            {
                G.vertices[j].firstarc = p->nextarc;//将i的第一条关联边更新
                free(p);//释放该边
                p = G.vertices[i].firstarc;
            }
            else {
                if (q) {
                    q->nextarc = p->nextarc;
                    free(p);//释放该边
                    p = q->nextarc;
                }
            }
            flag2 = 1;
        }
        else {
            //如果不是，往后遍历
            q = p;//q为i上一条关联的边
            p = p->nextarc;//下一条i关联边
        }
    }
    if (flag1 && flag2) {
        G.arcnum--;
        return OK;
    }
    else return ERROR;
}
void visit(VertexType v)
{
    printf(" %d %s", v.key, v.others);
}
void DFS(ALGraph& G, int v, bool visited[]) {
    // 标记为已访问
    visited[v] = true;
    visit(G.vertices[v].data);


    ArcNode* p = G.vertices[v].firstarc;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex, visited);
        }
        p = p->nextarc;
    }
}
status DFSTraverse(ALGraph& G)
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{

    bool Visited[MAX_VERTEX_NUM] = { 0 };
    for (int i = 0; i < G.vexnum; i++) {
        if (!Visited[i]) {
            DFS(G, i, Visited);
        }
    }
    return OK;
}
void BFSTraverse(ALGraph& G) {
    bool visited[MAX_VERTEX_NUM] = { 0 };
    queue<int> Q;

    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])//如果未访问过
        {
            visited[i] = true;
            visit(G.vertices[i].data);
            Q.push(i);  //入队

            while (!Q.empty())//当队列不为空
            {
                int v = Q.front();//已访问的出队，找它的下一层
                Q.pop();
                for (ArcNode* p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {
                    int w = p->adjvex;
                    if (!visited[w]) //将下一层访问并入队
                    {
                        visited[w] = true;
                        visit(G.vertices[w].data);
                        Q.push(w);
                    }
                }
            }
        }
    }
}
void PrintfGraph(ALGraph G)
{
    for (int j = 0; j < G.vexnum; j++)
    {
        ArcNode* p = G.vertices[j].firstarc;
        printf("%d %s", G.vertices[j].data.key, G.vertices[j].data.others);
        while (p)
        {
            printf(" %d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    FILE* fp = fopen(FileName, "w");
    for (int i = 0; i < G.vexnum; i++)
    {
        fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    fprintf(fp, "-1 nill ");
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode* p = G.vertices[i].firstarc;
        int VR[101][2];
        while (p)
        {
            if (p->adjvex > i)
            {
                fprintf(fp, "%d %d ", G.vertices[i].data.key, G.vertices[p->adjvex].data.key);
            }
            p = p->nextarc;
        }
    }
    fprintf(fp, "-1 -1");
    fclose(fp);
    return OK;
}
status LoadGraph(ALGraph& G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    VertexType V[21];
    KeyType VR[100][2];
    FILE* fp = fopen(FileName, "r");
    int i = 0;
    //从文件中读入数据到数组
    do {
        fscanf(fp,"%d%s", &V[i].key, V[i].others);
    } while (V[i++].key != -1);
    i = 0;
    do {
        fscanf(fp,"%d%d", &VR[i][0], &VR[i][1]);
    } while (VR[i++][0] != -1);
    CreateCraph(G, V, VR);//调用Creat函数
    fclose(fp);
    return OK;
}
