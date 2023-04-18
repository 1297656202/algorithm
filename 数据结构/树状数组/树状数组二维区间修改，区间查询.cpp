#include<bits/stdc++.h>
#define inf 100000000000000000
#define ll long long
#define y1 y3
using namespace std;
ll ans=0,a[2100][2100],b[2100][2100]={0},c[2100][2100]={0},d[2100][2100],
maxx,minn,cnt=0,ge,r,n,m;
ll low(ll x){return x&(-x);}
void add(ll x,ll y,ll z)
{ll i,j,k;
	for(i=x;i<=n;i+=low(i))
	   for(j=y;j<=m;j+=low(j))
        {
            a[i][j]+=z;
			b[i][j]+=z*x;
			c[i][j]+=z*y;
			d[i][j]+=z*x*y;			
		} 
}
ll ask(ll x,ll y)
{ll i,j,ans=0,k;
	for(i=x;i>0;i-=low(i))
	   for(j=y;j>0;j-=low(j))
	    {
	        ans+=a[i][j]*(x+1)*(y+1);
	        ans-=b[i][j]*(y+1);
	        ans-=c[i][j]*(x+1);
	        ans+=d[i][j];
		}
	return ans;
}
int main()
{
	ll x1,x2,y1,y2,z1,z2,f1,f2,x,he=0,v,y,len,t,i,j,k,l,r,z,p;
	char ch; 
	cin>>n>>m;
	while(scanf("%lld",&k)!=-1)
	{
		if(k==1)
		{
			scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&z);
			add(x1,y1,z);
			add(x2+1,y2+1,z);
			add(x1,y2+1,-z);
			add(x2+1,y1,-z);
		}
		else 
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			printf("%lld\n",ask(x2,y2)-ask(x1-1,y2)-ask(x2,y1-1)+ask(x1-1,y1-1));
		}
	}
    return 0;
}
