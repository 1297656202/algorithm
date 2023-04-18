给定一个n个点m条边的无向图，图中可能存在重边和自环。
请你判断这个图是否是二分图。（n,m<=1e5）

通过二分图染色来判断图是否为二分图，复杂度为O（n+m）
特别注意：二分图 <=> 图中没有奇环 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],bj[mn],ans,cnt=0,n,m,p;
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;	
}
bool dfs(ll x,ll prt)
{ll i,y;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		if(bj[y]==bj[x])return 0;
		else if(bj[y]==0)
		{
			bj[y]=-bj[x];
			if(dfs(y,x)==0)return 0;
		}
	}
	return 1;
}
int main()
{
	ll x,y,z,i,j,k,t;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n;i++)
	if(bj[i]==0)
	{
		bj[i]=1;
		if(dfs(i,0)==0)//即图中有奇环，不是二分图 
		{
			cout<<"no";
			return 0;
		} 
	}
	//图中没有环或者只有偶环，则是二分图 
	cout<<"yes";
    return 0;
}
