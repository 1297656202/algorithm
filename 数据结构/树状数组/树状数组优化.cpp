#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long//////////////
#define inf 1e18
#define maxn 100005
#define ii inline
#define mod 9901
#define low(i) (i&(-i))
using namespace std;
ll ans=0,c[maxn],b[maxn],cnt=0,n,m,d,a[maxn],
h[maxn],bj[maxn];
void add(int x,int z)
{ll i,j,k;
	for(i=x;i<=n;i+=low(i))
            c[i]+=z; 
}
ll ask(int x)
{ll i,j,ans=0,k;
	for(i=x;i>0;i-=low(i))
	         ans+=c[i];
	return ans;
}
int main()
{
    ll s,k,t,r,l,te,x,y,len,i,j,z;
    cin>>n>>d;
    for(i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	b[i]=a[i];
    }
    sort(a+1,a+n+1);
    len=unique(a+1,a+n+1)-a-1;
    for(i=1;i<=n;i++)
    {
    	x=upper_bound(a+1,a+1+len,b[i]+d)-a-1;
    	y=lower_bound(a+1,a+1+len,b[i]-d)-a;
    	z=lower_bound(a+1,a+1+len,b[i])-a;
    	ll sum=((ask(x)-ask(y-1))%mod+mod)%mod;
    	ans=(ans+sum)%mod;
    	add(z,sum+1);
    }
    cout<<ans;
	return 0;
}
