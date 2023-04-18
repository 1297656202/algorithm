欧拉通路就是给一个图，存在一条回路从起点到终点把所边经过且每条边只经过一次。即为一笔画问题
欧拉回路就是从起点遍历所有的边一次最后回到起点，欧拉图为具有欧拉回路的图 

欧拉通路的判定条件： 
①图G是连通的，不能有孤立的点存在；
②对无向图来说：度数为奇数的点的个数为0或者2，并且这两个点一定是路径的起点和终点；
  对有向图来说：存在两个顶点，其入度不等于出度，其中一个点出度比入度大1，为路径的起点；
另一点入度比出度大1，为路径的终点。其余每个顶点的入度要等于出度；

判断一个图G有欧拉回路，需要满足的两个条件： 
①图G是连通的，不能有孤立的点存在
②对无向图来说：度数为奇数的点的个数为0
对有向图来说：每个顶点的入度要等于出度

寻找欧拉路径（默认存在）：
首先根据题意以及判定先确定起点 S。
从起点 S开始 dfs 。
用前向星实现：
void DFS(int x)
{ 
	for(int i=h[x];i;i=edge[i].next)
	if(!vst[i])
	{ 
		vst[i]=1;//标记当前边
		vst[i^1]=1;//标记反向的另一条边DFS(edge[i].to);
		ans[++ans[0]]=x;//回溯过程中记录边
	}
}

模板：求有向图字典序最小的欧拉路径：总时间复杂度：O(n+mlogm)

注意，这个题目是不需要判断整张图是否联通的，但是有些题目是需要的，要注意 
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll anst,n,m,d[mn][2],del[mn],cnt[2]={0,0};//记录入度和出度 
stack<ll>s;
vector<ll>a[mn];
void dfs(ll x)
{ll i;
	for(i=del[x];i<a[x].size();i=del[x])
	{ 
		del[x]=i+1;
		dfs(a[x][i]);
	}
	s.push(x);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
    for(i=1;i<=m;i++){scanf("%lld%lld",&x,&y);a[x].push_back(y);d[x][1]++;d[y][0]++;}  
    for(i=1;i<=n;i++)sort(a[i].begin(),a[i].end());//字典序最小 
    ll st=1; //记录
    bool flag=1; //flag=1表示,所有的节点的入度都等于出度,
    for(i=1;i<=n;i++)
	{
        if(d[i][1]!=d[i][0])flag=0;
        if(d[i][1]-d[i][0]==1/*出度比入度多1*/){cnt[1]++;st=i;}
        if(d[i][0]-d[i][1]==1/*入度比出度多1*/)cnt[0]++;
    }
    if((!flag)&&!(cnt[0]==cnt[1]&&cnt[0]==1)){printf("No");return 0;}
	//不满足欧拉回路的判定条件，也不满足欧拉路径的判定条件，直接输出"No" 
    dfs(st);
    while(!s.empty()){printf("%d ",s.top());s.pop();}
	return 0;
}
