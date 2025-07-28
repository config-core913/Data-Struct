#include<iostream>
using namespace std;

//邻接矩阵结构
#define MVNum 100
#define MaxInt 32767
typedef int ArcType;
typedef char VerTexType;
typedef struct {
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
//查找顶点位置
int LocateVex(AMGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(G.vexs[i] == v){
            return i;
        }
    }
    return -1;
}
//邻接矩阵创建无向图
void Create_UDG(AMGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vexs[i];
    }
    for(int i = 0;i < G.vexnum;i++){
        for(int j = 0;j < G.vexnum;j++){
            G.arcs[i][j] = G.arcs[j][i] = 0;
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
//深度优先搜索遍历
bool visited[MVNum];
void DFS_AM(AMGraph G,int v){
    cout << G.vexs[v] << " ";
    visited[v] = true;
    for(int i = 0;i < G.vexnum;i++){
        if(G.arcs[v][i] != 0 && visited[i] == 0){
            DFS_AM(G,i);
        }
    }
}
int main(){
    AMGraph G;
    cout << "请输入图的信息：" << endl;
    Create_UDG(G);
    DFS_AM(G,0);

    return 0;
}