//����һ����Ϊ n �����У��Լ� n �������������漰���俪����������͡�
//���������ʾ���ֿ�ܶ�ʱ��������߶���һ������һ���������������Լ���ʱ�临�Ӷ� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll tag[mn],pos[mn],a[mn],
lx[mn],rx[mn],sum[mn],vis[mn],
ans,n,m,t;
void bui()
{ll i,j;
	for(i=1;i<=n/t;i++)
	{
		lx[i]=(i-1)*t+1;
		rx[i]=i*t;
	}
	t=n/t;
	if(rx[t]<n){t++;lx[t]=rx[t-1]+1;rx[t]=n;}
	for(i=1;i<=t;i++)
		for(j=lx[i];j<=rx[i];j++)
		{
			pos[j]=i;
			sum[i]+=a[j];
		} 
}
void cal(ll x)
{ll i; 
	if(vis[x])return ;
	vis[x]=1;sum[x]=0;
	for(i=lx[x];i<=rx[x];i++)
	{
		a[i]=sqrt(a[i]);
		sum[x]+=a[i];
		if(a[i]>1)vis[x]=0;
	}
}
void change(ll l,ll r)
{ll p=pos[l],q=pos[r],i;
	if(p==q)
	{
		for(i=l;i<=r;i++)
		{
			sum[p]-=a[i];
            a[i]=sqrt(a[i]);
            sum[p]+=a[i];
		}
		return ;
	}
	for(i=p+1;i<=q-1;i++)cal(i);
	for(i=l;i<=rx[p];i++)
	{
		sum[p]-=a[i];
        a[i]=sqrt(a[i]);
        sum[p]+=a[i];
	}
	for(i=lx[q];i<=r;i++)
	{
		sum[q]-=a[i];
        a[i]=sqrt(a[i]);
        sum[q]+=a[i];
	}
}
ll ask(ll l,ll r)
{ll p=pos[l],q=pos[r],ret=0,i;
	if(p==q)
	{
		for(i=l;i<=r;i++)ret+=a[i];
		return ret;
	}
	for(i=p+1;i<=q-1;i++)ret+=sum[i];
	for(i=l;i<=rx[p];i++)ret+=a[i];
	for(i=lx[q];i<=r;i++)ret+=a[i];
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;t=sqrt(n)+1;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	bui();
	for(i=1;i<=n;i++)//ԭ��������n������ 
	{
		scanf("%lld%lld%lld%lld",&k,&x,&y,&z);//zû���� 
		if(k==0)change(x,y);
		else printf("%lld\n",ask(x,y));
	}
	return 0;
}
