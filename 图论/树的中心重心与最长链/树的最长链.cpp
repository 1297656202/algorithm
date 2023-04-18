1 树形dp 
对于每个结点我们都要记录两个值：
d1[i]表示以i为根的子树中，i到叶子节点的距离最大值；
d2[i]表示以i为根的子树中，i到叶子节点的距离次大值；
令j是i的儿子。则：
①若d1[j]+1>d1[i]，则d2[i]=d1[i]; d1[i]=d1[j]+1;
②否则，若d1[j]+1>d2[i]，则d2[i]=d1[j]+1;
Answer=max{d1[i]+d2[i]}
void Treedp(int x,int prt)
{ 
	for(int i=h[x];i;i=a[i].next)
	{ 
		int y=a[i].to;
		if(y==prt)continue;//已经访问
		Treedp(y,x);
		if(d1[y]+1>d1[x])
		{ 
			d2[x]=d1[x];
			d1[x]=d1[y]+1;
		}
		else if(d1[y]+1>d2[x])d2[x]=d1[y]+1;
	}
}
2 两次dfs
从任意一点出发，到一个最远点之后，再到另一个最远点，连起来就是最长链
const int Maxn=200005;
struct Edge{int to,next;}a[2*Maxn];
int h[Maxn]={0},vst[Maxn],f[Maxn],N,cnt=0,Maxdep=0,st;
void AddEdge(int x,int y)
{ cnt++;a[cnt].to=y;a[cnt].next=h[x];h[x]=cnt;}
void Read()
{ 
	int i,x,y;
	cin>>N;
	for(i=1;i<N;i++){cin>>x>>y;AddEdge(x,y);AddEdge(y,x);}
}
void DFS(int x,int fa,int dep)
{ 
	int i,y;
	if(dep>Maxdep){Maxdep=dep;st=x;}
	for(i=h[x];i;i=a[i].next)
	{ 
		y=a[i].to;
		if(y==fa)continue;
		DFS(y,x,dep+1);
	}
}
void Solve()
{ 
	DFS(1,0,0);
	Maxdep=0;
	DFS(st,0,0);
	cout<<Maxdep<<endl;
}
