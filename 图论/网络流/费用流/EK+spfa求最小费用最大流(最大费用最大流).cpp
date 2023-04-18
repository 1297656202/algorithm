//输入第一行包含四个整数 n,m,s,t分别代表点数，边数，源点，汇点。（n<=5000，m<=50000） 
//接下来 m行，每行四个整数ui,vi,wi,ci，分别代表第 i条边的起点，终点，流量限制，单位流量费用。
//现在你要求出当前网络的最大流，并且求出保证最大流时的最小花费 
//原理为EK+spfa，求最大费用最大流只需要将单位流量费用取负，或者将spfa改为求最长路 
//spfa可以加上SLF优化（LLL优化用处不大）来加快速度 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll bj[mn],mincost=0,pre[mn],d[mn],
cnt=1,n,m,s,t,maxflow=0,h[mn];
//maxflow为最大流，mincost为最小花费  
struct w{ll z,v,to,next;}a[mn*2];
void add(ll x,ll y,ll z,ll k)
{
	a[++cnt]=w{z,k,y,h[x]};h[x]=cnt;
	a[++cnt]=w{0,-k,x,h[y]};h[y]=cnt;
}
bool spfa(ll s,ll t)
{ll i,x,y;
	queue<ll>q;
	for(i=1;i<=n;i++){d[i]=inf;bj[i]=0;pre[i]=0;}
	q.push(s);
	d[s]=0;
	bj[s]=1;
	while(q.empty()==0)
	{
		x=q.front();
	 	q.pop();
	 	bj[x]=0;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(a[i].z&&d[x]+a[i].v<d[y])
			{
				d[y]=d[x]+a[i].v;
				pre[y]=i;
				if(bj[y]==0)
				{
					bj[y]=1;
					q.push(y);
				}
			}
		}
	}
	if(d[t]<inf)return 1;
	else return 0;
}
void mcmf()
{ll i,p,del=inf;
	for(i=t;i!=s;i=a[p^1].to)
	{
		p=pre[i];
		del=min(del,a[p].z);
	}
	for(i=t;i!=s;i=a[p^1].to)
	{
		p=pre[i];
		a[p].z-=del;
		a[p^1].z+=del;
	}
	maxflow+=del;
	mincost+=d[t]*del;
}
void ek()
{
	while(spfa(s,t))mcmf();
}
int main()
{
	ll x,y,k,i,j,z;
	char ch;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		ll cost;
		scanf("%lld%lld%lld%lld",&x,&y,&z,&cost);
		add(x,y,z,cost);
	}
	ek();
	cout<<maxflow<<" "<<mincost<<endl;
	return 0;
}
