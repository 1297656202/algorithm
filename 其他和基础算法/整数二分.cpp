//luoguP2249 �����13.��1������ 
//��ĳ������һ�����������������е�һ�γ��ֵ�λ��,���û�г������-1 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll ans,n,m,a[mn]={-1};
bool check(ll x,ll mid){return x<=a[mid];}
ll div(ll x)
{ll l=1,r=n,ret=0;
	while(l<=r)//���ֲ�����������������Сֵ,����෴�Ļ�����Ҫ�ı�l��r����˳�� 
	{ 
		ll mid=(l+r)/2;
		if(check(x,mid)){r=mid-1;ret=mid;}
		else l=mid+1;
	}
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	while(m--)
	{
		scanf("%lld",&x);
		y=div(x);
		if(a[y]==x)printf("%lld ",y);
		else printf("-1 ");
	} 
	return 0;
}
