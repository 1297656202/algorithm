#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
using namespace std;
ll rs[maxn],ls[maxn],v[maxn],prt[maxn],d[maxn]={0},mans=0,maxx,minn,cnt=0,tot=0,ge,n,m,l,r;
ll gf(ll x)
{
	if(prt[x]==x)return x;
	prt[x]=gf(prt[x]);
	return prt[x];
}
ll he(ll x,ll y)
{
	if(x==0||y==0)return x+y;
	if(v[x]<v[y])swap(x,y);//这里的符号为<时为大根堆，>时为小根堆 
	rs[x]=he(rs[x],y);
	swap(ls[x],rs[x]);
	return x;
}
ll del(ll x)
{ll y;
	if(ls[x]==0&&rs[x]==0)
	{
		v[x]/=2;
		return x;
	}
	y=he(ls[x],rs[x]);
	prt[y]=y;
	prt[x]=x;
	ls[x]=rs[x]=0;
	v[x]/=2;
	ll z=he(y,x);
	prt[x]=prt[y]=z;
	return z;
}
int main()
{
	ll h,f1,f2,x,y,len,t,i,j,z;
	char ch;
	while(cin>>n)
	{
	memset(prt,0,sizeof(prt));
	for(i=1;i<=n;i++)
	   {
	   scanf("%lld",&v[i]);
	   prt[i]=i;
	   }
	cin>>m;
	for(i=1;i<=m;i++)
	   {
	   	scanf("%lld%lld",&x,&y);
	   	x=gf(x);y=gf(y);
	   	if(x==y){printf("-1\n");continue;}
	   	f1=del(x);
	   	f2=del(y);
	   	ll tmp=he(f1,f2);
	   	prt[f1]=prt[f2]=tmp;
	   	printf("%lld\n",v[tmp]);
	   }
	}
    return 0;
}
