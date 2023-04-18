#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define maxn 10005
#define y1 y3
using namespace std;
ll top,q[maxn],b[maxn],cnt=0,tot=0,sign=0,ge,n=0,m=0;
struct w{double x,y;}a[maxn];
double cal(w a,w b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cr(w a,w b,w c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
ll cmp(const w&a,const w&b)
{
	return (a.y<b.y)||(a.y==b.y&&a.x<b.x);
}
int main()
{
	ll c,f1,maxx,f2,x,y,k,len,t,i,j,z,r;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	   scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	if(n==2){printf("%.2lf\n0.00",cal(a[1],a[2]));return 0;}
	q[1]=1;
	q[2]=2;
	top=2;
	for(i=3;i<=n;i++)
	{
		while(top>1&&cr(a[q[top]],a[i],a[q[top-1]])<=0)
		top--;
		q[++top]=i;
	}
	for(i=1;i<=top;i++)
	b[++b[0]]=q[i];
	q[1]=n;
	q[2]=n-1;
	top=2;
	for(i=n-2;i>=1;i--)
	{
		while(top>1&&cr(a[q[top]],a[i],a[q[top-1]])<=0)
		top--;
		q[++top]=i;
	}
	for(i=2;i<=top-1;i++)
	b[++b[0]]=q[i];
	double s=0,l=0;
	b[b[0]+1]=b[1];
	for(i=1;i<=b[0];i++)
	{
		s+=cr(a[b[i]],a[b[i+1]],a[0]);
		l+=cal(a[b[i]],a[b[i+1]]);
	}
	s=abs(s)/2;
	if(s==0)l/=2;
	printf("%.2lf\n%.2lf",l,s);
	return 0;
}
