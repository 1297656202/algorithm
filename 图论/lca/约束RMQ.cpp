#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll h[mn],l[mn],tot=0,
f[mn][21],g[mn][21],d[mn], 
ans,cnt=0,n,m;
//ע��mnӦ��Ϊԭ���ڵ�����������tot��dfs���еĳ��ȣ����Ҳ��ԭ���ڵ������
//dfs������ÿ����ȥ��ʱ��ͼ������У�ÿ�δ���������֮���ּ���һ�� 
//l[i]��ʾ�ڵ�i��dfs���������λ�� 
//f[i][j]��ʾdfs��������i��ǰ��2��j�η������нڵ�������С����ȣ�g[i][j]��ʾ��С��f[i][j]����ԭ���ĸ��ڵ� 
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
void dfs(ll x,ll deep)//���dfs���� 
{ll i,y;
	l[x]=++tot;d[x]=deep;f[tot][0]=deep;g[tot][0]=x;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(l[y])continue;
		dfs(y,deep+1);
		f[++tot][0]=deep;
		g[tot][0]=x;
	}
}
void st()
{ll i,j;
	for(j=1;j<=log2(tot);j++)
		for(i=1;i<=tot-(1<<j)+1;i++)
		if(f[i][j-1]<f[i+(1<<(j-1))][j-1])
		{
			f[i][j]=f[i][j-1];
			g[i][j]=g[i][j-1];
		}
		else 
		{
			f[i][j]=f[i+(1<<(j-1))][j-1];
			g[i][j]=g[i+(1<<(j-1))][j-1];
		}
}
ll lca(ll x,ll y)
{ll k;
	x=l[x];y=l[y];
	if(x>y)swap(x,y);
	k=(ll)log2(y-x+1);
	if(f[x][k]<f[y-(1<<k)+1][k])return g[x][k];
    return g[y-(1<<k)+1][k];
}
ll dis(ll x,ll y)
{
	return d[x]+d[y]-2*d[lca(x,y)];
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	st();
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",lca(x,y));
	}
	return 0;
}
