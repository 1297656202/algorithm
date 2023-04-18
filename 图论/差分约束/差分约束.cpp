/*
给定一组不等式x[i]-x[i]<=c[k](或x[i]-x[i]>=c[k))，
需要求出满足所有不等式的一组解(x[1],x[2]....,x[n])。这类问题是线性规划的一类简单问题。
这就是差分约束系统。
差分约束系统先要通过大小关系进行建图，然后通过spfa求解， 
求最大解需用最短路算法，可以这样想，从最大值拉下来，符合条件后自然就是最大值 ,
此时建图的时候为当a[i]-a[j]<=x，add(i->j) 
反之最小解需用最长路，当a[i]-a[j]>=x，add(i->j)
然后使用spfa，存在负环的时候无解
差分约束系统关键在于要搞清约束关系
例题：
有一个整数序列，我们不知道它的长度是多少(即序列中整数的个数)，但我们知道在某些区间中至少有多少个整数，
用区间 [ai,bi,ci]来描述它，[ai,bi,ci]表示在该序列中处于[ai,bi]这个区间的整数至少有ci个。
n 现在给出若干个这样的区间，请你求出满足条件的最短序列长度是多少，如果不存在则输出 -1。 
约束关系： 先求前缀和s[i]
s[b]-S[a-1]≥c[i](1<=i<=m)
S[i]-S[i-1]≥0(1<=i<=n)
S[i-1]-S[i]≥-1(1<=i<=n) 
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
queue<ll>q;
ll x[25],s[25],used[1005]={0},num[25]={0},d[1005],r[25],cnt=0,h[1005]={0},bj[1005],ge,n,m,t;
struct w{ll next,to,z;}a[1000005];
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
ll spfa()
{ll i,x,y;
	for(i=0;i<=24;i++)
	{ 
		q.push(i);
	    s[i]=0;
	    bj[i]=1;
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		bj[x]=0;
		for(i=h[x];i;i=a[i].next)//这是在求解最长路，即为最小解 
		{
			y=a[i].to;
			if(s[y]<s[x]+a[i].z)
			{
				used[y]++;
				if(used[y]>=25)return 0;
				s[y]=s[x]+a[i].z;
				if(bj[y]==0)
				{
					q.push(y);
					bj[y]=1;
				}
			}
		}
	}
   return 1;
}
int main()
{
	ll x,y,i,j,k,z,he=0;
    for(i=1;i<=24;i++)
        cin>>r[i];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
		num[++x]++;
	}
	for(i=1;i<=24;i++)
	    he+=num[i];
	for(k=0;k<=he;k++)//用各种大小关系建图，有些大小关系很隐晦 
	{
		cnt=0;
	    memset(used,0,sizeof(used));
	    memset(h,0,sizeof(h));  
		for(i=1;i<=24;i++)
	    {
		    add(i,i-1,-num[i]);
		    add(i-1,i,0);
	    }
		for(i=8;i<=24;i++)
		   add(i-8,i,r[i]);
	    s[24]=k;
	    add(24,0,-k);
	    for(j=1;j<=7;j++)
	       add(j+16,j,r[j]-k);
		if(spfa())
		{cout<<k;return 0;}
	}
	cout<<"No Solution!";
	return 0;
}
