#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll b[mn],
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,s;}a[mn*4];//线段树数组开4倍 
void up(ll v)
{
	a[v].s=a[v*2].s+a[v*2+1].s;
}
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	if(l==r){a[v].s=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
	up(v);
}
void add(ll v,ll x,ll y)
{
	if(a[v].b<x||a[v].a>x)return;
	if(a[v].b==a[v].a){a[v].s+=y;return ;}
	add(v*2,x,y);
	add(v*2+1,x,y);
	up(v);
}
void ask(ll v,ll l,ll r)
{
	if(r<a[v].a||l>a[v].b)return ;
	if(l<=a[v].a&&r>=a[v].b){sum+=a[v].s;return ;}
	ask(2*v,l,r);
	ask(2*v+1,l,r);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(1,1,n);
	while(m--)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			scanf("%lld%lld",&x,&y);
			add(1,x,y);
		}
		else 
		{
			scanf("%lld%lld",&x,&y);
			sum=0;
			ask(1,x,y);
			printf("%lld\n",sum);
		}
	}
    return 0;
}
