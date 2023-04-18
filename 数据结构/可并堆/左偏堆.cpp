#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define maxn 1000005
using namespace std;
ll root[maxn],rs[maxn],ls[maxn],v[maxn],
prt[maxn],d[maxn]={0},maxx,
minn,cnt=0,tot=0,ge,n,m,l,r;
ll gf(ll x)
{
	if(prt[x]==x)return x;
	prt[x]=gf(prt[x]);
	return prt[x];
}
ll he(ll x,ll y)
{
	if(x==0||y==0)return x+y;
	if(v[x]<v[y])swap(x,y);
	rs[x]=he(rs[x],y);
	if(d[rs[x]]>d[ls[x]])swap(ls[x],rs[x]);
	if(rs[x]==0)d[x]=0;
	else d[x]=d[rs[x]]+1;
	return x;
}
ll tree(ll x)
{
	cnt++;
	v[cnt]=x;
	ls[cnt]=rs[cnt]=d[cnt]=0;
	return cnt;
}
void ins(ll x,ll y)
{ll z;
	z=tree(x);
	y=he(z,y);
}
ll delmin(ll x)
{ll t;
	t=v[root[x]];
	x=he(ls[x],rs[x]);
}
/*void del(ll x)
{ll q,p;
	q=prt[x];
	p=he(ls[x],rs[x]);
	prt[p]=q;
	if(q&&ls[q]==x)ls[q]=p;
	if(q&&rs[q]==x)rs[q]=p;
	while(q)
	{
		if(d[ls[q]]<d[rs[q]])swap(ls[q],rs[q]);
		if(d[rs[q]]+1==d[q])return ;
		d[q]=d[rs[q]]+1;
		p=q;
		q=prt[q];
	}
}*/
ll del(ll x)
{ll y;
	if(ls[x]==0&&rs[x]==0)
	{
		v[x]/=2;
		return x;
	}
	y=he(ls[x],rs[x]);
	prt[y]=y;
	prt[x]=x;
	ls[x]=rs[x]=0;
	v[x]/=2;
	ll z=he(y,x);
	prt[x]=prt[y]=z;
	return z;
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ll h,f1,f2,x,y,len,t,i,j,z;
	char ch;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
		   scanf("%lld",&v[i]);
		   prt[i]=i;
		}
		cin>>m;
		for(i=1;i<=m;i++)
		{
		   	scanf("%lld%lld",&x,&y);
		   	x=gf(x);y=gf(y);
		   	if(x==y){printf("-1\n");continue;}
		   	f1=del(x);
		   	f2=del(y);
		   	ll tmp=he(f1,f2);
		   	prt[f1]=prt[f2]=tmp;
		   	printf("%lld\n",v[tmp]);
	   	}
	}
    return 0;
}
