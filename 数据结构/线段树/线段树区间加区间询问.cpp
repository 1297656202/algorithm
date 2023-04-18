已知一个数列，你需要进行下面两种操作：
1.	将某区间每一个数加上 k。
2.	求出某区间每一个数的和。
即为区间修改区间询问，如果为单点操作将区间收缩为单点即可 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,add,s;}a[mn*4];//线段树数组开4倍 
void up(ll v)
{
	a[v].s=a[v*2].s+a[v*2+1].s;
}
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	if(l==r){a[v].s=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
	up(v);
}
void down(ll v)
{
	if(a[v].add)
	{
		a[v*2].s+=a[v].add*(a[v*2].b-a[v*2].a+1);
		a[v*2+1].s+=a[v].add*(a[v*2+1].b-a[v*2+1].a+1);
		a[v*2].add+=a[v].add;
		a[v*2+1].add+=a[v].add;
		a[v].add=0;
	}
}
void add(ll v,ll l,ll r,ll x)
{
	if(a[v].b<l||a[v].a>r)return;
	if(l<=a[v].a&&r>=a[v].b)
	{
		a[v].s+=x*(a[v].b-a[v].a+1);
		a[v].add+=x;
		return ;
	}
	down(v);
	add(v*2,l,r,x);
	add(v*2+1,l,r,x);
	up(v);
}
void ask(ll v,ll l,ll r)
{
	if(r<a[v].a||l>a[v].b)return ;
	if(l<=a[v].a&&r>=a[v].b){sum+=a[v].s;return ;}
	down(v);
	ask(2*v,l,r);
	ask(2*v+1,l,r);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(1,1,n);
	while(m--)
	{
		scanf("%lld",&k);
		if(k==1)
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
