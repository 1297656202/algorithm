����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի���
�����ж����ͼ�Ƿ��Ƕ���ͼ����n,m<=1e5��

ͨ������ͼȾɫ���ж�ͼ�Ƿ�Ϊ����ͼ�����Ӷ�ΪO��n+m��
�ر�ע�⣺����ͼ <=> ͼ��û���滷 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],bj[mn],ans,cnt=0,n,m,p;
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;	
}
bool dfs(ll x,ll prt)
{ll i,y;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		if(bj[y]==bj[x])return 0;
		else if(bj[y]==0)
		{
			bj[y]=-bj[x];
			if(dfs(y,x)==0)return 0;
		}
	}
	return 1;
}
int main()
{
	ll x,y,z,i,j,k,t;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n;i++)
	if(bj[i]==0)
	{
		bj[i]=1;
		if(dfs(i,0)==0)//��ͼ�����滷�����Ƕ���ͼ 
		{
			cout<<"no";
			return 0;
		} 
	}
	//ͼ��û�л�����ֻ��ż�������Ƕ���ͼ 
	cout<<"yes";
    return 0;
}
