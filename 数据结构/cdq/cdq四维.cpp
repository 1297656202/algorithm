#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
#define bit(i) (i&(-i))
using namespace std;
ll c[maxn],ans=0,maxx,minn,cnt=0,tot=0,ge,n,m;
struct w{ll a,b,c,bj,d;}a[maxn],t1[maxn],t2[maxn],t[maxn];
bool cmp(const w&a,const w&b)
{
	return a.a<b.a||a.a==b.a&&a.b<b.b||a.a==b.a&&a.b==b.b&&a.c<b.c;
}
bool cmp2(const w&a,const w&b)
{
	return a.b<b.b||a.b==b.b&&a.c<b.c;
}
void add(ll x,ll y)
{ll i;
	for(i=x;i<=n;i+=bit(i))
	c[i]+=y;
}
ll ask(ll x)
{
	ll ans=0,i;
	for(i=x;i;i-=bit(i))
	ans+=c[i];
	return ans;
}
void cdq2(ll l,ll r)
{
	if(l==r)return ;
	ll mid=(l+r)/2;
	cdq2(l,mid);cdq2(mid+1,r);
	ll i=l,j=mid+1,p=l;
	w *a=t1,*t=t2;
	while(i<=mid||j<=r)
	{
		if(j>r||(i<=mid&&a[i].c<a[j].c))
		{
			if(a[i].bj==1)add(a[i].d,1);
			t[p++]=a[i++];
		}
		else
		{
			if(a[j].bj==0)ans+=ask(a[j].d);
			t[p++]=a[j++];
		}
		
	}
	for(i=l;i<=mid;i++)
	   if(a[i].bj)add(a[i].d,-1);
	for(i=l;i<=r;i++)a[i]=t[i];
}
void cdq(ll l,ll r)
{
	if(l==r){return ;}
	ll mid=(l+r)/2;
	cdq(l,mid);
	cdq(mid+1,r);
	ll i=l,j=mid+1,p=l;
	w *t=t1;
	while(i<=mid||j<=r)
	{
		if(j>r||(i<=mid&&a[i].b<a[j].b)){(t[p++]=a[i++]).bj=1;}
		else (t[p++]=a[j++]).bj=0;
	}
	for(i=l;i<=r;i++)a[i]=t[i];
	cdq2(l,r);
}
int main()
{
	ll num=0,h,f1,f2,x,y,k,len,t,i,j,z;
	char ch[10];
	cin>>n;
	for(i=1;i<=n;i++)
	   scanf("%lld",&a[i].b);
	for(i=1;i<=n;i++)
	   scanf("%lld",&a[i].c);
	for(i=1;i<=n;i++)
	   scanf("%lld",&a[i].d);
	cdq(1,n);
	cout<<ans;
	return 0;
}
