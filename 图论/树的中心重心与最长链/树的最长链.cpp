1 ����dp 
����ÿ��������Ƕ�Ҫ��¼����ֵ��
d1[i]��ʾ��iΪ���������У�i��Ҷ�ӽڵ�ľ������ֵ��
d2[i]��ʾ��iΪ���������У�i��Ҷ�ӽڵ�ľ���δ�ֵ��
��j��i�Ķ��ӡ���
����d1[j]+1>d1[i]����d2[i]=d1[i]; d1[i]=d1[j]+1;
�ڷ�����d1[j]+1>d2[i]����d2[i]=d1[j]+1;
Answer=max{d1[i]+d2[i]}
void Treedp(int x,int prt)
{ 
	for(int i=h[x];i;i=a[i].next)
	{ 
		int y=a[i].to;
		if(y==prt)continue;//�Ѿ�����
		Treedp(y,x);
		if(d1[y]+1>d1[x])
		{ 
			d2[x]=d1[x];
			d1[x]=d1[y]+1;
		}
		else if(d1[y]+1>d2[x])d2[x]=d1[y]+1;
	}
}
2 ����dfs
������һ���������һ����Զ��֮���ٵ���һ����Զ�㣬�������������
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
