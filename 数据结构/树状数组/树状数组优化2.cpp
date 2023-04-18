#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long//////////////
#define inf 1e18
#define maxn 1205
#define ii inline
#define mod 1000000007
#define low(i) (i&(-i))
using namespace std;
ll ans=0,cnt=0,n,m,a[maxn],b[maxn],c[maxn],v[maxn],
f[maxn][maxn];
void add(int x,int z)
{ll i,j,k;
	for(i=x;i<=n;i+=low(i))
            c[i]+=z; 
}
ll ask(ll x,ll y)
{ll ret=0;
	while(x)
	{
		ret=(ret+f[x][y])%mod;
		x-=low(x);
	}
	return ret;
}
void add(ll x,ll y,ll z)
{
	while(x<=n)
	{
		f[x][y]=(f[x][y]+z)%mod;
		x+=low(x);
	}
}
int main()
{
    ll s,k,t,r,l,te,x,y,len,i,j,z;
    cin>>te;
    for(l=1;l<=te;l++)
	{
	memset(f,0,sizeof(f));
	cin>>n>>m;	
	for(i=1;i<=n;i++)
		{
		scanf("%lld",&a[i]);
        b[i]=a[i];
		}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=min(i+1,m);j++)
		if(j==1)add(a[i],1,1);
		else add(a[i],j,ask(a[i]-1,j-1));
	}
	printf("Case #%lld: %lld\n",l,ask(n,m));
	}
	return 0;
}
