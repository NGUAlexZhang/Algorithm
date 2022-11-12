#include<iostream>
#include<iomanip>
#include<fstream>

#define INF 0x3f3f3f3f
#define vNum 100   //顶点个数
#define typedata int 

using namespace std;

int p[vNum];  //存放路径


typedef struct Node{
    int edge[vNum][vNum];  //邻接矩阵
    int v;   //顶点个数
    int vis[vNum];  //访问标记数组
}G;

void InitUDG(G &g)    //无向图初始化
{
    fstream of("input.txt",ios_base::in);
    int v1,v2;
    of>>g.v;   //顶点个数
    for(int i =0;i<g.v; i ++)
    {
        g.vis[i] = 0;  //未被访问
        for(int j=0;i<g.v;i++)
            g.edge[i][j] = 0;   //无向图中仅用逻辑1 就可
    }
    while(of>>v1>>v2&&v1>=0&&v2>=0)
        {
            g.edge[v1][v2] = 1;
            g.edge[v2][v1] = 1;   //无向图
        }
        of.close();
}
int count=0;
void dfs(G& g,int st)  //st 初始顶点
{
    if(g.vis[st]) return;  // 1 已代表访问，退出访问
    // static int count=0;
    g.vis[st] = 1; //已访问
    if(count==g.v) return;
    p[count++] = st;
    for(int i=0;i<g.v;i++)
        {
            if(g.edge[st][i]==0) continue;
            if(!g.vis[i])
            {
                dfs(g,i);
            }
        }
    return ;
}

void displayMatrix(G g)
{
    for(int i=0;i<g.v;i++){
        for(int j=0;j<g.v;j++)
            cout<<setw(5)<<g.edge[i][j];
    cout<<endl;
    }

}

void displayPath(G g)
{
    cout<<"Dfs遍历路径 : "<<endl;
    for(int i=0;i<g.v;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    G g;
    InitUDG(g);
    displayMatrix(g);
   for(int i=0;i<g.v;i++)
   {
       for(int j=0;j<g.v;j++){
        g.vis[j] = 0;
       }
       count = 0;
       dfs(g,i);
       displayPath(g);
   }
    // dfs(g,3);
    // displayPath(g);

}
