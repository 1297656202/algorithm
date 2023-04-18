//P3810 【模板】三维偏序（陌上花开）
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
#define bit(i) (i&(-i))
using namespace std;
ll c[maxn],ans[maxn]={0},maxx,minn,cnt=0,tot=0,ge,n,m;
struct w{ll a,b,c,cnt,ans;}a[maxn],p[maxn];
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
	for(i=x;i<=m;i+=bit(i))
		c[i]+=y;
}
ll ask(ll x)
{
	ll ans=0,i;
	for(i=x;i;i-=bit(i))
	ans+=c[i];
	return ans;
}
void cdq(ll l,ll r)
{
	if(l==r){return ;}
	ll mid=(l+r)/2;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(p+l,p+mid+1,cmp2);
	sort(p+mid+1,p+r+1,cmp2);
	ll sum=0;
	ll i=l,j=mid+1,o=l;
	while(i<=mid&&j<=r)
	{
		if(p[i].b<=p[j].b){add(p[i].c,p[i].cnt);i++;}
		else {p[j].ans+=ask(p[j].c);j++;}
	}
	while(j<=r){p[j].ans+=ask(p[j].c);j++;}
	for(j=l;j<i;j++)
	add(p[j].c,-p[j].cnt);
}
int main()
{
	ll num=0,h,f1,f2,x,y,k,len,t,i,j,z;
	char ch[10];
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		cnt++;
		if(a[i].a!=a[i+1].a||a[i].b!=a[i+1].b||a[i].c!=a[i+1].c)
		{
			p[++tot]=a[i];
			p[tot].cnt=cnt;
			cnt=0;
		}
	}
	cdq(1,tot);
	for(i=1;i<=tot;i++)
	   ans[p[i].ans+p[i].cnt-1]+=p[i].cnt;
	for(i=0;i<=n-1;i++)
	printf("%lld\n",ans[i]);
	return 0;
}
