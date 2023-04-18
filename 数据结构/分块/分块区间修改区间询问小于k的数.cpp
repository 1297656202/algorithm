//给出一个长为 n 的数列，以及 n 个操作，操作涉及区间加法，询问区间内小于某个值 x 的元素个数。
//这个题目告诉我们，在每个分出的块里面可以嵌套数据结构，比如vector，set之类的 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll tag[mn],pos[mn],b[mn],lx[mn],rx[mn],sum[mn],
ans,n,m,t;
vector<ll>a[505];
void bui()
{ll i,j;
	for(i=1;i<=n/t;i++)
	{
		lx[i]=(i-1)*t+1;
		rx[i]=i*t;
	}
	t=n/t;
	if(rx[t]<n){t++;lx[t]=rx[t-1]+1;rx[t]=n;}
	for(i=1;i<=t;i++)
		for(j=lx[i];j<=rx[i];j++)
		{
			pos[j]=i;
			a[i].push_back(b[j]);
		}
}
void reset(ll x)
{ll i;
    a[x].clear();
    for(i=lx[x];i<=rx[x];i++)a[x].push_back(b[i]);
    sort(a[x].begin(),a[x].end());
}
void add(ll l,ll r,ll x)
{ll p=pos[l],q=pos[r],i;
	for(i=l;i<=min(rx[p],r);i++)b[i]+=x;
	reset(p);
	if(p!=q)
	{
		for(i=lx[q];i<=r;i++)b[i]+=x;
		reset(q);
	}
	for(i=p+1;i<=q-1;i++)tag[i]+=x;
}
ll ask(ll l,ll r,ll k)
{ll p=pos[l],q=pos[r],ret=0,i;
	for(i=l;i<=min(rx[p],r);i++)if(b[i]+tag[p]<k)ret++;
	if(p!=q)
	for(i=lx[q];i<=r;i++)if(b[i]+tag[q]<k)ret++;
	for(i=p+1;i<=q-1;i++)
	ret+=lower_bound(a[i].begin(),a[i].end(),k-tag[i])-a[i].begin();
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;t=sqrt(n);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(); 
	for(i=1;i<=t;i++)
		sort(a[i].begin(),a[i].end());
	for(i=1;i<=n;i++)//原题正好是n个操作
	{
		scanf("%lld%lld%lld%lld",&k,&x,&y,&z);
		if(k==0)add(x,y,z);
		else printf("%lld\n",ask(x,y,z*z));//原题是询问<z*z的数字有多少 
	}
	return 0;
}
