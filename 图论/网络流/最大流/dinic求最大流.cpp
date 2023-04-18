//dinic���۸��Ӷȸ���isap��ֻ�ǵ�����������룬���Ծ���ʹ��isap 
//n,m,s,t�ֱ��ʾ��ĸ���������ߵĸ�����Դ����š������š�n<=200,m<=5000 
//����������������dinic�������Ż������Ӷ�ΪO(n*n*m)
//����һ������£����Ӷȶ�û��ô�ߣ��ܶ�ʱ����Խ�����Ϊ��O(n*m) 
//���⣬1��λ��Ȩ��dinic���Ӷ�ΪO(n*sqrt(e)) 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],cur[mn],
cnt=1,ans=0,n,m,s,t;//ע�������cnt�Ǵ�1��ʼ�ģ�����Ŵ�2��ʼ��������2,3���ű߲���һ�� 
struct w{ll next,to,z;}a[mn];//ע��Ҫ������������������������˫��� 
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};h[x]=cnt;
	a[++cnt]=(w){h[y],x,0};h[y]=cnt;
}
ll bfs()
{ll i,x,y;
	queue<ll>q;
	q.push(s);
	for(i=1;i<=n;i++)d[i]=0; 
	d[s]=1;
	while(q.empty()==0)
	{
		x=q.front();q.pop();
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(a[i].z>0&&d[y]==0)
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return d[t];
}
ll dfs(ll x,ll flow)
{ll y;
	if(x==t||flow==0)return flow;
	ll used=0;
	for(ll &i=cur[x];i;i=a[i].next)//���Ż� 
	{
		y=a[i].to;
		if(a[i].z&&d[x]+1==d[y])
		{
			ll mi=dfs(y,min(flow-used,a[i].z));
			a[i].z-=mi;a[i^1].z+=mi;used+=mi;
			if(used==flow)return used;
		}
	}
	if(used==0)d[x]=0;
	return used;
}
ll dinic()
{
	ll maxflow=0,i,dis;
	while(bfs())
	{
		for(i=1;i<=n;i++)cur[i]=h[i];
		while(dis=dfs(s,inf))maxflow+=dis;
	}
	return maxflow;
} 
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	printf("%lld\n",dinic());
	return 0;
}
