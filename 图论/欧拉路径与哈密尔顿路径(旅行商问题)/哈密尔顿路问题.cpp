Hamilton·���Ķ�����1��n���ز�©�ؾ���ÿ����ǡ��һ�Ρ�
����Ϊ����һ���ڽӾ����������Hamilton·�������������������յ���㣩
��ŵĴ������£������Ҫ�Ż��Ļ��͸ĳ�ǰ���� 
���Ҫ���������·��,����������ֱ������,��ʵ���ǿ�����״ѹ�ķ�ʽȥ���
(��https://blog.csdn.net/qq_36306833/article/details/121872050 E: ��·����) 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define maxn 1005
#define ii inline
using namespace std;
ll bj,vst[maxn],prt[maxn],a[maxn][maxn],s,t=0,sum=0,ans[maxn],cnt=0,
tot=0,sign=0,n,m,c[maxn],num=0;
void dfs(ll i,ll k)
{ll j;
	if(k==n){bj=1;sum++;return;}
	for(j=1;j<=n;j++)
		if(a[i][j]==1&&vst[j]==0)
		{
			vst[j]=1;
			dfs(j,k+1);
			vst[j]=0;
		}
}
int main()
{
	ll te,x,y,k,len,i,j,z;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	bj=0;
	for(i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		vst[i]=1;
		dfs(i,1);
	}
	if(bj==0)cout<<0;
	else cout<<sum;
	return 0;
}
