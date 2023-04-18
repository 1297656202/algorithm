#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long//////////////
#define inf 1e18
#define maxn 250005///////////////
#define ii inline
using namespace std;
ll ans=0,v[maxn],tot=0,cnt=0,sign=0,st[maxn],n,m,s,t,d[maxn],
h[maxn],g[maxn],dfn[maxn],p[maxn],f[maxn][21];
struct w{ll next,to,z;}a[maxn*2];
bool cmp(ll x,ll y){return dfn[x]<dfn[y];}
void add(ll x,ll y,ll z)
{
	if(x==y)return ;
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
void dfs(ll x,ll prt)
{	ll i,y;
	f[x][0]=prt;
	dfn[x]=++sign;
	for(i=h[x];i;i=a[i].next)
	{	y=a[i].to;
		if(y==prt)continue;
		d[y]=d[x]+1;
		v[y]=min(v[x],a[i].z);
		dfs(y,x);
	}
}
void ST()
{	ll i,j;
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(f[i][j-1]!=-1&&f[f[i][j-1]][j-1]!=-1)
				f[i][j]=f[f[i][j-1]][j-1];
}
ll lca(ll x,ll y)
{	ll i,j;
	if(d[x]<d[y])swap(x,y);
	for(i=20;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	if(x==y)return y;
	for(i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	return f[x][0];
}
void dp(ll x)
{ll i;
	g[x]=v[x];
	ll tmp=0;
	for(i=h[x];i;i=a[i].next)
	{
		dp(a[i].to);
		tmp+=g[a[i].to];
	}
	h[x]=0;
	if(tmp==0)g[x]=v[x];
	else if(tmp<g[x])g[x]=tmp;
}
int main()
{
    ll k,r,l,te,x,y,len,i,j,z;
    cin>>n;
    for(i=1;i<n;i++)
    {
    	scanf("%lld%lld%lld",&x,&y,&z);
    	add(x,y,z);
    	add(y,x,z);
    }
    memset(f,-1,sizeof(f));
    v[1]=inf;
    d[1]=0;
    dfs(1,0);
    ST();
    cnt=0;
    memset(h,0,sizeof(h));
    cin>>m;
    while(m--)
    {
    	scanf("%lld",&k);
    	for(j=1;j<=k;j++)
    		scanf("%lld",&p[j]);
    	sort(p+1,p+k+1,cmp);
		tot=1;ll top=0;
		for(j=2;j<=k;j++)
			if(lca(p[tot],p[j])!=p[tot])p[++tot]=p[j];
		st[++top]=1;
		cnt=0;///////////
		for(i=1;i<=tot;i++)
		{
			ll lc=lca(p[i],st[top]);
			while(1)
			{
				if(d[st[top-1]]<=d[lc])
				{
				add(lc,st[top--],0);	
				if(st[top]!=p[i])st[++top]=lc;
				break;
				}
				add(st[top-1],st[top],0);
				top--;
			}
			if(st[top]!=p[i])st[++top]=p[i];
		}	
		while(--top)add(st[top],st[top+1],0);
		dp(1);
		printf("%lld\n",g[1]);
    }
	return 0;
}
