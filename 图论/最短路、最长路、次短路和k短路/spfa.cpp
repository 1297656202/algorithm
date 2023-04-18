#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll used[mn],d[mn],cnt=0,
h[mn],bj[mn],n,m;
struct w{ll next,to,z;}a[mn*2];
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
ll spfa(ll s)
{ll i,x,y;
	queue<ll>q;
	for(i=1;i<=n;i++)
	{
		d[i]=inf;
		bj[i]=0;
	}
	d[s]=0;bj[s]=1;q.push(s);
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		bj[x]=0;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(d[y]>d[x]+a[i].z)
			{
				d[y]=d[x]+a[i].z;
				if(bj[y]==0)
				{
					q.push(y);
					bj[y]=1;
					used[y]++;
					if(used[y]>=n+1)return 0;
				}
			}
		}
	}
   return 1;
}
int main()
{
	ll x,y,i,j,k,z,s;
    cin>>n>>m>>s;
    for(i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
    }
    if(spfa(s))
	{
		for(i=1;i<=n;i++)
		printf("%lld ",d[i]);
    }
    else  cout<<"no solution"<<endl;
	return 0;
}
