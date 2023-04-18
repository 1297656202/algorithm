#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll cnt=0,h[mn],bj[mn],n,m,d[mn];
struct w{ll next,to,z;}a[mn];
/*typedef pair<ll,ll>heap;
priority_queue<heap,vector<heap>,greater<heap> >q;*///pair类写法 
//priority_queue<ll>Q;//大根堆
//priority_queue<ll,vector<ll>,greater<ll> >p;//小根堆
struct ww//结构体式写法 
{
	ll x,d;
	friend bool operator<(ww a,ww b){return a.d>b.d;}//<为从大到小排列，>为从小到大排列 
};
priority_queue<ww>q;
void add(ll x,ll y,ll v)
{
	cnt++;
    a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=v;
	h[x]=cnt;
}
int main()
{
	ll x,y,z,l,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(i=1;i<=n;i++)
	d[i]=inf;
	d[1]=0;
	q.push((ww){1,d[1]});
	while(!q.empty())
	{
		ww u=q.top();
		q.pop();
		x=u.x;
		if(bj[x])continue;
		bj[x]=1;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(!bj[y]&&d[y]>d[x]+a[i].z)
			{
				d[y]=d[x]+a[i].z;
				q.push((ww){y,d[y]});
			}
		}
	}
    cout<<d[n];
	return 0;
}
