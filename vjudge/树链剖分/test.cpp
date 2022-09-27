//by:hyfhaha 
#include<bits/stdc++.h>
using namespace std;
const long long maxn=1200100;		//特以此纪念本人数据范围开小卡90分卡两天
int a[maxn],tree[maxn],tag[maxn],n,m,mode,x,y,z,S,cnt;
int large[maxn],seg[maxn],father[maxn],vis[maxn],dep[maxn],son[maxn],rev[maxn],top[maxn];
int Next[maxn],head[maxn],from[maxn],to[maxn],id[maxn],tot;
//********************以下线段树********************
void pushdown(int node,int begin,int end){
    if(tag[node]){
        int m=(begin+end)/2;
        tree[node*2]+=tag[node]*(m-begin+1);
        tree[node*2+1]+=tag[node]*(end-m);
        tag[node*2]+=tag[node];
        tag[node*2+1]+=tag[node];
        tag[node]=0;
    }
}
int query(int node,int begin,int end,int x,int y){
    if(x<=begin&&end<=y)
    return tree[node];
    else{
        int m=(begin+end)/2,res=0;
        pushdown(node,begin,end);
        if(x<=m)
            res+=query(node*2,begin,m,x,y);
        if(y>m)
            res+=query(node*2+1,m+1,end,x,y);
        return res;
    }
}
void update(int node,int begin,int end,int x,int y,int val){
    if(x<=begin&&end<=y){
        tree[node]+=val*(end-begin+1);
        tag[node]+=val;
    }
    else{
        int m=(begin+end)/2; 
        pushdown(node,begin,end);
        if(x<=m){
            update(node*2,begin,m,x,y,val);
        }
        if(y>m){
            update(node*2+1,m+1,end,x,y,val);					 
        }
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
//********************以上线段树********************
//********************以下树链剖分********************
void dfs1(int x,int f){
    large[x]=1;father[x]=f;
    dep[x]=dep[f]+1;
    int maxy=0;
    for(int i=head[x];i!=-1;i=Next[i]){
        int u=to[i],big=0;
        if(u==f)continue;
        dfs1(u,x);
        large[x]+=large[u];
        if(large[u]>maxy){son[x]=u;maxy=large[u];}
    }
}
void dfs2(int x,int f){
    top[x]=f;id[x]=++tot;
    if(!son[x]){
        return;
    }
    dfs2(son[x],f);
    for(int i=head[x];i!=-1;i=Next[i]){
        int u=to[i];
        if(u!=son[x]&&u!=father[x]){
            dfs2(u,u);
        }
    }
}
void updatelong(int x,int y,int z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
        	update(1,1,n,id[top[y]],id[y],z);
       	 	y=father[top[y]];
    	}else{
    		update(1,1,n,id[top[x]],id[x],z);
       	 	x=father[top[x]];
        }
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],z);
}
//********************以上树链剖分********************
void add(int x,int y){	//建边 
    cnt++;
    from[cnt]=x;to[cnt]=y;
    Next[cnt]=head[x];head[x]=cnt;
}
//********************以下主程序********************
int main(){
    scanf("%d",&n);S=1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs1(S,0);dfs2(S,S);
    for(int i=1;i<=n-1;i++){
    	updatelong(a[i],a[i+1],1);
    	updatelong(a[i+1],a[i+1],-1);//记得终点减1
    }
    for(int i=1;i<=n;i++)
    printf("%d\n",query(1,1,n,id[i],id[i]));
}//光棍数字收场 