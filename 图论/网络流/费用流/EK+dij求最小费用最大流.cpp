//�����һ�а����ĸ����� n,m,s,t�ֱ���������������Դ�㣬��㡣��n<=5000��m<=50000�� 
//������ m�У�ÿ���ĸ�����ui,vi,wi,ci���ֱ����� i���ߵ���㣬�յ㣬�������ƣ���λ�������á�
//������Ҫ�����ǰ���������������������֤�����ʱ����С���� 
//ԭ��ΪEK+dij�����Ǿ�û�а취��������������ˣ�Ҫ��Ļ�ֻ����spfa  
//����㷨���ܲ�����ȷ�ģ��������ʱ��Ļ���spfa�ͺ��� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll mincost=0,pre[mn],d[mn],ht[mn],
cnt=1,n,m,s,t,maxflow=0,h[mn];
//maxflowΪ�������mincostΪ��С����  
struct w{ll z,v,to,next;}a[mn*2];
void add(ll x,ll y,ll z,ll k)
{
	a[++cnt]=w{z,k,y,h[x]};h[x]=cnt;
	a[++cnt]=w{0,-k,x,h[y]};h[y]=cnt;
}
struct ww//�ṹ��ʽд�� 
{
	ll x,d;
	friend bool operator<(ww a,ww b){return a.d>b.d;}//<Ϊ�Ӵ�С���У�>Ϊ��С�������� 
};
bool dij(ll s,ll t)
{ll i,x,y;
	priority_queue<ww>q;
	for(i=1;i<=n;i++){d[i]=inf;pre[i]=0;}
	d[s]=0;
	q.push((ww){s,d[s]});
	while(!q.empty())
	{
		ww u=q.top();
		q.pop();
		x=u.x;
		if(u.d!=d[x])continue;
		if(x==t)break;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			ll tmp=a[i].v+ht[x]-ht[y];
			if(d[y]>d[x]+tmp&&a[i].z)
			{
				d[y]=d[x]+tmp;
				pre[y]=i;
				q.push((ww){y,d[y]});
			}
		}
	}
	if(d[t]<inf)return 1;
	else return 0;
}
void mcmf()
{ll i,p,del=inf;
	for(i=1;i<=n;i++)
        ht[i]=min(ht[i]+d[i],(ll)inf);
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
	mincost+=ht[t]*del;
}
void ek()
{
	while(dij(s,t))mcmf();
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
