#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define maxn 1005
#define ii inline
using namespace std;
ll bj[maxn][maxn],h[maxn],
my[maxn],vst[maxn],
ans=0,g[maxn][maxn],
cnt=0,tot=0,sign=0,n,m;
struct w{ll next,to;}a[maxn*maxn];
struct ww{ll tim,x,y,x2,y2;}b[maxn];
bool cmp(const ww&a,const ww&b){return a.tim<b.tim;}
ii void add(ll x,ll y)
{
	a[++cnt]={h[x],y};
	h[x]=cnt;
}
ii bool dfs(ll x)
{ll i;
	for(i=h[x];i;i=a[i].next)
		{
			ll y=a[i].to;
			if(vst[y]==0)
			{
			vst[y]=1;	
			if(my[y]==0||dfs(my[y]))
			{
				my[y]=x;
				return 1;
			}
			}
		}
	return 0;
}
ii ll hun()
{
	ll ans=0,i;
	memset(my,0,sizeof(my));
	for(i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	return ans;
}
int main()
{
	ll l,f1,f2,x,y,k,len,t=0,i,j,z,r;
	char ch;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(h,0,sizeof(h));
		cnt=0;
		char ch[5];
		ll c[5];
		for(i=1;i<=n;i++)
		{
		ch[0]=getchar();
		scanf("%c%c:%c%c%lld%lld%lld%lld",&ch[1],&ch[2],&ch[3],&ch[4],&b[i].x,&b[i].y,&b[i].x2,&b[i].y2);
		for(j=1;j<=4;j++)
		   {
		   c[j]=ch[j]-'0';
		   }
		b[i].tim=(c[1]*10+c[2])*60+c[3]*10+c[4];
	    }
	    sort(b+1,b+n+1,cmp);
	    for(i=1;i<=n;i++)
	       for(j=i+1;j<=n;j++)
	          if(b[i].tim+abs(b[i].x-b[i].x2)+abs(b[i].y-b[i].y2)+
			  abs(b[i].x2-b[j].x)+abs(b[i].y2-b[j].y)<b[j].tim)
	          	add(i,j);
	    cout<<n-hun()<<endl;
	}
	return 0;
}
