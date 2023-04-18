luogu4178
点分治，常用来大规模处理路径，一般情况下，单纯的朴素算法需要O（n*n）
而点分治可以将复杂度降为O（nlogn） 
给定一棵 n 个节点的树，每条边有边权，求出树上两点距离小于等于 k 的点对数量。

思路：
在树中一条路径有两种情况：
①过根结点
②在一棵子树中
启发我们可以使用分治算法。
路径在子树中的情况只需递归处理即可，下面来分析如何处理路径过根结点的情况。
记d(i)表示点i到根结点的路径长度，Belong(i)=X（X为根结点的某个儿子，且结点i在以
X为根的子树内）。那么我们要统计的就是：
满足d(i)+d(j)<=K且Belong(i)≠Belong(j)的(i,j)个数
=满足d(i)+d(j)<=K的(i,j)个数-满足d(i)+d(j)<=K且Belong(i)=Belong(j)的(i,j)个数
而对于这两个部分，都是要求出满足Ai+Aj<=K的(i,j)的对数：将A[]排序后利用单调性（即
双指针维护），很容易得出一个O(N)的算法，所以可以用O(NlogN)的时间解决这个问题。

注意：一般情况下点分治的题目都需要剔除来自同一个belong的路径的答案，
因为来自同一个belong的两个点的路径长度根本不等于两个点到此时根节点的长度的距离和，
他们之间的路径根本不经过此时的根节点 

代码： 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn], 
maxcore,core,d[mn],lim;
struct w{ll next,to,z;}a[2*mn];
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
void dfss(ll x,ll prt,ll dis)//标记x到fa的距离为dis方便后续处理 
{ll i,y;
	d[++d[0]]=dis;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y]==1||y==prt)continue;
		dfss(y,x,dis+a[i].z);
	}
}
void cal(ll x,ll len,ll dlt)//求以x为根,x到父亲距离为len时,子树中满足条件的点对
{   d[0]=0;
	dfss(x,x,len);//因为计算是到当前子树的根节点的距离，如果计算同一个子树的路径，则需要加上x到fa的距离 
	sort(d+1,d+d[0]+1);//按距离从小到大快排
	ll l=1,r=d[0];//双指针维护求合法点对数目
	while(l<r)
    if(d[l]+d[r]<=lim){ans+=(r-l)*dlt;l++;}
		else r--;
}
void find(ll x,ll prt,ll num)//找重心，这一部分基本都是模板 
{ll maxx=0,i,y;
	s[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt||bj[y]==1)continue;
		find(y,x,num);
		s[x]+=s[y];
		maxx=max(maxx,s[y]);
	}
	maxx=max(maxx,num-s[x]);
	if(maxcore>maxx){maxcore=maxx;core=x;}//core为树的重心
}
void dfs(ll x,ll num)//以x为根,总共Num个结点
{ll i,y;
    maxcore=inf;
	find(x,0,num);//求以x为根的子树的中心core，以上也是必须的模板 
	cal(core,0,1);//求以core为根的子树中满足条件的点对
	bj[core]=1;//标记，也是必须的模板 
	for(i=h[core];i;i=a[i].next)//对于重心儿子结点处理
	{
		y=a[i].to;
		if(bj[y]==1)continue; 
		cal(y,a[i].z,-1);//减去儿子子树中满足条件的点对
		dfs(y,s[y]);//对以儿子结点为根的子树递归处理，也是模板套路 
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
    cin>>lim;
	dfs(1,n);
	cout<<ans;
    return 0;
}
