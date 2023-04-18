//输入第一行包含四个整数 n,m,s,t分别代表点数，边数，源点，汇点。（n<=5000，m<=50000） 
//接下来 m行，每行四个整数ui,vi,wi,ci，分别代表第 i条边的起点，终点，流量限制，单位流量费用。
//现在你要求出当前网络的最大流，并且求出保证最大流时的最小花费 
//原理为EK+dij，但是就没有办法求最大费用最大流了，要求的话只能用spfa  
//这个算法可能不是正确的，如果不卡时间的话用spfa就好了 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll mincost=0,pre[mn],d[mn],ht[mn],
cnt=1,n,m,s,t,maxflow=0,h[mn];
//maxflow为最大流，mincost为最小花费  
struct w{ll z,v,to,next;}a[mn*2];
void add(ll x,ll y,ll z,ll k)
{
	a[++cnt]=w{z,k,y,h[x]};h[x]=cnt;
	a[++cnt]=w{0,-k,x,h[y]};h[y]=cnt;
}
struct ww//结构体式写法 
{
	ll x,d;
	friend bool operator<(ww a,ww b){return a.d>b.d;}//<为从大到小排列，>为从小到大排列 
};
bool dij(ll s,ll t)
{ll i,x,y;
	priority_queue<ww>q;
	for(i=1;i<=n;i++){d[i]=inf;pre[i]=0;}
	d[s]=0;
	q.push((ww){s,d[s]});
	while(!q.empty())
	{
		ww u=q.top();
		q.pop();
		x=u.x;
		if(u.d!=d[x])continue;
		if(x==t)break;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			ll tmp=a[i].v+ht[x]-ht[y];
			if(d[y]>d[x]+tmp&&a[i].z)
			{
				d[y]=d[x]+tmp;
				pre[y]=i;
				q.push((ww){y,d[y]});
			}
		}
	}
	if(d[t]<inf)return 1;
	else return 0;
}
void mcmf()
{ll i,p,del=inf;
	for(i=1;i<=n;i++)
        ht[i]=min(ht[i]+d[i],(ll)inf);
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
	mincost+=ht[t]*del;
}
void ek()
{
	while(dij(s,t))mcmf();
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
