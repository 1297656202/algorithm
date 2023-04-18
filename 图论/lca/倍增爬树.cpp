#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt=0,m;
ll f[100005][21],d[200005]={0},siz[200005]={0},h[200005]={0};
struct jjd
{	ll to,next;
}a[200005];
void add(ll x,ll y)
{	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(ll x,ll prt)
{ll i,y;
	f[x][0]=prt;
	for(i=h[x];i;i=a[i].next)
	{	y=a[i].to;
		if(y==prt)continue;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}
void st()
{ll i,j;
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(f[i][j-1]!=-1&&f[f[i][j-1]][j-1]!=-1)
				f[i][j]=f[f[i][j-1]][j-1];
}
ll lca(ll x,ll y)
{ll i;
	if(d[x]<d[y])swap(x,y);
	for(i=20;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	if(x==y)return y;
	for(i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	return f[x][0];
}
ll climb(ll x,ll dis)//从x往上爬到dis这么高 
{ll i;
	for(i=20;i>=0;i--)
		if(d[x]-(1<<i)>=dis)x=f[x][i];
	return x;
}
ll dis(ll x,ll y) 
{
	return d[x]+d[y]-2*d[lca(x,y)];
}
bool check(ll x,ll s,ll t)//检查x是否在s到t的路线上 
{
    if(dis(s,x)+dis(x,t)==dis(s,t))return 1;
    return 0;
}
/*bool check(ll x,ll s,ll t)//检查x是否在s到t的路线上的第二种写法 
{
	if(d[x]>=d[lca(s,t)]&&((lca(x,s)==x)||(lca(x,t)==x)))return 1;
	return 0;
}
判断x是否在s到t的路径上，要满足两个条件
1、x比s和t的lca深
2、x和s 或 x和t 的lca等于x
*/
 
//当两条路线相交时，一定有一条线的lca在另外一条线上

int main()
{	ll i,x,y;
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{	scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	memset(f,-1,sizeof(f));
	d[1]=0;
	dfs(1,0);
	f[1][0]=-1;
	st();
	return 0;
}
