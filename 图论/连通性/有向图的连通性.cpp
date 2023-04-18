#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long inf=100000000;
ll he[5005],f[5005],belong[5005],//belong[]指的是这个节点属于哪个块 
sum=0,top=0,in[5005],d[5005],s[5005],
son=0,ans=0,low[5005],sign=0,dfn[5005],
prt[5005],cnt=0,h[5005]={0},n,m,t;
struct w{ll next,to;}a[1000005];
void add(ll x,ll y)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(ll x)//有向图求强联通分量 
{ll i,y;
	dfn[x]=++sign;
	low[x]=sign;
	s[++top]=x;
	in[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(dfn[y]==0)
		{
	   		dfs(y);
	   		low[x]=min(low[x],low[y]);
	   	}
		else if(in[y]==1)low[x]=min(low[x],dfn[y]);
	}
    if(low[x]==dfn[x])
    {
		sum++; 
    	do
		{
			y=s[top--];	
			he[sum]++;//没用 
			belong[y]=sum;
			f[sum]=min(f[sum],y);//没用 
			in[y]=0;
       	}while(x!=y);
    }
}
void solve()
{ll i,j,minn=inf,maxx=-inf,k;
	for(i=1;i<=n;i++)//注意，这一步容易忘，因为原图不一定保证完全的联通  
	   if(dfn[i]==0)dfs(i);
	for(i=1;i<=sum;i++)
	if(maxx<he[i]||(maxx==he[i]&&minn>f[i]))
	{
	    maxx=he[i];
	    minn=f[i];
	    k=i;
	}
	cout<<maxx<<endl;
	for(i=1;i<=n;i++)
	if(belong[i]==k)
	cout<<i<<" ";
}
int main()
{
	ll bj=0,x,y,maxx=-inf,w,t,l,minn=inf,he=0,len,i,j,k,z,p;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	    f[i]=inf;
	for(i=1;i<=m;i++)
	{
	    cin>>x>>y>>z;
	    if(z==1){add(x,y);}
	    if(z==2){add(x,y);add(y,x);}
	}
	solve();
	return 0;
}
