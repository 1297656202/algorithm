#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
#define bit(i) (i&(-i))
#define eps 1e-8
using namespace std;
ll rt,s[maxn],top=0,cnt=0,tot=0,ge,n,m,num;
double f[maxn];
struct w{double x,y,a,b,k,rate;ll w,id;}p[maxn],t[maxn];
double getk(ll a,ll b)
{
	if(b==0)return -inf;
	if(abs(p[a].x-p[b].x)<eps)return inf;
	return (p[b].y-p[a].y)/(p[b].x-p[a].x);
}
bool operator<(w a,w b){return a.k>b.k;}
void cdq(ll l,ll r)
{ll i;
	if(l==r)
	{
		f[l]=max(f[l],f[l-1]);
		p[l].y=f[l]/(p[l].a*p[l].rate+p[l].b);
		p[l].x=p[l].rate*p[l].y;
		return ;
	}
	ll l1,l2,mid=(l+r)/2,j=1;
	l1=l,l2=mid+1;
	for(i=l;i<=r;i++)
	   if(p[i].id<=mid)
	     t[l1++]=p[i];
	    else t[l2++]=p[i];
	for(i=l;i<=r;i++)
	   p[i]=t[i];
	cdq(l,mid);
	top=0;
	for(i=l;i<=mid;i++)
	{
		while(top>1&&getk(s[top-1],s[top])<getk(s[top],i)+eps)
		top--;
		s[++top]=i;
	}
	s[++top]=0;
	for(i=mid+1;i<=r;i++)
	{
		while(j<top&&getk(s[j],s[j+1])+eps>p[i].k)j++;
		f[p[i].id]=max(f[p[i].id],p[s[j]].x*p[i].a+p[s[j]].y*p[i].b);
	}
	cdq(mid+1,r);
	l1=l;l2=mid+1;
	ll len=l;
	while(l1<=mid&&l2<=r)
	{
		if(p[l1].x<p[l2].x||(abs(p[l1].x-p[l2].x))<eps&&p[l1].y<p[l2].y)
		t[len++]=p[l1++];
		else t[len++]=p[l2++];
	}
	if(l1<=mid)for(i=l1;i<=mid;i++)
	   t[len++]=p[i];
	if(l2<=r)for(i=l2;i<=r;i++)t[len++]=p[i];
	for(i=l;i<=r;i++)p[i]=t[i];
}
int main()
{
	ll num=0,h,f1,f2,k,len,t,i,j,z;
	char ch[10];
	cin>>n>>f[0];
	for(i=1;i<=n;i++)
	 {
	   scanf("%lf%lf%lf",&p[i].a,&p[i].b,&p[i].rate);
     	p[i].k=-p[i].a/p[i].b;
     	p[i].id=i;
	 }
	 sort(p+1,p+n+1);
	 cdq(1,n);
	 printf("%.3lf",f[n]);
	return 0;
}
