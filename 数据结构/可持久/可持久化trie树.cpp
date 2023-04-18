#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
using namespace std;
ll root[maxn],ch[maxn][2],
h[maxn]={0},d[maxn],s[maxn],f[maxn][20],ans=0,v[maxn],
cnt=0,tot=0,sign=0,ge,n,m;
struct w{ll next,to;}a[maxn*2];
void add(ll x,ll y)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
ll ins(ll x,ll c)
{ll tmp,y,i;
	tmp=y=++tot;
	for(i=15;i>=0;i--)
	{
		ch[y][0]=ch[x][0];
		ch[y][1]=ch[x][1];
		s[y]=s[x]+1;
		ll t=(c>>i)&1;
		x=ch[x][t];
		ch[y][t]=++tot;
		y=ch[y][t];
	}
	s[y]=s[x]+1;
	return tmp;
}
void dfs(ll x,ll deep)
{ll i,y;
	d[x]=deep;
	root[x]=ins(root[f[x][0]],v[x]);
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==f[x][0])continue;
		f[y][0]=x;
		dfs(y,deep+1);
	}
}
ll lca(ll x,ll y)
{	ll i,j;
	if(d[x]<d[y])swap(x,y);
	for(i=15;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	if(x==y)return y;
	for(i=15;i>=0;i--)
		if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	return f[x][0];
}
ll ask(ll x,ll y,ll z,ll c)
{ll ans=0,i;
	for(i=15;i>=0;i--)
	{
		ll t=(c>>i)&1;
		if(s[ch[x][!t]]+s[ch[y][!t]]-2*s[ch[z][!t]]>0)
		{
			x=ch[x][!t];
			y=ch[y][!t];
			z=ch[z][!t];
			ans+=(1<<i);
		}
		else
		{
			x=ch[x][t];
			y=ch[y][t];
			z=ch[z][t];
		}
	}
	return ans;
}
int main()
{
	ll c,h,f1,he=0,f2,x,y,k,len,t,i,j,z,l,r;
	char ch;
	while(cin>>n>>m)
	{
	for(i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(i=1;i<=n-1;i++)
	   {
	   	scanf("%lld%lld",&x,&y);
	   	add(x,y);
	   	add(y,x);
	   }
	dfs(1,1);
	for(j=1;j<=15;j++)
		for(i=1;i<=n;i++)
			if(f[i][j-1]!=-1&&f[f[i][j-1]][j-1]!=-1)
				f[i][j]=f[f[i][j-1]][j-1];
	while(m--)
	{
		scanf("%lld%lld%lld",&x,&y,&c);
		z=lca(x,y);
		printf("%lld\n",max(ask(root[x],root[y],root[z],c),c^v[z]));
	}
	}
	return 0;
}
