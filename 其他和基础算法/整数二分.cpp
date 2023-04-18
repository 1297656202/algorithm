//luoguP2249 【深基13.例1】查找 
//求某个数在一个单调不减的序列中第一次出现的位置,如果没有出现输出-1 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll ans,n,m,a[mn]={-1};
bool check(ll x,ll mid){return x<=a[mid];}
ll div(ll x)
{ll l=1,r=n,ret=0;
	while(l<=r)//二分查找求满足条件的最小值,如果相反的话则需要改变l和r语句的顺序 
	{ 
		ll mid=(l+r)/2;
		if(check(x,mid)){r=mid-1;ret=mid;}
		else l=mid+1;
	}
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	while(m--)
	{
		scanf("%lld",&x);
		y=div(x);
		if(a[y]==x)printf("%lld ",y);
		else printf("-1 ");
	} 
	return 0;
}
