#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long//////////////
#define inf 1e18
#define maxn 1005
#define ii inline
using namespace std;
ll ans=0,cnt=0,n,m,s,t,h[maxn],
v[maxn],f[maxn][1<<6],sta[maxn],status,vst[maxn][1<<6];
struct w{ll v,z,next;}a[maxn*40];
struct ww{ll x,y;};
queue<ww>q;
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].v=y;
	a[cnt].z=z;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void spfa()
{ww tmp,ne;ll i;
	while(q.empty()==0)
	{tmp=q.front();
	q.pop();
	vst[tmp.x][tmp.y]=0;	
	for(i=h[tmp.x];i;i=a[i].next)
	{ll v,situ;
		v=a[i].v;
		situ=tmp.y|sta[v];
		if(f[tmp.x][tmp.y]+a[i].z<f[v][situ])
		{
			f[v][situ]=f[tmp.x][tmp.y]+a[i].z;
			if(situ==tmp.y&&vst[v][situ]==0)
			{
				ne.x=v;
				ne.y=situ;
				q.push(ne);
				vst[v][situ]=1;
			}
		}
	}
	}
}
ll dp()
{ll i;
	ans=inf;
	for(i=0;i<=n+m;i++)
		ans=min(ans,f[i][status-1]);
	return ans;
}
int main()
{
    ll k,r,l,te,x,y,len,p,i,j,z;
    while(cin>>n>>m>>p)
    {
    	memset(h,0,sizeof(h));
    	memset(vst,0,sizeof(vst));
    	memset(sta,0,sizeof(sta));
    	cnt=0;
    	status=1<<(n+1);
    	for(i=0;i<=n+m;i++)
    		for(j=0;j<=status;j++)
    			f[i][j]=inf;
    	for(i=0;i<=n;i++)
    	{
    		sta[i]=1<<i;
    		f[i][sta[i]]=0;
    	}
    	for(i=1;i<=m+n;i++)
    	{
    		scanf("%lld",&v[i]);
    		add(0,i,v[i]);
    		add(i,0,v[i]);
    	}
    	for(i=0;i<p;i++)
    	{
    		scanf("%lld%lld%lld",&x,&y,&z);
    		add(x,y,z);
    		add(y,x,z);
    	}
    	ww tmp;
    	for(i=0;i<status;i++)
    	{
    		for(j=0;j<=n+m;j++)
    		{
    			if(((i&sta[j])==0)&&j<=n)continue;
    			for(k=i;k;k=(k-1)&i)
    			{
    				f[j][i]=min(f[j][i],f[j][k|sta[j]]+f[j][(i-k)|sta[j]]);
    			}
    			if(f[j][i]!=inf)
    			{
    				tmp.x=j;
    				tmp.y=i;
    				q.push(tmp);
    				vst[j][i]=1;
    			}
    		}
    		spfa();
    	}
    	printf("%lld\n",dp());
    }
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long//////////////
#define inf 1e18
#define maxn 205
#define ii inline
using namespace std;
ll ans=0,cnt=0,n,m,s,t,h[maxn],
v[maxn],f[maxn][1<<6],sta[maxn],status,g[maxn],
vst[maxn][1<<6];
struct w{ll v,z,next;}a[maxn*40];
struct ww{ll x,y;};
queue<ww>q;
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].v=y;
	a[cnt].z=z;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void spfa()
{ww tmp,ne;ll i;
	while(q.empty()==0)
	{tmp=q.front();
	q.pop();
	vst[tmp.x][tmp.y]=0;	
	for(i=h[tmp.x];i;i=a[i].next)
	{ll v,situ;
		v=a[i].v;
		situ=tmp.y|sta[v];
		if(f[tmp.x][tmp.y]+a[i].z<f[v][situ])
		{
			f[v][situ]=f[tmp.x][tmp.y]+a[i].z;
			if(situ==tmp.y&&vst[v][situ]==0)
			{
				ne.x=v;
				ne.y=situ;
				q.push(ne);
				vst[v][situ]=1;
			}
		}
	}
	}
}
bool check(ll state)
{ll i,sum=0;
	for(i=0;i<n;i++)
	{
		if(state&(1<<i))sum++;
		if(state&(1<<(n+i)))sum--;
	}
	return sum==0;
}
void dp()
{ll i,j;
	for(i=0;i<status;i++)
	{
	g[i]=inf;
	for(j=0;j<n+m;j++)
	g[i]=min(g[i],f[j][i]);
    }
    for(i=1;i<status;i++)
    {
    	if(check(i)==0)continue;
    	for(j=(i-1)&i;j;j=(j-i)&i)
    	{
    		if(check(j)==0)continue;
    		g[i]=min(g[i],g[j]+g[i-j]);
    	}
    }
    if(g[status-1]==inf)printf("No solution\n");
    else printf("%lld\n",g[status-1]);
}
int main()
{
    ll k,r,l,te,x,y,len,p,i,j,z;
    cin>>te;
    while(te--)
    {
    	cin>>n>>p>>k;
    	m=n-k;
    	n=k;
    	memset(h,0,sizeof(h));
    	memset(vst,0,sizeof(vst));
    	memset(sta,0,sizeof(sta));
    	cnt=0;
    	status=1<<(n*2);
    	for(i=0;i<n+m;i++)
    		for(j=0;j<status;j++)
    			f[i][j]=inf;
    	for(i=0;i<n;i++)
    	{
    		sta[i]=(1<<i);
    		f[i][sta[i]]=0;
    		sta[m+i]=1<<(n+i);
    		f[m+i][sta[m+i]]=0;
    	}
    	for(i=0;i<p;i++)
    	{
    		scanf("%lld%lld%lld",&x,&y,&z);
    		x--;y--;
    		add(x,y,z);
    		add(y,x,z);
    	}
    	ww tmp;
    	for(i=0;i<status;i++)
    	{
    		for(j=0;j<n+m;j++)
    		{
//    			if(((i&sta[j])==0)&&j<=n)continue;
    			for(k=i;k;k=(k-1)&i)
    			{
    				f[j][i]=min(f[j][i],f[j][k|sta[j]]+f[j][(i-k)|sta[j]]);
    			}
    			if(f[j][i]!=inf)
    			{
    				tmp.x=j;
    				tmp.y=i;
    				q.push(tmp);
    				vst[j][i]=1;
    			}
    		}
    		spfa();
    	}
    	dp();
    }
	return 0;
}
