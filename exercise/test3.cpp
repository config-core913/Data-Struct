#include<iostream>
using namespace std;

//邻接矩阵结构
#define MVNum 100
#define MAXInt 32767
typedef char VerTexType;
typedef int ArcType;
typedef struct{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
//邻接表结构
//边结点
typedef struct ArcNode{
    int adjvex;
    ArcNode *nextarc;
}ArcNode;
//顶点表单个元素
typedef struct VNode{
    VerTexType data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];
//邻接表
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
//邻接表查找顶点位置
int Locate_ALG(ALGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(v == G.vertices[i].data){
            return i;
        }
    }
    return -1;
}
//查找顶点位置——邻接矩阵
int LocateVex_AMG(AMGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(v == G.vexs[i]){
            return i;
        }
    }
    return -1;
}
//邻接矩阵创建无向图
void Create_UDN(AMGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vexs[i];
    }
    for(int i = 0;i < G.vexnum;i++){
        for(int j = 0;j < G.vexnum;j++){
            G.arcs[i][j] = MAXInt;
        }
    }
    for(int k = 0;k < G.arcnum;k++){
        VerTexType v1,v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex_AMG(G,v1);
        int j = LocateVex_AMG(G,v2);
        G.arcs[i][j] = G.arcs[j][i] = w;
    }
}
//邻接矩阵——深度优先遍历
bool visited[MVNum];
void DFS_AMG(AMGraph G,int v){
    cout << G.vexs[v] << " ";
    visited[v] = true;
    for(int i = 0;i < G.vexnum;i++){
        if(visited[i] == 0 && G.arcs[v][i] != MAXInt){
            DFS_AMG(G,i);
        }
    }
}
//邻接表创建有向图
void Create_DG(ALGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k = 0;k < G.arcnum;k++){
        VerTexType v1,v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = Locate_ALG(G,v1);
        int j = Locate_ALG(G,v2);
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
}
//邻接表深度优先遍历
bool visited_AL[MVNum];
void DFS_AL(ALGraph G,int v){
    cout << G.vertices[v].data << " ";
    visited_AL[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while(p){
        if(visited_AL[p->adjvex] == 0){
            DFS_AL(G,p->adjvex);
        }
        p = p->nextarc;
    }
}
int main(){
    // AMGraph G;
    // Create_UDN(G);
    // DFS_AMG(G,0);

    ALGraph G;
    Create_DG(G);
    DFS_AL(G,0);

    return 0;
}