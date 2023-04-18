G是连通图，点u∈V(G)，G-u不再连通，则称u是G的割点。
void dfs(ll x)//求割点 
{ll i,y; 
	sign++;
	dfn[x]=sign; //给x按照访问顺序的先后标号为sign
	low[x]=sign; //给low[x]赋初始值
	for(i=h[x];i;i=w[i].next) //寻找一个x的相邻节点y
	{
		y=w[i].to;
		if(prt[x]!=y)//x→y有边相连且不是回边
		{ 
			if(dfn[y]==0) //y未被访问
			{ 
				prt[y]=x; //则x是y的父亲
				dfs(y); //xy是父子边，递归访问x
				low[x]=min(low[x],low[y]);//所有儿子中最小值
				if(low[y]>=dfn[x])
				{ 
					if(!mark[x]){ans++;mark[x]=1;}
					if(dfn[x]==1){root=x;son++;}
				}
			}
			else low[x]=min(low[x],dfn[y]); //xy是返祖边
		}
	}
}

对于连通图，割边就是删除这条边后使图不再连通，亦称做桥
void dfs(ll x)//求割边 
{ll i,y;
	sign++;
	dfn[x]=sign; //给x按照访问顺序的先后标号为sign
	low[x]=sign; //给low[x]赋初始值
	for(i=h[x];i;i=w[i].next) //寻找一个x的相邻节点y
	{
		y=w[i].to;
		if(prt[x]!=y)//x→y有边相连且不是回边
		{ 
			if(dfn[y]==0) //y未被访问
			{ 
				prt[y]=x; //则x是y的父亲
				dfs(y); //xy是父子边，递归访问x
				low[x]=min(low[x],low[y]);//所有儿子中最小值
				if(low[y]>dfn[x])//xy是割边
			}
			else low[x]=min(low[x],dfn[y]); //xy是返祖边
		}
	}
}

没有割点的图叫2-连通图，亦称做块，G中成块的极大子图叫做G的块。
把每个块收缩成一个点，就得到一棵树，它的边就是桥。
void dfs(ll x)//无向图的分块 
{ll i,y;
	low[x]=dfn[x]=++sign;
	s[++top]=x;
	for(i=h[x];i;i=a[i].next)
	{ 
		y=a[i].to;
		if(prt[x]!=y)
		{ 
			if(!dfn[y])
			{
				prt[y]=x;
				dfs(y);
				low[x]=min(low[x],low[y]);
			}
			else low[x]=min(low[x],dfn[y]);
		}
	}
		if(low[x]==dfn[x])
		{
			bcc++;
			do{
				y=s[top--];
				belong[y]=bcc;
			}while(y!=x);
		}
}
