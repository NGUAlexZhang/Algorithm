#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N =20;

int ways[N],ans;
bool st[N]; 
double a,b,c,n;


void check()
{
    //边界
    for(int i=1;i<=9;i++)
    {
        if(!st[i]) return;
    }
    for(int i=1;i<8;i++)    //i,j,k代表个数
    {  
        for(int j =1;j<8;j++)
        {
            if(i+j>=9) continue;
            int count=0;
            a=b=c=0;
            while(count!=i)
                a = a*10 + ways[++count];
            while(count!=i+j)
                b = b*10 + ways[++count];
            while(count!=9)
                c= c*10 +ways[++count];
            if(n==a + b*1.0/c) ans++;
        }
        
    }
    return ;
}

void dfs(int u)     //1~9全排列
{
    //确定边界
    if(u==10){
        check();
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(!st[i]){
            st[i] = true;
            ways[u] = i;
            dfs(u+1);
            st[i] = false;
            ways[u] = 0;
        }
    }
}

int main()
{
    
    scanf("%lf",&n);
    
    dfs(1);  //当前遍历的位数
    
    cout<<ans<<endl;
    
    return 0;
    
}