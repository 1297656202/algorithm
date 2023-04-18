#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1200005
using namespace std;
typedef pair<ll,ll>pii;
priority_queue<pii>Q;
ll top,q[6],rt,D,K,t,
ans=0,maxx,minn,cnt=0,tot=0,ge,n,m,l,r;
struct w{ll d[6],mx[6],mi[6],l,r;}a[maxn],tmp;
bool cmp(const w&a,const w&b){return a.d[D]<b.d[D];}
void up(ll x)
{ll i,ls=a[x].l,rs=a[x].r;
	for(i=0;i<=K-1;i++)
	{
		if(ls)
		{
			a[x].mx[i]=max(a[x].mx[i],a[ls].mx[i]);
			a[x].mi[i]=min(a[x].mi[i],a[ls].mi[i]);
		}
		if(rs)
		{
			a[x].mx[i]=max(a[x].mx[i],a[rs].mx[i]);
			a[x].mi[i]=min(a[x].mi[i],a[rs].mi[i]);
		}
	}
}
void bui(ll &root,ll l,ll r,ll d)
{ll i,mid=(l+r)/2;
	D=d;
	root=mid;
	nth_element(a+l,a+mid,a+r+1,cmp);
	for(i=0;i<=K-1;i++)
	a[root].mx[i]=a[root].mi[i]=a[root].d[i];
	if(l<mid)bui(a[root].l,l,mid-1,(d+1)%K);
	if(r>mid)bui(a[root].r,mid+1,r,(d+1)%K);
	up(root);
}
ll Dis(ll x)
{ll i,ans=0;
	for(i=0;i<=K-1;i++)
	   ans+=(ll)abs(q[i]-a[x].d[i]);
	return ans;
}
void print()
{ll i,x;
	while(Q.empty()==0)
	{
		x=Q.top().second;
		Q.pop();
		print();
		printf("%lld\n",Dis(x));
	}
}
ll gue(ll x)
{ll i,s=0;
	for(i=0;i<=K-1;i++)
	{
		if(q[i]<a[x].mi[i])s+=(ll)abs(q[i]-a[x].mi[i]);
		if(q[i]>a[x].mx[i])s+=(ll)abs(q[i]-a[x].mx[i]);
	}
	return s;
}
void ins(ll root,ll x)
{ll i,dir=0,p=root;
	while(1)
	{
		for(i=0;i<=1;i++)
		{
			a[p].mx[i]=max(a[p].mx[i],a[x].mx[i]);
			a[p].mi[i]=min(a[p].mi[i],a[x].mi[i]);
		}
		if(a[x].d[dir]>=a[p].d[dir])
		{
			if(a[p].r==0){a[p].r=x;return ;}
			else p=a[p].r;
		}
		else 
		{
			if(a[p].l==0){a[p].l=x;return ;}
			else p=a[p].l;
		}
		dir=(dir+1)%2;
	}
}
void ask(ll x)
{
	if(x==0)return ;
	ll dis=Dis(x),dl=gue(a[x].l),dr=gue(a[x].r);;
	if(dis<Q.top().first)
	{
		Q.pop();
		Q.push(make_pair(dis,x));
	}
	if(dl<dr)
	{
		if(dl<Q.top().first)ask(a[x].l);
		if(dr<Q.top().first)ask(a[x].r);
	}
	else 
	{
		if(dr<Q.top().first)ask(a[x].r);
		if(dl<Q.top().first)ask(a[x].l);
	}
}
int main()
{
	ll h,f1,f2,x,he=0,v,y,len,t,i,j,z;
	char ch;
	K=2;
	cin>>n>>m;
		for(i=1;i<=n;i++)
		   for(j=0;j<=1;j++)
		   	scanf("%lld",&a[i].d[j]);
		   	bui(rt,1,n,0);
	while(m--)
	{
		ll k;
		scanf("%lld",&k);
		if(k==1)
			{
			n++;
			scanf("%lld%lld",&a[n].d[0],&a[n].d[1]);
			a[n].mx[0]=a[n].mi[0]=a[n].d[0]; 
			a[n].mx[1]=a[n].mi[1]=a[n].d[1]; 
			ins(rt,n);
			}
		else 
		{
			scanf("%lld%lld",&q[0],&q[1]);
			Q.push(make_pair(inf,0));
			ask(rt);
			print();
		}
	}
    return 0;
}
