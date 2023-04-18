#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll h[mn],l[mn],tot=0,
f[mn][21],g[mn][21],d[mn], 
ans,cnt=0,n,m;
//注意mn应该为原树节点数的两倍，tot是dfs序列的长度，最大也是原树节点的两倍
//dfs序列是每次下去的时候就计入序列，每次从下面上来之后又计入一次 
//l[i]表示节点i在dfs序列里面的位置 
//f[i][j]表示dfs序列里面i向前爬2的j次方的所有节点里面最小的深度，g[i][j]表示最小的f[i][j]属于原树哪个节点 
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
void dfs(ll x,ll deep)//求出dfs序列 
{ll i,y;
	l[x]=++tot;d[x]=deep;f[tot][0]=deep;g[tot][0]=x;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(l[y])continue;
		dfs(y,deep+1);
		f[++tot][0]=deep;
		g[tot][0]=x;
	}
}
void st()
{ll i,j;
	for(j=1;j<=log2(tot);j++)
		for(i=1;i<=tot-(1<<j)+1;i++)
		if(f[i][j-1]<f[i+(1<<(j-1))][j-1])
		{
			f[i][j]=f[i][j-1];
			g[i][j]=g[i][j-1];
		}
		else 
		{
			f[i][j]=f[i+(1<<(j-1))][j-1];
			g[i][j]=g[i+(1<<(j-1))][j-1];
		}
}
ll lca(ll x,ll y)
{ll k;
	x=l[x];y=l[y];
	if(x>y)swap(x,y);
	k=(ll)log2(y-x+1);
	if(f[x][k]<f[y-(1<<k)+1][k])return g[x][k];
    return g[y-(1<<k)+1][k];
}
ll dis(ll x,ll y)
{
	return d[x]+d[y]-2*d[lca(x,y)];
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	st();
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",lca(x,y));
	}
	return 0;
}
