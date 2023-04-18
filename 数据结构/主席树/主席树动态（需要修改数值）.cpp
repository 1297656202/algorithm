给定一个含有 n个数的序列 ，需要支持两种操作：
Q l r k 表示查询下标在区间 [l,r]中的第 k小的数
C x y 表示将 a_x改为 y
1≤n，m≤10^5

首先说说怎么搞带修改主席树？
回忆一般的kth问题，我们的主席树求的是前缀和，这样我们在目标区间的左右端点的主席树差分下就能求出kth。
考虑到我们之前使用主席树朴素的维护区间前缀和，支持修改的话，
只要把前缀和交给擅长它的树状数组维护，主席树只要维护下大概位置就好。当然维护位置最好要离散化一下。

外层维护的是元素位置的区间：如果我们想查询[L,R]的第k小，
我们首先找的是外层的对应[1,R]、[1,L-1]前缀和的几段区间（外层的节点，就是内层线段树的根节点）
【外层的线段树的作用，是为了帮助我们找到位置区间对应的几颗内层线段树】

内层维护的是数值的出现次数：每棵线段树表示，在根节点对应的外层区间中，每个数值出现的次数

然后要注意的是，有可能空间会开得很大，（n+m）*logn*logn 级别的，大概要*400左右，甚至更多（看题目限制多少） 
如果不离散，为（n+m）*logn*logm，如果空间没有爆的话，或者题目本身就不方便离散所有插入，询问值的时候 
也可以不离散 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll a[mn],b[mn*2],
t1[mn],t2[mn],rt[mn],ls[mn*400],
rs[mn*400],s[mn*400],cnt=0,tot=0,ge,n,m;
struct w{ll l,r,k;char c[3];}q[mn];
inline ll low(ll i){return i&(-i);}
//现在的端点为x，范围（l，r），要处理的位置为pos，加上val 
void ins(ll &x,ll l,ll r,ll pos,ll val) 
{
	if(x==0)x=++cnt;s[x]+=val;
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(pos<=mid)ins(ls[x],l,mid,pos,val);
	else ins(rs[x],mid+1,r,pos,val);
} 
void add(ll k,ll x,ll val)//排在内层线段树第k位，外层位于x这个位置，加上val 
{ll i;
	for(i=x;i<=n;i+=low(i))ins(rt[i],1,tot,k,val);
}
ll query(ll l,ll r,ll k)//询问第二层线段树中的第k大 
{ll i;
	if(l==r)return l;
	ll mid=(l+r)/2,tmp1=0,tmp2=0;
	for(i=1;i<=t1[0];i++)tmp1+=s[ls[t1[i]]];
	for(i=1;i<=t2[0];i++)tmp2+=s[ls[t2[i]]];
	ll tmp=tmp2-tmp1;
	if(tmp>=k)
	{
		for(i=1;i<=t1[0];i++)t1[i]=ls[t1[i]];
		for(i=1;i<=t2[0];i++)t2[i]=ls[t2[i]];
		return query(l,mid,k);
	}
	else 
	{
		for(i=1;i<=t1[0];i++)t1[i]=rs[t1[i]];
		for(i=1;i<=t2[0];i++)t2[i]=rs[t2[i]];
		return query(mid+1,r,k-tmp);
	}
}
ll ask(ll l,ll r,ll k)//询问，注意下面main函数的前缀和处理  
{ll i;
	t1[0]=t2[0]=0;
	for(i=l;i;i-=low(i))t1[++t1[0]]=rt[i];
	for(i=r;i;i-=low(i))t2[++t2[0]]=rt[i];
	return query(1,tot,k);
}
int main()
{
	ll x,y,k,i,j,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	    scanf("%lld",&a[i]);
        b[i]=a[i];
	}
	tot=n;
	for(i=1;i<=m;i++)
	{
		scanf("%s",q[i].c);
		if(q[i].c[0]=='C')
		{
			scanf("%lld%lld",&q[i].l,&q[i].k);
			b[++tot]=q[i].k;
		}
		else scanf("%lld%lld%lld",&q[i].l,&q[i].r,&q[i].k);
	}
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(i=1;i<=n;i++)
	   a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	for(i=1;i<=n;i++)//
	   add(a[i],i,1);
	for(i=1;i<=m;i++)
	{
		if(q[i].c[0]=='Q')printf("%lld\n",b[ask(q[i].l-1,q[i].r,q[i].k)]);//询问（l,r）中的第k大 
		else//做差分， 现在l减1，再在r处加1（k相当于r） 
		{
			add(a[q[i].l],q[i].l,-1);
			x=lower_bound(b+1,b+tot+1,q[i].k)-b;
			a[q[i].l]=x;
			add(a[q[i].l],q[i].l,1);
		}
	}
	return 0;
}

题意
2e5的数组，q个操作
1.将a[x]改为y
2.求下标l到r内所有的a[i]通过加法不能构成的最小的值

前面主席树静态的的题目的变体，照着静态的代码魔改即可 
