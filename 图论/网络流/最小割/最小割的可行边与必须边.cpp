首先求最大流，那么最小割的可行边与必须边都必须是满流

残量网络：残量网络是最大流中的一个重要概念，假设有一源点为s汇点为t的流网络G=(V,E)，f是G中的一个流，
可以定义边u,v的剩余容量Gf(u,v)=c(u,v)-f(u,v)，由此定义残量网络Gf(V,Ef)。 

可行边 (x,y)：在残量网络中不存在 x 到 y 的路径。
必须边 (x,y)：在残量网络中 S 能到 x 且 y能到 T。

最小割的可行边：被某一种最小割方案包含的边。
充要条件：
1. 满流。
2. 在残余网络中找不到入点到出点的路径。

求法：
在残余网络中tarjan求SCC，入出两点在同一SCC中说明残余网络中存在入点到出点的路径。
由于该边满流，它的反向边一定存在于残余网络中，反向边与其他入点到出点的路径会构成SCC。

最小割的必须边（不考虑容量为0的边）：一定在最小割中的边。必须边的另一种理解是扩大容量后能增大最大流的边。
充要条件：
1. 满流。
2. 残余网络中源点能到入点，出点能到汇点。

求法：
在残余网络上从源点开始dfs，从汇点开始反向dfs，标记到达的点，然后枚举满流边判断即可。
若求过可行边，已经有了SCC，直接判断入点是否与源点在同一SCC中且出点是否与汇点在同一SCC中即可。
考虑为什么两种算法是等价的，由于源点到入点一定有流，所以一定存在入点到源点的有流路径，等价得证。

例题：P4126
先给定一个最小割模型，对每条边询问其是否为可行边和必须边，是输出1，否则输出0 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],gap[mn],cur[mn],
low[mn],dfn[mn],in[mn],stk[mn],
scc[mn],sign=0,top=0,sum=0,
cnt=1,ans=0,n,m,s,t,maxflow;//注意这里的cnt是从1开始的，边序号从2开始，这样（2,3）号边才是一组 
struct w{ll x,next,to,z;}a[mn];
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){x,h[x],y,z};
	h[x]=cnt;
}
void bfs()
{ll i,x,y;
	memset(d,-1,sizeof(d));
	memset(gap,0,sizeof(gap));
	d[t]=0;gap[0]=1;
	queue<ll>q;
	q.push(t);
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(d[y]!=-1)continue;
			q.push(y);
			d[y]=d[x]+1;
			gap[d[y]]++;
		}
	}
}
ll dfs(ll x,ll flow)
{ll i,y;
	if(x==t){maxflow+=flow;return flow;}
	ll used=0;
	for(i=cur[x];i;i=a[i].next)//cur[]即为弧优化 
	{
		cur[x]=i;
		y=a[i].to;
		if(a[i].z&&d[y]+1==d[x])
		{
			ll mi=dfs(y,min(a[i].z,flow-used));
			if(mi){a[i].z-=mi;a[i^1].z+=mi;used+=mi;}
			if(used==flow)return used;
		}
	}
	if(--gap[d[x]]==0)d[s]=n+1;
	d[x]++;gap[d[x]]++;
	return used;
}
ll isap()
{
	maxflow=0;
	bfs();
	while(d[s]<n){memcpy(cur,h,sizeof(h));dfs(s,inf);}
	return maxflow;
}
void tarjan(ll x)//有向图求强联通分量 
{ll i,y;
	dfn[x]=++sign;
	low[x]=sign;
	stk[++top]=x;
	in[x]=1;
	for(i=h[x];i;i=a[i].next)
	if(a[i].z)//必须要还有剩余流量，也就是在残量网络中  
	{
		y=a[i].to;
		if(dfn[y]==0)
		{
	   		tarjan(y);
	   		low[x]=min(low[x],low[y]);
	   	}
		else if(in[y]==1)low[x]=min(low[x],dfn[y]);
	}
    if(low[x]==dfn[x])
    {
		sum++; 
    	do
		{
			y=stk[top--];	
			scc[y]=sum;//scc[]为节点属于缩块后的哪个块  
			in[y]=0;
       	}while(x!=y);
    }
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,0);
	}
	ll flow=isap();
	for(i=1;i<=n;i++)
	if(scc[i]==0)tarjan(i);
	for(i=2;i<=cnt;i+=2)
	{
		x=a[i].x,y=a[i].to;
		if(a[i].z==0&&scc[x]!=scc[y])
		{
			printf("1 ");
			if(scc[x]==scc[s]&&scc[y]==scc[t])printf("1");
			else printf("0");
		}
		else printf("0 0");
		printf("\n");
	}
	return 0;
}
