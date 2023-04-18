#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll ans=0,a[mn],f[mn],n,m;
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
	ll x,y,i,j,k,l,z;
	char ch; 
	cin>>n>>m;
	for(i=1;i<=n;i++)
	   scanf("%lld",&a[i]);
	while(m--)
	{
		scanf("%lld",&k);	
		if(k==1)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			add(f,x,z);
			add(f,y+1,-z);
		}
		else 
		{
			scanf("%lld",&x);
			ans=a[x]+ask(f,x);
			printf("%lld\n",ans);
		}
	}
    return 0;
}
