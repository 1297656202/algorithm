#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define maxn 10005
#define y1 y3
using namespace std;
ll b[105],cnt=0,tot=0,sign=0,ge,n=0,m=0;
struct ww{ll x,y;}a[105];
double cal(ww a,ww b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cr(ww a,ww b,ww c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
ll cmp(const ww&x,const ww&y)
{
	double tmp=cr(x,y,a[1]);
	if(tmp>0)return 1;
	if(tmp==0)return cal(x,a[1])<cal(y,a[1]);
	return 0;
}
int main()
{
	ll c,f1,maxx,f2,x,y,k,len,t,i,j,z,r;
	char ch;
	cin>>n;
	ll minx=inf,miny=inf;
	for(i=1;i<=n;i++)
	   {
	   	scanf("%lld%lld",&a[i].x,&a[i].y);
	   	if(miny>a[i].y||(miny==a[i].y&&minx>a[i].x))
	   	{
	   		minx=a[i].x;
	   		miny=a[i].y;
	   		k=i;
	   	}
	   }
	swap(a[1],a[k]);
	sort(a+2,a+n+1,cmp);
	b[1]=1;b[2]=2;t=2;
	for(i=3;i<=n;i++)
	{
		while(t>1&&cr(a[b[t]],a[i],a[b[t-1]])<=0)t--;
		b[++t]=i;
	}
	b[++t]=b[1];
	double s=0,l=0;
	for(i=2;i<=t;i++)
	{
		s+=cr(a[b[i-1]],a[b[i]],a[1]);
		l+=cal(a[b[i]],a[b[i-1]]);
	}
	s=abs(s)/2;
	if(s==0)l=l/2;
	cout<<fixed<<setprecision(2)<<l<<endl;
	cout<<fixed<<setprecision(2)<<s<<endl;
	return 0;
}
