//值得注意的是RMQ不仅可以维护最大/最小值，还可以维护区间gcd（都具有区间可加性质）
//当然这种区间可加性质的维护用线段树也是完全可以的  

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll a[mn],n,m,f[mn][20],f1[mn][20];
ll ask(ll l,ll r)
{ll x;
	x=(ll)(log(r-l+1)/log(2));
	return max(f[l][x],f[r-(1<<x)+1][x])-min(f1[l][x],f1[r-(1<<x)+1][x]); 
}
void st()
{ll i,j;
	for(i=1;i<=n;i++)f[i][0]=a[i];
		for(j=1;(1<<j)<=n;j++)
	    	for(i=1;i+(1<<j)-1<=n;i++)
	        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(i=1;i<=n;i++)f1[i][0]=a[i];
	for(j=1;(1<<j)<=n;j++)
	    for(i=1;i+(1<<j)-1<=n;i++)
	        f1[i][j]=min(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
	         
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	   scanf("%lld",&a[i]);
	st();
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",ask(x,y));
	}
	return 0;
}
