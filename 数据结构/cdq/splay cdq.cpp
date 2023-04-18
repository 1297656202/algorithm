#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
//#define  inline
#define bit(i) (i&(-i))
#define eps 1e-8
using namespace std;
ll c[maxn][2],rt,fa[maxn],cnt=0,tot=0,ge,n,m,num;
double f[maxn],x[maxn],y[maxn],lk[maxn],
ans=0,rk[maxn],a[maxn],b[maxn],rate[maxn];
 void turn(ll x,ll &rt)
{ll y=fa[x],z=fa[y];
	ll p=(c[y][1]==x),q=p^1;
	if(y==rt)rt=x;
	else if(c[z][0]==y)c[z][0]=x;
	else c[z][1]=x;
	fa[x]=z;
	fa[y]=x;
	fa[c[x][q]]=y;
	c[y][p]=c[x][q];
	c[x][q]=y;
}
 void spl(ll x,ll &rt)
{
	while(x!=rt)
	{
		ll y=fa[x],z=fa[y];
		if(y!=rt)
			if((c[y][0]==x)^(c[z][0]==y))turn(x,rt);else turn(y,rt);
		turn(x,rt);
	}
}
 void ins(ll &t,ll anc,ll y)
{
	if(t==0){t=y;fa[t]=anc;return ;}
	if(x[y]<=x[t]+eps)ins(c[t][0],t,y);
	else ins(c[t][1],t,y);
} 
 double getk(ll i,ll j)
{
	if(abs(x[i]-x[j])<eps)return -inf;
	else return (y[j]-y[i])/(x[j]-x[i]);
}
 ll prev(ll rt)
{ll t=c[rt][0],tmp=t;
	while(t)
	{
		if(getk(t,rt)<=lk[t]+eps){tmp=t;t=c[t][1];}
		else t=c[t][0];
	}
	return tmp;
}
 ll succ(ll rt)
{ll t=c[rt][1],tmp=t;
	while(t)
	{
		if(getk(rt,t)+eps>=rk[t]){tmp=t;t=c[t][0];}
		else t=c[t][1];
	}
	return tmp;
}
 void up(ll t)
{
	spl(t,rt);
	if(c[t][0])
	{
		ll l=prev(rt);
		spl(l,c[rt][0]);
		c[l][1]=0;
		lk[t]=rk[l]=getk(l,t);
	}
	else lk[t]=inf;
	if(c[t][1])
	{
		ll r=succ(rt);
		spl(r,c[rt][1]);
		c[r][0]=0;
		rk[t]=lk[r]=getk(t,r);
	}
	else rk[t]=-inf;
	if(lk[t]<=rk[t]+eps)
	{
		rt=c[t][0];
		c[rt][1]=c[t][1];
		fa[c[t][1]]=rt;
		fa[rt]=0;
		lk[rt]=rk[c[t][1]]=getk(rt,c[t][1]);
	}
}
 ll find(ll t,double k)
{
	if(t==0)return 0;
	if(lk[t]+eps>=k&&k+eps>=rk[t])return t;
	if(k+eps>lk[t])return find(c[t][0],k);
	else return find(c[t][1],k);
}
int main()
{
	ll num=0,h,f1,f2,k,len,t,i,j,z;
	char ch[10];
	cin>>n>>f[0];
	for(i=1;i<=n;i++)
	   scanf("%lf%lf%lf",&a[i],&b[i],&rate[i]);
	for(i=1;i<=n;i++)
	   {
	   	ll j=find(rt,-a[i]/b[i]);
	   	f[i]=max(f[i-1],x[j]*a[i]+y[j]*b[i]);
	   	y[i]=f[i]/(a[i]*rate[i]+b[i]);
	   	x[i]=y[i]*rate[i];
	   	ins(rt,0,i);
	   	up(i);
	   }
	cout<<fixed<<setprecision(3)<<f[n];
	return 0;
}
