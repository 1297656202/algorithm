���������������ô��С��Ŀ��б������߶�����������

�������磺����������������е�һ����Ҫ���������һԴ��Ϊs���Ϊt��������G=(V,E)��f��G�е�һ������
���Զ����u,v��ʣ������Gf(u,v)=c(u,v)-f(u,v)���ɴ˶����������Gf(V,Ef)�� 

���б� (x,y)���ڲ��������в����� x �� y ��·����
����� (x,y)���ڲ��������� S �ܵ� x �� y�ܵ� T��

��С��Ŀ��бߣ���ĳһ����С��������ıߡ�
��Ҫ������
1. ������
2. �ڲ����������Ҳ�����㵽�����·����

�󷨣�
�ڲ���������tarjan��SCC�����������ͬһSCC��˵�����������д�����㵽�����·����
���ڸñ����������ķ����һ�������ڲ��������У��������������㵽�����·���ṹ��SCC��

��С��ı���ߣ�����������Ϊ0�ıߣ���һ������С���еıߡ�����ߵ���һ�����������������������������ıߡ�
��Ҫ������
1. ������
2. ����������Դ���ܵ���㣬�����ܵ���㡣

�󷨣�
�ڲ��������ϴ�Դ�㿪ʼdfs���ӻ�㿪ʼ����dfs����ǵ���ĵ㣬Ȼ��ö���������жϼ��ɡ�
��������бߣ��Ѿ�����SCC��ֱ���ж�����Ƿ���Դ����ͬһSCC���ҳ����Ƿ�������ͬһSCC�м��ɡ�
����Ϊʲô�����㷨�ǵȼ۵ģ�����Դ�㵽���һ������������һ��������㵽Դ�������·�����ȼ۵�֤��

���⣺P4126
�ȸ���һ����С��ģ�ͣ���ÿ����ѯ�����Ƿ�Ϊ���бߺͱ���ߣ������1���������0 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll d[mn],h[mn],gap[mn],cur[mn],
low[mn],dfn[mn],in[mn],stk[mn],
scc[mn],sign=0,top=0,sum=0,
cnt=1,ans=0,n,m,s,t,maxflow;//ע�������cnt�Ǵ�1��ʼ�ģ�����Ŵ�2��ʼ��������2,3���ű߲���һ�� 
struct w{ll x,next,to,z;}a[mn];
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){x,h[x],y,z};
	h[x]=cnt;
}
void bfs()
{ll i,x,y;
	memset(d,-1,sizeof(d));
	memset(gap,0,sizeof(gap));
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
{ll i,y;
	if(x==t){maxflow+=flow;return flow;}
	ll used=0;
	for(i=cur[x];i;i=a[i].next)//cur[]��Ϊ���Ż� 
	{
		cur[x]=i;
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
{
	maxflow=0;
	bfs();
	while(d[s]<n){memcpy(cur,h,sizeof(h));dfs(s,inf);}
	return maxflow;
}
void tarjan(ll x)//����ͼ��ǿ��ͨ���� 
{ll i,y;
	dfn[x]=++sign;
	low[x]=sign;
	stk[++top]=x;
	in[x]=1;
	for(i=h[x];i;i=a[i].next)
	if(a[i].z)//����Ҫ����ʣ��������Ҳ�����ڲ���������  
	{
		y=a[i].to;
		if(dfn[y]==0)
		{
	   		tarjan(y);
	   		low[x]=min(low[x],low[y]);
	   	}
		else if(in[y]==1)low[x]=min(low[x],dfn[y]);
	}
    if(low[x]==dfn[x])
    {
		sum++; 
    	do
		{
			y=stk[top--];	
			scc[y]=sum;//scc[]Ϊ�ڵ������������ĸ���  
			in[y]=0;
       	}while(x!=y);
    }
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
		add(y,x,0);
	}
	ll flow=isap();
	for(i=1;i<=n;i++)
	if(scc[i]==0)tarjan(i);
	for(i=2;i<=cnt;i+=2)
	{
		x=a[i].x,y=a[i].to;
		if(a[i].z==0&&scc[x]!=scc[y])
		{
			printf("1 ");
			if(scc[x]==scc[s]&&scc[y]==scc[t])printf("1");
			else printf("0");
		}
		else printf("0 0");
		printf("\n");
	}
	return 0;
}
