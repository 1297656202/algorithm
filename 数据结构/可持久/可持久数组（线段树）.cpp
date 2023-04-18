如题，你需要维护这样的一个长度为 N的数组，支持如下几种操作
1.在某个历史版本上修改某一个位置上的值
2.访问某个历史版本上的某一位置的值
此外，每进行一次操作（对于操作2，即为生成一个完全一样的版本，不作任何改动），
就会生成一个新的版本。版本编号即为当前操作的编号（从1开始编号，版本0表示初始状态数组）

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll int
#define inf 1e18
#define maxn 1000005
using namespace std;
ll rt[20*maxn],ls[20*maxn],rs[20*maxn],v[20*maxn],a[maxn],
ans=0,cnt=0,tot=0,sign=0,ge,n,m;
void bui(ll &x,ll l,ll r)
{
	x=++cnt;
	if(l==r){v[x]=a[l];return ;}
	ll mid=(l+r)/2;
	bui(ls[x],l,mid);
	bui(rs[x],mid+1,r);
}
void ins(ll &x,ll prt,ll l,ll r,ll q,ll val)
{
	x=++cnt;
	ls[x]=ls[prt];
	rs[x]=rs[prt];
	v[x]=v[prt];
	if(l==r){v[x]=val;return ;}
	ll mid=(l+r)/2;
	if(q<=mid)ins(ls[x],ls[prt],l,mid,q,val);
	else ins(rs[x],rs[prt],mid+1,r,q,val);
}
ll ask(ll x,ll l,ll r,ll q)
{
	if(l==r)return v[x];
	ll mid=(l+r)/2;
	if(q<=mid)return ask(ls[x],l,mid,q);
	else return ask(rs[x],mid+1,r,q);
}
int main()
{
	ll c,h,f1,maxx,f2,x,y,k,len,t,i,j,z,l,r;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	bui(rt[0],1,n);
	for(i=1;i<=m;i++)
	{ll prt,val;
		scanf("%d%d%d",&k,&prt,&x);
		if(k==1){scanf("%d",&val);ins(rt[i],rt[prt],1,n,x,val);}
		else {printf("%d\n",ask(rt[prt],1,n,x));rt[i]=rt[prt];}
	}
	return 0;
}
