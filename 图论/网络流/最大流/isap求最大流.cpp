//n,m,s,t�ֱ��ʾ��ĸ���������ߵĸ�����Դ����š������š�n<=200,m<=5000 
//����������������ISAP����GAP�Ż��Լ����Ż������Ӷ�ΪO(n*n*m)
//����һ������£����Ӷȶ�û��ô�ߣ��ܶ�ʱ����Խ�����Ϊ��O(n*m) 
//���⣬1��λ��Ȩ��dinic��ISAP�����Ӷ�ΪO(n*sqrt(e)) 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],gap[mn],cur[mn],
cnt=1,ans=0,n,m,s,t,maxflow;//ע�������cnt�Ǵ�1��ʼ�ģ�����Ŵ�2��ʼ��������2,3���ű߲���һ�� 
struct w{ll next,to,z;}a[mn];//ע��Ҫ������������������������˫��� 
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};h[x]=cnt;
	a[++cnt]=(w){h[y],x,0};h[y]=cnt;
}
void bfs()
{ll i,x,y;
	for(i=1;i<=n;i++){d[i]=-1;gap[i]=0;}
	d[t]=0;gap[0]=1;
	queue<ll>q;
	q.push(t);
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(d[y]!=-1)continue;
			q.push(y);
			d[y]=d[x]+1;
			gap[d[y]]++;
		}
	}
}
ll dfs(ll x,ll flow)
{ll y;
	if(x==t){maxflow+=flow;return flow;}
	ll used=0;
	for(ll &i=cur[x];i;i=a[i].next)//cur[]��Ϊ���Ż� 
	{
		y=a[i].to;
		if(a[i].z&&d[y]+1==d[x])
		{
			ll mi=dfs(y,min(a[i].z,flow-used));
			if(mi){a[i].z-=mi;a[i^1].z+=mi;used+=mi;}
			if(used==flow)return used;
		}
	}
	if(--gap[d[x]]==0)d[s]=n+1;
	d[x]++;gap[d[x]]++;
	return used;
}
ll isap()
{ll i;
	maxflow=0;
	bfs();
	while(d[s]<n){for(i=1;i<=n;i++)cur[i]=h[i];dfs(s,inf);}
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
	printf("%lld\n",isap());
	return 0;
}
