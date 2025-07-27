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
//查找顶点位置（邻接矩阵）
int LocateVex(AMGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i++){
        if(v == G.vexs[i]){
            return i;
        }
    }
    return -1;
}
//创建无向网
void CreateUDM(AMGraph &G){
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++){
        cin >> G.vexs[i];
    }
    for(int i = 0;i < G.arcnum;i++){
        for(int j = 0;j < G.arcnum;j++){
            G.arcs[i][j] = MaxInt;
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
int main(){

    return 0;
}