#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll b[mn],
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,add;}a[mn*4];//线段树数组开4倍 
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	if(l==r){a[v].add=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
}
void add(ll v,ll l,ll r,ll x)
{
	if(a[v].b<l||a[v].a>r)return;
	if(l<=a[v].a&&r>=a[v].b)
	{
		a[v].add+=x;
		return ;
	}
	add(v*2,l,r,x);
	add(v*2+1,l,r,x);
}
void ask(ll v,ll x)
{
	if(x<a[v].a||x>a[v].b)return ;
	ans+=a[v].add;
	if(a[v].a==a[v].b)return ;
	ask(2*v,x);
	ask(2*v+1,x);
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
			scanf("%lld%lld%lld",&x,&y,&z);
			add(1,x,y,z);
		}
		else 
		{
			scanf("%lld",&x);
			ans=0;
			ask(1,x);
			printf("%lld\n",ans);
		}
	}
    return 0;
}
