对2-SAT问题的总结：
简要意思:就是给定N个组（每个组2个元素）、M个互斥关系，从每个组里挑1个使得给定的不满足任何互斥关系。
但是解决这类问题的关键还是在于建模，基本建模就是对于两个不相容的点i、j，
构图方式为:i→j'(i和j冲突，选i只能选j')和j→i'（i和j冲突，选j只能选i')。
解2-SAT方法是:对原图求一次强连通分量，然后看每组中的两个点是否属于同一个强连通分量，
如果存在这种情况，那么无解;否则对图进行一次拓扑排序，自底向上地选择点即可得到一组可行解。

某国有n个党派，每个党派在议会中恰有2个代表。 现在要成立和平委员会 ，该会满足
.每个党派在和平委员会中有且只有一个代表 
.如果某两个代表不和，则他们不能都属于委员会
.代表的编号从1到2n，编号为2a-1、2a的代表属于第a个党派 
任务：读入党派的数量和关系不友好的代表对，计算决定建立和平委员会是否可能，若行，则列出委员会的成员表。
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll bj[mn],in[mn],num=0,s[mn],
opp[mn],belong[mn],top=0,sign=0,
cnt=0,ge,r,d,n,m,h[mn],dfn[mn],low[mn];
struct w{ll next,to;}a[mn];
void add(ll x,ll y)
{
   cnt++;
   a[cnt].next=h[x];
   a[cnt].to=y;
   h[x]=cnt;
}
void dfs(ll x)
{ll i,y;
	dfn[x]=low[x]=++sign;
	s[++top]=x;
	in[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
	   	y=a[i].to;
	   	if(dfn[y]==0)
	   	{
			dfs(y);
			low[x]=min(low[x],low[y]);
	   	}
	   	else if(in[y])low[x]=min(low[x],low[y]);
	}
	   ll t;
	if(low[x]==dfn[x])
	{
	    num++;
	    do
		{
		    t=s[top--];	
			in[t]=0;
			belong[t]=num;
	    }while(t!=x);
	}
}
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		ll x2,y2;
		cin>>x>>y;
		if(x%2==0)x2=x-1;else x2=x+1;
		if(y%2==0)y2=y-1;else y2=y+1;
		add(x,y2);//选了x就必须选y2 
		add(y,x2);//选了y就必须选x2
	}
	for(i=1;i<=2*n;i++)
		if(dfn[i]==0)dfs(i);
	for(i=1;i<=n;i++)
	{
		x=i*2;
		y=i*2-1;
		if(belong[x]==belong[y]){cout<<"NIE";return 0;}
	}
	for(i=1;i<=2*n;i++)
	{
		if(i%2==0)x=i-1;else x=i+1;
		opp[belong[i]]=belong[x];
	}
	for(i=1;i<=num;i++)
		if(bj[i]==0)bj[opp[i]]=1;
	for(i=1;i<=2*n;i++)
		if(bj[belong[i]]==0)cout<<i<<endl;
	return 0;
}
