//n,m,s,t分别表示点的个数、有向边的个数、源点序号、汇点序号。n<=200,m<=5000 
//求出其网络最大流。ISAP经过GAP优化以及弧优化，复杂度为O(n*n*m)
//但是一般情况下，复杂度都没这么高，很多时候可以近似认为是O(n*m) 
//另外，1单位边权的dinic（ISAP）复杂度为O(n*sqrt(e)) 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],gap[mn],cur[mn],
cnt=1,ans=0,n,m,s,t,maxflow;//注意这里的cnt是从1开始的，边序号从2开始，这样（2,3）号边才是一组 
struct w{ll next,to,z;}a[mn];//注意要开边数的两倍，网络流都是双向边 
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};h[x]=cnt;
	a[++cnt]=(w){h[y],x,0};h[y]=cnt;
}
void bfs()
{ll i,x,y;
	for(i=1;i<=n;i++){d[i]=-1;gap[i]=0;}
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
{ll y;
	if(x==t){maxflow+=flow;return flow;}
	ll used=0;
	for(ll &i=cur[x];i;i=a[i].next)//cur[]即为弧优化 
	{
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
{ll i;
	maxflow=0;
	bfs();
	while(d[s]<n){for(i=1;i<=n;i++)cur[i]=h[i];dfs(s,inf);}
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
	printf("%lld\n",isap());
	return 0;
}
