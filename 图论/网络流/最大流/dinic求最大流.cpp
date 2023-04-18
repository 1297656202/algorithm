//dinic理论复杂度高于isap，只是单纯的留存代码，可以尽量使用isap 
//n,m,s,t分别表示点的个数、有向边的个数、源点序号、汇点序号。n<=200,m<=5000 
//求出其网络最大流。dinic经过弧优化，复杂度为O(n*n*m)
//但是一般情况下，复杂度都没这么高，很多时候可以近似认为是O(n*m) 
//另外，1单位边权的dinic复杂度为O(n*sqrt(e)) 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],cur[mn],
cnt=1,ans=0,n,m,s,t;//注意这里的cnt是从1开始的，边序号从2开始，这样（2,3）号边才是一组 
struct w{ll next,to,z;}a[mn];//注意要开边数的两倍，网络流都是双向边 
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};h[x]=cnt;
	a[++cnt]=(w){h[y],x,0};h[y]=cnt;
}
ll bfs()
{ll i,x,y;
	queue<ll>q;
	q.push(s);
	for(i=1;i<=n;i++)d[i]=0; 
	d[s]=1;
	while(q.empty()==0)
	{
		x=q.front();q.pop();
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(a[i].z>0&&d[y]==0)
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return d[t];
}
ll dfs(ll x,ll flow)
{ll y;
	if(x==t||flow==0)return flow;
	ll used=0;
	for(ll &i=cur[x];i;i=a[i].next)//弧优化 
	{
		y=a[i].to;
		if(a[i].z&&d[x]+1==d[y])
		{
			ll mi=dfs(y,min(flow-used,a[i].z));
			a[i].z-=mi;a[i^1].z+=mi;used+=mi;
			if(used==flow)return used;
		}
	}
	if(used==0)d[x]=0;
	return used;
}
ll dinic()
{
	ll maxflow=0,i,dis;
	while(bfs())
	{
		for(i=1;i<=n;i++)cur[i]=h[i];
		while(dis=dfs(s,inf))maxflow+=dis;
	}
	return maxflow;
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
	}
	printf("%lld\n",dinic());
	return 0;
}
