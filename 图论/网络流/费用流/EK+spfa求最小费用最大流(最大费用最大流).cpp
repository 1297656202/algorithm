//�����һ�а����ĸ����� n,m,s,t�ֱ���������������Դ�㣬��㡣��n<=5000��m<=50000�� 
//������ m�У�ÿ���ĸ�����ui,vi,wi,ci���ֱ����� i���ߵ���㣬�յ㣬�������ƣ���λ�������á�
//������Ҫ�����ǰ���������������������֤�����ʱ����С���� 
//ԭ��ΪEK+spfa���������������ֻ��Ҫ����λ��������ȡ�������߽�spfa��Ϊ���· 
//spfa���Լ���SLF�Ż���LLL�Ż��ô��������ӿ��ٶ� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll bj[mn],mincost=0,pre[mn],d[mn],
cnt=1,n,m,s,t,maxflow=0,h[mn];
//maxflowΪ�������mincostΪ��С����  
struct w{ll z,v,to,next;}a[mn*2];
void add(ll x,ll y,ll z,ll k)
{
	a[++cnt]=w{z,k,y,h[x]};h[x]=cnt;
	a[++cnt]=w{0,-k,x,h[y]};h[y]=cnt;
}
bool spfa(ll s,ll t)
{ll i,x,y;
	queue<ll>q;
	for(i=1;i<=n;i++){d[i]=inf;bj[i]=0;pre[i]=0;}
	q.push(s);
	d[s]=0;
	bj[s]=1;
	while(q.empty()==0)
	{
		x=q.front();
	 	q.pop();
	 	bj[x]=0;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(a[i].z&&d[x]+a[i].v<d[y])
			{
				d[y]=d[x]+a[i].v;
				pre[y]=i;
				if(bj[y]==0)
				{
					bj[y]=1;
					q.push(y);
				}
			}
		}
	}
	if(d[t]<inf)return 1;
	else return 0;
}
void mcmf()
{ll i,p,del=inf;
	for(i=t;i!=s;i=a[p^1].to)
	{
		p=pre[i];
		del=min(del,a[p].z);
	}
	for(i=t;i!=s;i=a[p^1].to)
	{
		p=pre[i];
		a[p].z-=del;
		a[p^1].z+=del;
	}
	maxflow+=del;
	mincost+=d[t]*del;
}
void ek()
{
	while(spfa(s,t))mcmf();
}
int main()
{
	ll x,y,k,i,j,z;
	char ch;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		ll cost;
		scanf("%lld%lld%lld%lld",&x,&y,&z,&cost);
		add(x,y,z,cost);
	}
	ek();
	cout<<maxflow<<" "<<mincost<<endl;
	return 0;
}
