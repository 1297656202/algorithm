树形dp入门经典题 p2014 
大意就是学n门课可以获得相应的学分v[i],但学一门课必须先学习他的先修课
给定能学的课程数m，求能得的最大学分。

很经典，就是一个树上的01背包，注意倒序枚举。当然，并不是所有的题目都可以倒序枚举从而实现压维的， 
有的时候我们需要通过tmp数组对前一次的状态进行记录，然后让f数组从tmp数组转移以避免麻烦 

然后，还有就是这一类的题目很多时候一开始要把所有的状态置为-1或者-inf这样的非法值，
否则在dp过程中很容易出现错误 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2005
using namespace std;
ll h[mn],v[mn],f[mn][mn],ans,cnt=0,n,m;
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
void dfs(ll x)
{ll i,y,j,k;
	f[x][1]=v[x]; 
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		for(j=m;j>=1;j--)//倒序枚举，这个本质上是一个01背包 
            for(k=j-1;k>=1;k--)
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]);
	}
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&v[i]);
		add(x,i);
	}
	m++;// 由于0节点的参与，m需要自加1
	dfs(0);//搜索0号节点
    cout<<f[0][m];
	return 0;
}

但是其实还有一种优化，在某些题目里面真的用得到，就是把dfs部分改一改，用sz[]将其的范围缩减一下
可以看出，其实优化之后，任何一个点对只会在其lca处被统计了，所以理论复杂度是O（n*m）
如果不需要优化并且要好写的话就写上面那个，需要优化就写下面那个 

void dfs(ll x)
{ll i,y,j,k;
	f[x][1]=v[x];sz[x]=1; 
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		for(j=sz[x];j>=1;j--)//倒序枚举，这个本质上是一个01背包 
            for(k=min(sz[y],m-j);k>=1;k--)
                f[x][j+k]=max(f[x][j+k],f[x][j]+f[y][k]);
		sz[x]+=sz[y];
	}
}
P3177 [HAOI2015] 树上染色
有一棵点数为 n 的树，树边有边权。给你一个在 0～n 之内的正整数 k ，
你要在这棵树中选择 k个点，将其染成黑色，并将其他 的 n-k 个点染成白色。将所有点染色后，
你会获得黑点两两之间的距离加上白点两两之间的距离的和的受益。问受益最大值是多少。

这个题就要用到上面的那个优化，复杂度降到O（n*m），并且这个优化还能避免很多麻烦

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2005
using namespace std;
ll f[mn][mn],h[mn],sz[mn],
ans=0,cnt=0,n,m,p;
struct w{ll next,to,z;}a[mn*2];
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
void dfs(ll x,ll prt)
{ll i,y,j,k;
	sz[x]=1;
	f[x][0]=f[x][1]=0;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		dfs(y,x);
		for(j=min(sz[x],m);j>=0;j--)
			for(k=min(sz[y],m-j);k>=0;k--)
				f[x][j+k]=max(f[x][j+k],
				f[x][j]+f[y][k]+k*(m-k)*a[i].z+(sz[y]-k)*(n-m-(sz[y]-k))*a[i].z);
		sz[x]+=sz[y];
	}
}
int main()
{
	ll te,x,y,i,j,k,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
			f[i][j]=-inf;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout<<f[1][m];
    return 0;
}

