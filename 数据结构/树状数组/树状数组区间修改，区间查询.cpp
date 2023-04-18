#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll ans=0,a[mn],f[mn],g[mn],sum[mn],n,m;
ll low(ll x){return x&(-x);}
void add(ll c[],ll x,ll z)
{ll i,j,k;
	for(i=x;i<=n;i+=low(i))
            c[i]+=z; 
}
ll ask(ll c[],ll x)
{ll i,j,ans=0,k;
	for(i=x;i>0;i-=low(i))
	         ans+=c[i];
	return ans;
}
int main()
{
	ll x,y,i,j,k,z;
	char ch; 
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	   scanf("%lld",&a[i]);
	   sum[i]=sum[i-1]+a[i];
    }
	while(m--)
	{
		cin>>ch;	
	   	if(ch=='C')
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			add(f,x,z);
			add(f,y+1,-z);
			add(g,x,z*x);
			add(g,y+1,-z*(y+1));
		}
	   	else 
		{
			scanf("%lld%lld",&x,&y);
			ans=sum[y]+(y+1)*ask(f,y)-ask(g,y);
			ans-=sum[x-1]+x*ask(f,x-1)-ask(g,x-1);
			printf("%lld\n",ans);
	   	}
	}
    return 0;
}
