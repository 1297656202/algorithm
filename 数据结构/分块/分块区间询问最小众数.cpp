//给出一个长为n的数列，以及n个操作，操作涉及询问区间的最小众数。
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll pos[mn],a[mn],b[mn],
lx[mn],rx[mn],sum[mn],val[mn],f[505][505],
ans,n,m,t;
vector<ll>v[mn];
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
			pos[j]=i;
}
void pre(ll x)
{ll maxx=0,ret=0,i;
	memset(sum,0,sizeof(sum));
	for(i=lx[x];i<=n;i++)
	{
		sum[a[i]]++;
		ll p=pos[i]; 
		if(sum[a[i]]>maxx||(sum[a[i]]==maxx&&val[a[i]]<val[ret]))
		{
			ret=a[i];
			maxx=sum[a[i]];
		}
		f[x][p]=ret;
	}
}
ll cal(ll l,ll r,ll x)
{
	return upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
}
ll ask(ll l,ll r)
{ll ret,maxx=-inf,p=pos[l],q=pos[r],i;
	ret=f[p+1][q-1];
	maxx=cal(l,r,ret);
	for(i=l;i<=min(rx[p],r);i++)
	{
		ll k=cal(l,r,a[i]);
		if(k>maxx||(k==maxx&&val[ret]>val[a[i]]))
		{ret=a[i];maxx=k;}
	}
	if(p!=q)
	for(i=lx[q];i<=r;i++)
	{
		ll k=cal(l,r,a[i]);
		if(k>maxx||(k==maxx&&val[ret]>val[a[i]]))
		{ret=a[i];maxx=k;}
	}
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;t=200;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
   		b[i]=a[i];
	sort(b+1,b+n+1);
	ll tot=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)
	{
		ll tmp=lower_bound(b+1,b+tot+1,a[i])-b;
		val[tmp]=a[i];
		a[i]=tmp;
	}
	for(i=1;i<=n;i++)
		v[a[i]].push_back(i);
	bui();
	for(i=1;i<=t;i++)pre(i);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",val[ask(x,y)]);
	}
	return 0;
}
