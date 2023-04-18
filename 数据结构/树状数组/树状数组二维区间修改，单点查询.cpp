#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1005
#define y1 y3
using namespace std;
ll ans=0,c[mn][mn]={0},p,
n,m;
ll low(ll x){return x&(-x);}
void add(ll x,ll y,ll z)
{ll i,j;
	for(i=x;i<=n;i+=low(i))
	   for(j=y;j<=m;j+=low(j))
        	c[i][j]+=z;
}
ll ask(ll x,ll y)
{ll i,j,ans=0;
	for(i=x;i>0;i-=low(i))
	   	for(j=y;j>0;j-=low(j))
	    	ans+=c[i][j];
	return ans;
}
int main()
{
	ll x1,y1,x2,y2,t,x,y,i,j,k,z;
	char ch[10];
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&p);
		memset(c,0,sizeof(c));
		while(p--)
		{
			scanf("%s",&ch);
			if(ch[0]=='C')
			{
				scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&z);
				add(x1,y1,z);
				add(x1,y2+1,-z);
				add(x2+1,y1,-z);
				add(x2+1,y2+1,z);
			}
			else 
			{
				scanf("%lld%lld",&x,&y);
				printf("%lld\n",ask(x,y));
			}
		}
		printf("\n");
	}
    return 0;
}
