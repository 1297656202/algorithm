#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define maxn 60005
using namespace std;
ll nn,top,cnt=0,tot=0,sign=0,ge,n,m;
ll x1,x2;
double ans=0;
struct w{double x,y;}a[maxn],b[maxn];
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
/*double area(w i,w j,w k)
{
	double a=cal(i,j);
	double b=cal(i,k);
	double c=cal(k,j);
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}*/
void addcr(w A,w B,w c,w d)
{
	double c1=abs(cr(d,B,A)),c2=abs(cr(c,B,A));
	nn++;
	b[nn].x=(c1*c.x+c2*d.x)/(c1+c2);
	b[nn].y=(c1*c.y+c2*d.y)/(c1+c2);
}
void cut(w A,w B)
{ll i;
//	cout<<n<<endl;
	nn=0;a[n+1]=a[1];
	for(i=2;i<=n+1;i++)
	{
		if(cr(a[i-1],B,A)>=0)//À≥ ±’Î°∑=0£¨ƒÊ ±’Î°∂=0 
		{
		b[++nn]=a[i-1];
		if(cr(a[i],B,A)<0)addcr(A,B,a[i-1],a[i]);
	    }
		else if(cr(a[i],B,A)>0)addcr(A,B,a[i-1],a[i]);
	}
	for(i=1;i<=nn;i++)
	   a[i]=b[i];
	n=nn;
}
void read()
{ll m,i;
	w a,b,c;
	cin>>m;cin>>a.x>>a.y;
	c=a;
	for(i=2;i<=m;i++)
	{
		scanf("%lf%lf",&b.x,&b.y);
		cut(a,b);
		a=b;
	}
	cut(a,c);
}
int main()
{
	ll f1,maxx,f2,x,y,k,len,t,i,j,z,r;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	   {
	   scanf("%lf%lf",&a[i].x,&a[i].y);
       }
	read();
	a[n+1]=a[1];
	for(i=1;i<=n;i++)
	   ans+=a[i].x*a[i+1].y-a[i].y*a[i+1].x;
	printf("%.2lf",abs(ans)/2);
	return 0;
}
