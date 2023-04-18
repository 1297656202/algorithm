例题：给定一棵有n（<=10000）个点的树，给定m(<=100)个询问，问树上距离为k的点对是否存在。（时限200ms） 

思路：这个题目用点分治是必然的，但是，如果对于每个询问都进行点分，
复杂度n*m*logn理论上可行，但是点分治的常数复杂度太大，故无法完成，
这个时候，最好一次点分治就能够解决问题，就可以避免巨大的常数，
有两种方法：1：建立点分树 2：边点分边解决询问 

注意：一般情况下点分治的题目都需要剔除来自同一个belong的路径的答案

下面为边点分边解决询问的代码： 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn],bel[mn],d0,ok[mn],qus[mn],
maxcore,core;
struct w{ll next,to,z;}a[2*mn];
struct ww{ll d,bl;}d[mn];
bool cmp(ww a,ww b){return a.d<b.d;}
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
void dfss(ll x,ll prt,ll dis,ll belong)//标记x到fa的距离为dis方便后续处理 
{ll i,y;
	d[++d0]=(ww){dis,belong};
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y]==1||y==prt)continue;
		dfss(y,x,dis+a[i].z,belong);
	}
}
void cal(ll x)//求以x为根,x到父亲距离为len时,子树中满足条件的点对
{ll i,y;
	d0=0;
	d[++d0]=(ww){0,0};
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y])continue;
		dfss(y,x,a[i].z,y);
	}
	sort(d+1,d+d0+1,cmp);//按距离从小到大快排
	for(i=1;i<=m;i++)
	if(ok[i]==0)
	{
		ll l=1,r=d0;//双指针维护求合法点对是否存在 
		while(l<r)
	    if(d[l].d+d[r].d<qus[i])l++;
		else if(d[l].d+d[r].d>qus[i])r--;
		else if(d[l].bl!=d[r].bl){ok[i]=1;break;} 
		else l++;
	}
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
	cal(core);//求以core为根的子树中满足条件的点对
	bj[core]=1;//标记，也是必须的模板 
	for(i=h[core];i;i=a[i].next)//对于重心儿子结点处理
	{
		y=a[i].to;
		if(bj[y]==1)continue; 
		dfs(y,s[y]);//对以儿子结点为根的子树递归处理，也是模板套路 
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
    for(i=1;i<=m;i++)
		scanf("%lld",&qus[i]);
	dfs(1,n);
	for(i=1;i<=m;i++)
	if(ok[i])printf("AYE\n");
	else printf("NAY\n");
    return 0;
}
