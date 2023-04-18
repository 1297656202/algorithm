简单来讲，就是在Kruskal算法进行的过程中，我们把最小生成树的边权改为点权。
这样，原树的节点个数变成2n-1个，并且有着许多有趣的性质。

Kruskal重构树的性质
1.根据我们构造的过程，这是一个二叉堆(后面再讲构造)
2.原树两点之间的边权最大值(最小值)是重构树上两点Lca的权值
3.重构树中代表原树中的点的节点全是叶子节点，其余节点都代表了一条边的边权。
有了这些个性质，我们就可以解决一些问题了。
时间复杂度是优秀的O(nlogn)

例题： 【BZOJ3732】网络Network
给你n个点m条边的无向图，给出q个询问， 
每个询问的格式是：A B，表示询问从A点走到B点的所有路径中，最长的边最小值是多少？
首先，我们可以知道，所有这样的路径一定存在于最小生成树上，
我们好像都会求树上的LCA倍增最小值。
但是我们发现Kruskal重构树的做法更加优美，直接求出LCA的点权即可。
类似的还有noip货车运输

可以看出，这种使两点之间路径上的最长边最小的题目很多都可以用kru重构树 

例题： 路径权值
给定一个带权树，树上任意两点间的路径权值d(x,y)定义为x,y这两个点之间路径上的边权最小值，
树上任意一点x的权值定义为这个点到树上其他所有点的路径权值和，现求树上一点，使得这个点的权值最大，输出这个值。

我们之前提到过Kruskal重构树中，两个节点的LCA节点就是两点路径上的最大/最小节点。
也就是说，对于一个非叶节点x，它左子树中的节点到右子树中的节点的路径一定会经过x节点所对应的边，反之亦然。
那么我们就可以建出Kruskal重构树之后维护当前边对于重构树子树中节点的贡献了。
因为一条边所代表的节点x的左边的所有叶子节点都需要加上v[x]*sz[rs[x]],
也就是说这条边的权值乘上他的右儿子的节点总数，右边的叶子节点也是一样的 
这相当于是区间中的所有元素同时加上一个数， 最后再询问每一个节点的值 
这个区间加法的过程我们可以用树状数组实现。

例题： H.Life is a Game
给你一个图，图上有点权和边权。以及q个查询：每个查询给你一个初始位置x和初始能量k。
你每到一个新点上即可获得该点的能量（即点权），但是如果想通过一条边，你的能量总数需要大于边权。
问：可以获取的最大能量数
重构树以后， 对于X点是否能通过就是能量[X的子树和]+初始能量值>=父节点点权
变换得 初始能量值>=父节点点权-能量[X的子树和]
这个(父节点点权-能量[X的子树和])可以通过倍增快速得到一段区域内的最大值，
然后就可以通过倍增爬树法来判断是否可以跳过这段区域 
代码如下： 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll prt[mn],h[mn],v[mn],f[mn][21],sz[mn],g[mn][21],
ans,cnt,tot,n,m;
struct w{ll next,to;}a[mn];
struct ww{ll x,y,z;}c[mn];
bool cmp(ww a,ww b){return a.z<b.z;}
ll gf(ll x)
{
	if(prt[x]==x)return x;
	prt[x]=gf(prt[x]);
	return prt[x];
}
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
void exkru()//这一段是exkru的模板 
{ll i;
	for(i=1;i<=2*n-1;i++)
		prt[i]=i;
	sort(c+1,c+m+1,cmp);
	tot=n;
	for(i=1;i<=m;i++)
	{
		ll f1=gf(c[i].x),f2=gf(c[i].y);
		if(f1==f2)continue;
		prt[f1]=prt[f2]=++tot;
		v[tot]=c[i].z;
		add(tot,f1);
		add(tot,f2);
		if(tot==2*n-1)break;
	}
}
void dfs(ll x)//遍历重构树 
{ll i,y;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		sz[x]+=sz[y];
		g[y][0]=v[x]-sz[y];
		f[y][0]=x;
	}
}
void st()//在重构树上倍增 
{ll i,j;
	for(j=1;j<=20;j++)
		for(i=1;i<=2*n-1;i++)
			if(f[i][j-1]!=-1&&f[f[i][j-1]][j-1]!=-1)
			{
				f[i][j]=f[f[i][j-1]][j-1];
				g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
			}
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>t;
	for(i=1;i<=n;i++)
		scanf("%lld",&sz[i]);
	for(i=1;i<=m;i++)
		scanf("%lld%lld%lld",&c[i].x,&c[i].y,&c[i].z);
	exkru();
	for(i=1;i<=2*n-1;i++)
		for(j=0;j<=20;j++)
		g[i][j]=inf;
	memset(f,-1,sizeof(f));
	dfs(2*n-1);
	st();
	while(t--)
	{
		scanf("%lld%lld",&x,&z);
		for(i=20;i>=0;i--)
		if(z>=g[x][i])
		{
			x=f[x][i];
		}
		printf("%lld\n",sz[x]+z);
	}
    return 0;
}
最后在那个学习笔记里面还有一道经典题目要用持久化数据结构，我就等会再总结好了 
