点分树源于点分治有一些很好的性质：
1、树高严格小于等于logn
2、点分树上每个点的子树中所有点就是原树中以这个点为分治中心时要遍历到的点
3、点分树上以一个点x到根路径上的每个点为分治中心时都会遍历到这个点x
4、点分树上的边不是原树上的边
那么怎么用点分树实现动态点分治呢？我们考虑点分治以某个点为分治中心时，遍历到的点组成了一个联通块，
而这个联通块中的点就是这个分治中心在点分树上的子树中的所有点。
点分治时每个分治中心需要遍历它所在联通块来得到它和联通块内每个点之间的信息，
那么点分树上每个点就需要维护这个点和子树中每个点之间的信息。
这样当修改某个点的信息时只需要更改这个点在点分树上到根路径上每个点维护的信息。
而查询时也只需要查询点分树上从查询点到根路径上的每个点的信息进行统计。
这里有几个地方需要注意：
1、因为每个点要维护和子树中所有点的信息，所以一般来说每个点维护的信息需要用数据结构来维护，
也就是点分树套数据结构
2、因为点分树上的边不是原树上的边，所以需要用原树两点间LCA来求两点间距离，为了不影响时间复杂度，要用RMQ求LCA
3、动态点分治统计答案一般采用容斥的方法
4、构建点分树就是跑一遍不统计信息的空的点分治
5、解决动态点分治问题时可以先考虑单次询问用点分治如何处理、需要求什么信息，然后再转到点分树上进行处理。
说了这么多来看一道例题：给一棵n个节点的树，边权为1，点有点权，有m次操作，每次操作要么修改一个点的权值，
要么询问距离一个点距离小于等于k的所有点的点权和，强制在线，n,m<=10^5。
最开始在 xx 的时候，直接将 xx 子树的节点对 xx 的贡献加入答案即可。再考虑在往上爬的过程中（
设当前节点为 u ，与 x的距离为 dis），我们需要计算的是在 u 子树内但不在 x子树内的节点对 x的贡献，
也就是在 u 子树但不在 x子树的节点中与 x的距离 ≤y-dis≤y?dis 的节点的权值和。那么容斥一下可以得到，
我们要求的就是与 u子树内 u距离 ≤y-dis≤y-dis 的节点权值和减去 x子树内与 u距离 ≤y-dis≤y-dis 的权值和。
容易发现，如果我们记 W_{i,j}Wi,j 为 i子树内与 i的距离为 j的节点权值和，
那么我们每次询问的都是wi的前缀和，那么我们就可以用树状数组来维护这些信息了。
注意上面要用到的信息有两个：
1.	i子树内节点对 i的贡献。
2.	i节点子树内节点对其 i父亲的贡献。
我们分别用 C_{0,i},C_{1,i}表示这两个树状数组。
那么每次查询的时候只需要按照上述步骤完成即可，注意由于 n很大，可以用 vector 来存，
大小为 i的子树大小 +1由于距离可能为 00 ，需要将树状数组整体右移，
对于修改操作，那么我们只需要按照上述规则，一直往上爬树修改C_{0,i},C_{1,i}即可，树高小于logn 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn],l[mn],d[mn],dfn[mn],tot=0,
f[mn][21],g[mn][21],fa[mn],val[mn],
maxcore,core;
vector<ll>c[2][mn];
//c[0][i][x]维护到i距离为x的点权和，c[1][i][x]维护到点分树上的父节点fa[i]距离为x的点权和 
struct w{ll next,to;}a[2*mn];
void add(ll x,ll y)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void find(ll x,ll prt,ll num)//找重心，这一部分基本都是模板 
{ll maxx=0,i,y;
	s[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt||bj[y]==1)continue;
		find(y,x,num);
		s[x]+=s[y];
		maxx=max(maxx,s[y]);
	}
	maxx=max(maxx,num-s[x]);
	if(maxcore>maxx){maxcore=maxx;core=x;}//core为树的重心
}
void dfs(ll x,ll num,ll prt)//以x为根,总共Num个结点
{ll i,y,tmp;
    maxcore=inf;
	find(x,0,num);//求以x为根的子树的中心core，以上也是必须的模板 
	bj[core]=1;//标记，也是必须的模板 
	fa[core]=prt;
	s[core]=num;
	c[0][core].resize(s[core]+2);//动态开树状数组，最大为s[x]+2，可以开大一点防止re 
	c[1][core].resize(s[core]+2);
	tmp=core;
	for(i=h[core];i;i=a[i].next)//对于重心儿子结点处理
	{
		y=a[i].to;
		if(bj[y]==1)continue;
		dfs(y,s[y],tmp);//对以儿子结点为根的子树递归处理，也是模板套路 
	}
}
void dfs2(ll x,ll deep)
{ll i,y;
	l[x]=++tot;d[x]=deep;f[tot][0]=deep;g[tot][0]=x;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(l[y])continue;
		dfs2(y,deep+1);
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
ll low(ll x){return x&(-x);}
void ad(ll k,ll u,ll x,ll z)
{ll i;
	x++;
	for(i=x;i<=s[u]+1;i+=low(i))
	    c[k][u][i]+=z;
}
ll ask(ll k,ll u,ll x) 
{ll i,ans=0;
	x++;
	x=min(x,s[u]+1);
	for(i=x;i>0;i-=low(i))
	    ans+=c[k][u][i];
	return ans;
}
void ins(ll x,ll v)
{ll i;
	for(i=x;i;i=fa[i])ad(0,i,dis(x,i),v);
	for(i=x;fa[i];i=fa[i])ad(1,i,dis(x,fa[i]),v);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs2(1,0);
	st();
	dfs(1,n,0);
	for(i=1;i<=n;i++)
	ins(i,val[i]);
	ans=0; 
	while(m--)
	{
		scanf("%lld%lld%lld",&k,&x,&y);
		x^=ans;y^=ans;
		if(k==0)
		{
			ans=ask(0,x,y);
			for(i=x;fa[i];i=fa[i])
			{
				ll tmp=dis(x,fa[i]);
				if(y>=tmp)
				ans+=ask(0,fa[i],y-tmp)-ask(1,i,y-tmp);
			}
			printf("%lld\n",ans);
		}
		else 
		{
			ins(x,y-val[x]);
			val[x]=y;
		}
	}
    return 0;
}
