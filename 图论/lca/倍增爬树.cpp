#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt=0,m;
ll f[100005][21],d[200005]={0},siz[200005]={0},h[200005]={0};
struct jjd
{	ll to,next;
}a[200005];
void add(ll x,ll y)
{	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(ll x,ll prt)
{ll i,y;
	f[x][0]=prt;
	for(i=h[x];i;i=a[i].next)
	{	y=a[i].to;
		if(y==prt)continue;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}
void st()
{ll i,j;
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(f[i][j-1]!=-1&&f[f[i][j-1]][j-1]!=-1)
				f[i][j]=f[f[i][j-1]][j-1];
}
ll lca(ll x,ll y)
{ll i;
	if(d[x]<d[y])swap(x,y);
	for(i=20;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	if(x==y)return y;
	for(i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	return f[x][0];
}
ll climb(ll x,ll dis)//��x��������dis��ô�� 
{ll i;
	for(i=20;i>=0;i--)
		if(d[x]-(1<<i)>=dis)x=f[x][i];
	return x;
}
ll dis(ll x,ll y) 
{
	return d[x]+d[y]-2*d[lca(x,y)];
}
bool check(ll x,ll s,ll t)//���x�Ƿ���s��t��·���� 
{
    if(dis(s,x)+dis(x,t)==dis(s,t))return 1;
    return 0;
}
/*bool check(ll x,ll s,ll t)//���x�Ƿ���s��t��·���ϵĵڶ���д�� 
{
	if(d[x]>=d[lca(s,t)]&&((lca(x,s)==x)||(lca(x,t)==x)))return 1;
	return 0;
}
�ж�x�Ƿ���s��t��·���ϣ�Ҫ������������
1��x��s��t��lca��
2��x��s �� x��t ��lca����x
*/
 
//������·���ཻʱ��һ����һ���ߵ�lca������һ������

int main()
{	ll i,x,y;
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{	scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	memset(f,-1,sizeof(f));
	d[1]=0;
	dfs(1,0);
	f[1][0]=-1;
	st();
	return 0;
}
