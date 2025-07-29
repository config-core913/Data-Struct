#include<iostream>
using namespace std;

//邻接矩阵结构
#define MaxInt 32767    //极大值
#define MVNum 100       //最大顶点数
typedef char VerTexType;//顶点数据类型
typedef int ArcType;    //边数据类型
typedef struct{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum,arcnum;          //当前图的顶点数和边数
}AMGraph;
//辅助队列结构
typedef struct{
    int *data;
    int front;
    int rear;
}SqQueue;
//初始化队列
void Init_Queue(SqQueue &Q){
    Q.data = new int[MVNum];
    Q.front = Q.rear = 0;
}
//入队
bool EnQueue(SqQueue &Q,int v){
    if(Q.rear + 1 == MVNum){
        return false;
    }else{
        Q.data[Q.rear] = v;
        Q.rear++;
        return true;
    }
}
//出队
bool DeQueue(SqQueue &Q,int &v){
    if(Q.front == Q.rear){
        return false;
    }else{
        v = Q.data[Q.front];
        Q.front++;
        return true;
    }
}
//查找顶点位置（邻接矩阵）
int LocateVex(AMGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(v == G.vexs[i]){
            return i;
        }
    }
    return -1;
}
//创建无向图
void CreateUDM(AMGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vexs[i];
    }
    for(int i = 0;i < G.arcnum;i++){
        for(int j = 0;j < G.arcnum;j++){
            G.arcs[i][j] = 0;
        }
    }
    for(int k = 0;k < G.arcnum;k++){
        VerTexType v1,v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.arcs[i][j] = G.arcs[j][i] = w;
    }
}
//广度优先搜索遍历
bool visited[MVNum];
void BFS(AMGraph G,int v){
    SqQueue Q;
    Init_Queue(Q);
    EnQueue(Q,v);
    visited[v] = true;
    while(Q.front != Q.rear){
        DeQueue(Q,v);
        cout << G.vexs[v] << " ";
        for(int i = 0;i < G.vexnum;i++){
            if(visited[i] == 0 && G.arcs[v][i] != 0){
                EnQueue(Q,i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    AMGraph G;
    CreateUDM(G);

    BFS(G,0);
    return 0;
}