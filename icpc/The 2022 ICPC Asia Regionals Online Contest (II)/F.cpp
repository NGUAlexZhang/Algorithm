#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e18+5;
ll p[100],k;
ll cnt;
ll find(ll x,ll y)
{
  if(y>x)return find(y,x);
  if(x==y)return x;
  for(ll i=0;i<cnt;i++)
  {
    if(x>p[i]&&x<=p[i+1])
    {
      x-=p[i];
      break;
    }
  }
  ll f;
  f=x/k;
  if(x%k)f++;
  return find(f,y);
}
void rmain()
{
  memset(p,0,sizeof(p));
  p[0]=1;
  cnt=0;
  ll x,y;
  scanf("%lld%lld%lld",&k,&x,&y);
  ll temp=k;
  ll cl=0;
  while(temp>=10)
  {
    temp/=10;
    cl++;
  }
  
  for(int i=1;i<=(cl==0?100:(18/cl));i++)
  {
    p[i]=p[i-1]*(k+1);
    cnt++;
    if(MAXN/k<p[i-1])
    {
      p[i]=MAXN;
      break;
    }
  }
  ll ans;
  ans=find(x,y);
  printf("%lld\n",ans);
  return;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--)
  {
    rmain();
  }
  return 0;
}