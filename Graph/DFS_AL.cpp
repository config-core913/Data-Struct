#include<iostream>
using namespace std;

//邻接表结构
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
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
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
//邻接表查找顶点位置
int LocateVex(ALGraph G,int v){
    for(int i = 0;i < G.vexnum;i++){
        if(G.vertices[i].data == v){
            return i;
        }
    }
    return -1;
}
//邻接表创建有向图
void Create_ALG(ALGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k = 0;k < G.arcnum;k++){
        VerTexType v1,v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
}
//深度优先搜索遍历
bool visited[MVNum];
void DFS_AL(ALGraph G,int v){
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while(p){
        if(visited[p->adjvex] == 0){
            DFS_AL(G,p->adjvex);
        }
        p = p->nextarc;
    }
}
int main(){
    ALGraph G;
    cout << "请输入图的信息：" << endl;
    Create_ALG(G);
    DFS_AL(G,0);
    return 0;
}