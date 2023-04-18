求基环树的直径
注意，有可能像下面的这道例题，有可能是基环树森林 
例题：IOI2008 island（算法竞赛p383） 
我们先用一次深度优先遍历找出基环树中的“环”，把“环”上的
节点做上标记。设环上的节点为s1,s2,.. .,St
从每个s出发，在不经过环上其他节点的前提下，再次执行深度优先遍历，
即可访问去掉“环之后以si为根的子树。在这样的每棵子树中，
按照求树的直径的方法进行DP并更新答案，即可处理直径不在环上的情况。
同时，还可以计算出D[si]，表示从节点si出发走向以si为根的子树，能够到达的最远节点的距离。
最后，我们考虑直径在环上的情况。这相当于找到环上两个不同的节点si，sj，
使得D[s]+D[sj]+dist(si,sj)最大。其中dis(si,sj)表示si,sj在环上的距离，
有逆时针、顺时针两种走法，取较长的那一种。这等价于“环路运输”，
把环断开成链再复制一倍，用单调队列即可在O(N)的时间内解决。
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll bj[mn],v[mn],ins[mn],cir[mn],maxd=0,ed,h[mn],stk[mn],
f[mn],sum[mn],top=0,dis[mn],ans=0,st,
cnt=0,tot=0,n,m;
struct w{ll next,to,z;}a[mn*2];
deque<ll>q;
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
void dfs1(ll x,ll fa)
{ll i,y,j,bjj=0;
    stk[++top]=x;
	ins[x]=top;
    for(i=h[x];i;i=a[i].next)
	{
        y=a[i].to;
		if(y==fa&&bjj==0){bjj++;continue;}
		dis[top]=a[i].z;
        if(ins[y])
		for(j=ins[y];j<=ins[x];j++)
		{
			cir[++cir[0]]=stk[j];
			sum[cir[0]]=sum[cir[0]-1]+dis[j];
			bj[stk[j]]=1;
		}
        else 
		{
			dfs1(y,x);
		}
    }
    top--;
}
void dfs(ll x,ll prt,ll deep)
{ll i,y;
	if(deep>maxd){maxd=deep;ed=x;}
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt||bj[y]==1)continue;
		dfs(y,x,deep+a[i].z);
	}
}
ll cal()
{ll i,j,s=0;
	cir[0]=0;
	top=0;
	q.clear();
	dfs1(st,0);
	for(i=1;i<=cir[0];i++)
	{
		maxd=0;
		dfs(cir[i],0,0);
		f[i]=maxd;
		maxd=0;
		if(n>=800000)bj[cir[i]]=0;
		dfs(ed,0,0);
		if(n>=800000)bj[cir[i]]=1;
		s=max(maxd,s);
	}
//	cout<<s<<" "<<cir[1]<<" "<<f[1]<<" "<<f[2]<<endl;
	for(i=1;i<=cir[0];i++)
		f[i+cir[0]]=f[i];
	for(i=cir[0]+1;i<=cir[0]*2;i++)
	{
		sum[i]=sum[i-1]+sum[i-cir[0]]-sum[i-cir[0]-1];
	}
	for(i=1;i<=cir[0]*2;i++)
	{
		while(q.empty()==0&&i-q.front()>=cir[0])
		q.pop_front();
		if(q.empty()==0)s=max(s,f[i]+f[q.front()]+sum[i-1]-sum[q.front()-1]);
		while(q.empty()==0&&f[q.back()]-sum[q.back()-1]<f[i]-sum[i-1])
		q.pop_back();
		q.push_back(i);
	}
	return s;
}
int main()
{
	ll te,x,y,i,j,z,k;
	char ch;	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(i,x,y);
		add(x,i,y);
	}
	for(i=1;i<=n;i++)
	if(ins[i]==0)
	{
		st=i;
		ans+=cal();
	}
	cout<<ans;
    return 0;
}
