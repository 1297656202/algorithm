//如题，已知一棵包含 N个结点的树（连通且无环），每个节点上包含一个数值，需要支持以下操作：
//1 x y z，表示将树从 x 到 y 结点最短路径上所有节点的值都加上 z。
//2 x y，表示求树从 x到 y结点最短路径上所有节点的值之和。
//3 x z，表示将以 x为根节点的子树内所有节点值都加上 z。
//4 x 表示求以 x为根节点的子树内所有节点值之和
//这种题权值都是点权，如果是边权，就将(prt[x],x)的权值放置于x中 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],sz[mn],dep[mn],h[mn],son[mn],
id[mn],top[mn],d[mn],fa[mn],sum,
mod,rt=1,cnt=0,tot=0,ans,n,m;
struct w{ll next,to;}a[mn*2];
struct ww{ll a,b,s,add;}c[mn*4];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
ll dfs(ll x,ll prt,ll deep)//第一次dfs，找出每个节点的dep，fa和重儿子以求出重路径 
{ll i,y,maxx=0;
	dep[x]=deep;
	fa[x]=prt;
	sz[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		sz[x]+=dfs(y,x,deep+1);
		if(sz[y]>maxx){maxx=sz[y];son[x]=y;}
	}
	return sz[x];
}
void dfs2(ll x,ll tp)//第二次dfs，tp是整条链的顶点 
{ll i,y;
	id[x]=++tot;//x节点对应线段树的第tot个叶子节点 
	d[tot]=b[x];//线段树的第tot个叶子节点的权值是多少 
	top[x]=tp;
	if(son[x]==0)return ;
	dfs2(son[x],tp);
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(id[y]==0)dfs2(y,y);
	}
}
void up(ll x)//线段树上传标记 
{
	c[x].s=c[x*2].s+c[x*2+1].s;
}
void bui(ll v,ll l,ll r)//建立线段树 
{
	c[v].a=l;c[v].b=r;
	if(l==r){c[v].s=d[l];return ;}
	ll mid=(l+r)/2;
	bui(2*v,l,mid);
	bui(2*v+1,mid+1,r);
	up(v);
}
void down(ll v)//线段树下传标记 
{
	if(c[v].add)
	{
		c[v*2].s+=c[v].add*(c[v*2].b-c[v*2].a+1);
		c[v*2+1].s+=c[v].add*(c[v*2+1].b-c[v*2+1].a+1);
		c[v*2].add+=c[v].add;
		c[v*2+1].add+=c[v].add;
		c[v].add=0;
	}
}
void segadd(ll v,ll l,ll r,ll x)//将线段树的(l,r)区间添加x 
{
	if(c[v].b<l||c[v].a>r)return;
	if(l<=c[v].a&&r>=c[v].b)
	{
		c[v].s+=x*(c[v].b-c[v].a+1);
		c[v].add+=x;
		return ;
	}
	down(v);
	segadd(v*2,l,r,x);
	segadd(v*2+1,l,r,x);
	up(v);
}
void segsum(ll v,ll l,ll r)//求线段树上的sum(l,r) 
{
	if(r<c[v].a||l>c[v].b)return ;
	if(l<=c[v].a&&r>=c[v].b){sum=sum+c[v].s;return ;}
	down(v);
	segsum(2*v,l,r);
	segsum(2*v+1,l,r);
}
void add(ll x,ll y,ll z)//将树上路径x到y每个点添加z 
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		segadd(1,id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	segadd(1,id[x],id[y],z);
	//segadd(1,id[son[x]],id[y]);//边权
}
ll Sum(ll x,ll y)//求树上x到y的路径和 
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		segsum(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	segsum(1,id[x],id[y]);
	//segsum(1,id[son[x]],id[y]);//边权
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>rt>>mod;//原题是输入的rt 
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(rt,0,1);
	dfs2(rt,rt);
	bui(1,1,n);
	while(m--)
	{
		scanf("%lld%lld",&k,&x);
		if(k==1)
		{
			scanf("%lld%lld",&y,&z);
			add(x,y,z);
		}
		if(k==2)
		{
			scanf("%lld",&y);
			sum=0;Sum(x,y);
			printf("%lld\n",sum%mod);
		}
		if(k==3)//很显然一颗子树里面的节点在线段树上都是连在一起的 
		{
			scanf("%lld",&z);
			segadd(1,id[x],id[x]+sz[x]-1,z);
		}
		if(k==4)
		{
			sum=0;segsum(1,id[x],id[x]+sz[x]-1);
			printf("%lld\n",sum%mod);
		}
	}
	return 0;
}
