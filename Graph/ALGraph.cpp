#include<iostream>
using namespace std;

typedef char VerTexType;
//边结点
#define MVNum 100
typedef struct ArcNode{ 
    int adjvex;         //改边指向的顶点位置
    ArcNode *nextarc;   //指向下一条边的指针
}ArcNode;
//顶点表单个元素
typedef struct VNode{
    VerTexType data;    //顶点
    ArcNode *firstarc;  //指向第一条边的指针
}VNode,AdjList[MVNum];  //AdjList表示邻接表类型
//顶点表
typedef struct{
    AdjList vertices;   
    int vexnum,arcnum;  //图的顶点数和边数
}ALGraph;
//查找顶点位置
int LocateVex(ALGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(v == G.vertices[i].data){
            return i;
        }
    }
    return -1;
}
//邻接表创建无向图
void CreateUDG(ALGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k = 0;k < G.arcnum;k++){
        VerTexType v1,v2;
        cin >> v1 >> v2;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        ArcNode *p2 = new ArcNode;
        p2->adjvex = j;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
}
int main(){

    return 0;
}