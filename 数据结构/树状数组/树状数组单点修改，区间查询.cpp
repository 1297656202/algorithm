//��״����c[i],i�ǲ��ܵ���0�ģ������i����0����ʹ��������ƽ�� 
//low(x)��Ϊx���������ұߵ�1��Ӧ��ֵ 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll ans=0,a[mn],c[mn],n,m;
ll low(ll x){return x&(-x);}
void add(ll c[],ll x,ll z)
{ll i;
	for(i=x;i<=n;i+=low(i))
        c[i]+=z;
}
ll ask(ll c[],ll x) 
{ll i,ret=0;
	for(i=x;i>0;i-=low(i))
	    ret+=c[i];
	return ret;
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	   scanf("%lld",&a[i]);
	   add(c,i,a[i]);
    }
	while(m--)
	{
		scanf("%lld",&k);	
		if(k==1)
		{
			scanf("%lld%lld",&x,&z);
			add(c,x,z);
		}
		else
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask(c,y)-ask(c,x-1));
		}
	}
    return 0;
}
