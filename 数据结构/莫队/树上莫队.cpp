#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 100005
using namespace std;
ll top=0,v[maxn],sum[maxn],s[maxn],h[maxn]={0},
d[maxn]={0},st[maxn],c[maxn],scc=0,dfn[maxn],
ans[maxn],belong[maxn],f[maxn][21]={0},sign=0,Ans=0,
kuai,maxx,minn,cnt=0,rt,tot=0,ge,n,m,l,r;
struct w{ll x,y,a,b,i;}q[maxn];
struct we{ll next,to;}a[maxn];
void add(ll x,ll y)
{
	cnt++;
	a[cnt].next=h[x];
	a[cnt].to=y;
	h[x]=cnt;
}
bool cmp(const w&a,const w&b)
{
	if(belong[a.x]==belong[b.x])return dfn[a.y]<dfn[b.y];
	return belong[a.x]<belong[b.x];
}
void dfs(ll x)
{ll i,y,k,bot=top;
	dfn[x]=++sign;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y!=f[x][0])
		{
			f[y][0]=x;
			d[y]=d[x]+1;
			dfs(y);
			if(top-bot>=kuai)
			{
				scc++;
				while(top!=bot)
				belong[st[top--]]=scc;
			}
		}
	}
	st[++top]=x;
}
ll lca(ll x,ll y)
{ll i;
	if(d[x]<d[y])swap(x,y);
	for(i=20;i>=0;i--)
	   if(f[x][i]&&d[f[x][i]]>=d[y])
	      x=f[x][i];
	if(x==y)return y;
	for(i=20;i>=0;i--)
	   if(f[x][i]&&f[x][i]!=f[y][i])
	   {
	   	x=f[x][i];
	   	y=f[y][i];
	   }
	return f[x][0];
}
void rev(ll x)
{
	if(v[x]==0)
	{
		v[x]=1;
		s[c[x]]++;
		if(s[c[x]]==1)Ans++;
	}
	else 
	{
		v[x]=0;
		s[c[x]]--;
		if(s[c[x]]==0)Ans--;
	}
}
void work(ll x,ll y)
{
	while(x!=y)
	{
		if(d[x]>d[y])
		{
		rev(x);
		x=f[x][0];
		}
		else 
		{
		rev(y);
		y=f[y][0];
		}
	}
}
int main()
{
	ll h,k,f1,f2,x,he=0,v,y,len,t,i,j,z;
	char ch;
	cin>>n>>m;
	kuai=(ll)(sqrt(n));
	for(i=1;i<=n;i++)
	   scanf("%lld",&c[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(x==0)rt=y;
		else if(y==0)rt=x;
		else {add(x,y);add(y,x);}
	}
	d[rt]=1;
	dfs(1);//what??
	scc++;
	if(top)
	{
	while(top)
	{
		belong[st[top--]]=scc;
	}
	}
	for(j=1;j<=20;j++)
	   for(i=1;i<=n;i++)
	      f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=m;i++)
	{
	    scanf("%lld%lld%lld%lld",&q[i].x,&q[i].y,&q[i].a,&q[i].b);	
	    if(dfn[q[i].x]>dfn[q[i].y])
	    swap(q[i].x,q[i].y);
	    q[i].i=i;
	}
	sort(q+1,q+m+1,cmp);
	t=lca(q[1].x,q[1].y);
	work(q[1].x,q[1].y);
	rev(t);
	ans[q[1].i]=Ans;
	if(s[q[1].a]&&s[q[1].b]&&q[1].a!=q[1].b)
	ans[q[1].i]--;
	rev(t);
	for(i=2;i<=m;i++)
	   {
	   	work(q[i-1].x,q[i].x);
	   	work(q[i-1].y,q[i].y);
	   	t=lca(q[i].x,q[i].y);
	   	rev(t);
	   	ans[q[i].i]=Ans;
	   	if(s[q[i].a]&&s[q[i].b]&&q[i].a!=q[i].b)
	   	ans[q[i].i]--;
	   	rev(t);
	   }
	   for(i=1;i<=m;i++)
	      printf("%lld\n",ans[i]);
    return 0;
}
