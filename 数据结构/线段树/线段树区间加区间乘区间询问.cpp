���⣬��֪һ�����У�����Ҫ�����������ֲ�����
1����ĳ����ÿһ��������x
2����ĳ����ÿһ��������x
3�����ĳ����ÿһ�����ĺ�
ά�����������ǣ��ֱ��ʾ�˶��٣�mul���ͼӶ��٣�add���������ǼӵĻ��Ͱ�addֱ�Ӽ��������
��������ǳ˵Ļ��Ͱ�mul�����������ͬʱ��addҲ������������� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],mod,
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,add,mul,s;}a[mn*4];//�߶������鿪4�� 
void up(ll v)
{
	a[v].s=(a[v*2].s+a[v*2+1].s)%mod;
}
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	a[v].mul=1;
	a[v].add=0;
	if(l==r){a[v].s=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
	up(v);
}
void down(ll v)
{
	a[v*2].s=(a[v*2].s*a[v].mul+a[v].add*(a[v*2].b-a[v*2].a+1))%mod;
	a[v*2+1].s=(a[v*2+1].s*a[v].mul+a[v].add*(a[v*2+1].b-a[v*2+1].a+1))%mod;
	a[v*2].mul=(a[v*2].mul*a[v].mul)%mod;
	a[v*2+1].mul=(a[v*2+1].mul*a[v].mul)%mod;
	a[v*2].add=(a[v*2].add*a[v].mul+a[v].add)%mod;
	a[v*2+1].add=(a[v*2+1].add*a[v].mul+a[v].add)%mod;
	a[v].mul=1;
	a[v].add=0;
}
void add(ll v,ll l,ll r,ll x)
{
	if(a[v].b<l||a[v].a>r)return;
	if(l<=a[v].a&&r>=a[v].b)
	{
		a[v].s=(a[v].s+x*(a[v].b-a[v].a+1))%mod;
		a[v].add=(a[v].add+x)%mod;
		return ;
	}
	down(v);
	add(v*2,l,r,x);
	add(v*2+1,l,r,x);
	up(v);
}
void mul(ll v,ll l,ll r,ll x)
{
	if(r<a[v].a||l>a[v].b)return ;
	if(l<=a[v].a&&r>=a[v].b)
	{
		a[v].s=a[v].s*x%mod;
		a[v].add=(a[v].add*x)%mod;
		a[v].mul=a[v].mul*x%mod;
		return ;
	}
	down(v);
	mul(v*2,l,r,x);
	mul(v*2+1,l,r,x);
	up(v);
}
void ask(ll v,ll l,ll r)
{
	if(r<a[v].a||l>a[v].b)return ;
	if(l<=a[v].a&&r>=a[v].b){sum=(sum+a[v].s)%mod;return ;}
	down(v);
	ask(2*v,l,r);
	ask(2*v+1,l,r);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>mod;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(1,1,n);
	while(m--)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			mul(1,x,y,z);
		}
		else if(k==2)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			add(1,x,y,z);
		}
		else 
		{
			scanf("%lld%lld",&x,&y);
			sum=0;
			ask(1,x,y);
			printf("%lld\n",sum);
		}
	}
    return 0;
}
