luogu sp1716 GSS3
操作0 x y把A_x改成y 
操作1 l r询问区间[l,r]的最大子段和，也就是连在一起的最大子段 

值得注意的是这个模型非常有价值
它还可以维护以某个序列上的点为左端点（右端点）能够得到的最大子段和（具体过程可以类比下面的过程想出来）
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,s,ls,rs,res;}a[mn*4];//线段树数组开4倍 
//s表示这一段的总和，ls，rs分别表示从区间左端点和右端点开始的最大子段和，res为区间最长子段和 
void up(ll v)//这一段的维护过程是重点 
{
	a[v].s=a[v*2].s+a[v*2+1].s;
	a[v].ls=max(a[v*2].ls,a[v*2].s+a[v*2+1].ls);
	a[v].rs=max(a[v*2+1].rs,a[v*2+1].s+a[v*2].rs);
	a[v].res=max(a[v*2].rs+a[v*2+1].ls,max(a[v*2].res,a[v*2+1].res)); 
}
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	if(l==r){a[v].s=a[v].ls=a[v].rs=a[v].res=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
	up(v);
}
void add(ll v,ll x,ll y)
{
	if(a[v].b<x||a[v].a>x)return;
	if(a[v].a==a[v].b){a[v].s=a[v].ls=a[v].rs=a[v].res=y;return ;}
	add(v*2,x,y);
	add(v*2+1,x,y);
	up(v);
}
w ask(ll v,ll l,ll r)//这一段的询问过程也是重点 
{
	if(l<=a[v].a&&r>=a[v].b){return a[v];}
	if(r<a[v*2+1].a)return ask(v*2,l,r);
	if(l>a[v*2].b)return ask(v*2+1,l,r);
	w lv=ask(v*2,l,r),rv=ask(v*2+1,l,r),ret;
	ret.s=lv.s+rv.s;
	ret.ls=max(lv.ls,lv.s+rv.ls);
	ret.rs=max(rv.rs,rv.s+lv.rs);
	ret.res=max(lv.rs+rv.ls,max(lv.res,rv.res));
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(1,1,n);
	cin>>m;
	while(m--)
	{
		scanf("%lld",&k);
		if(k==0)
		{
			scanf("%lld%lld",&x,&y);
			add(1,x,y);
		}
		else 
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask(1,x,y).res);
		}
	}
    return 0;
}
