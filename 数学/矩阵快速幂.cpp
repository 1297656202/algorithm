��f[i]=f[i-1]+f[i-2],��f[n] 
��[f[i-1],f[i-2]]��Ϊһ���о���a����Ϊ2��2�У�Ҳ����f[i]���ڶ��ٸ�Ԫ֮�ͣ����ж����ж����У�
Ȼ����a��������ĳ��������ʹ��[f[i-1],f[i-2]]*a�������[f[i],f[i-1]]����[f[i-1]+f[i-2],f[i-1]]��
���a����Ϊ[1,1]
		   [1,0] 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 105
#define mod 1000000007
using namespace std;
ll ans,n,m;
struct ma
{
	ll a[100][100];//����Ĵ�Сȡ����m 
	ma operator * (const ma &c)
	{
		ma s;
		ll i,j,k;
		memset(s.a,0,sizeof(s.a));
		for(i=0;i<m;i++)//
			for(j=0;j<m;j++)//
				for(k=0;k<m;k++)//
					s.a[i][j]=(s.a[i][j]+a[i][k]*c.a[k][j]%mod)%mod;
		return s;
	}
	ma operator ^ (ll b)
	{
		ma s;ll i;
		memset(s.a,0,sizeof(s.a));
		for(i=0;i<m;i++)//
			s.a[i][i]=1;
		while(b!=0)
		{
			if(b%2!=0)s=s*(*this);
			(*this)=(*this)*(*this);
			b/=2;
		}
		return s;
	}
};
ma a;
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>m>>k;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
		scanf("%lld",&a.a[i][j]);
	a=a^k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%lld ",a.a[i][j]);
		printf("\n");
	}
    return 0;
}
