G����ͨͼ����u��V(G)��G-u������ͨ�����u��G�ĸ�㡣
void dfs(ll x)//���� 
{ll i,y; 
	sign++;
	dfn[x]=sign; //��x���շ���˳����Ⱥ���Ϊsign
	low[x]=sign; //��low[x]����ʼֵ
	for(i=h[x];i;i=w[i].next) //Ѱ��һ��x�����ڽڵ�y
	{
		y=w[i].to;
		if(prt[x]!=y)//x��y�б������Ҳ��ǻر�
		{ 
			if(dfn[y]==0) //yδ������
			{ 
				prt[y]=x; //��x��y�ĸ���
				dfs(y); //xy�Ǹ��ӱߣ��ݹ����x
				low[x]=min(low[x],low[y]);//���ж�������Сֵ
				if(low[y]>=dfn[x])
				{ 
					if(!mark[x]){ans++;mark[x]=1;}
					if(dfn[x]==1){root=x;son++;}
				}
			}
			else low[x]=min(low[x],dfn[y]); //xy�Ƿ����
		}
	}
}

������ͨͼ����߾���ɾ�������ߺ�ʹͼ������ͨ���������
void dfs(ll x)//���� 
{ll i,y;
	sign++;
	dfn[x]=sign; //��x���շ���˳����Ⱥ���Ϊsign
	low[x]=sign; //��low[x]����ʼֵ
	for(i=h[x];i;i=w[i].next) //Ѱ��һ��x�����ڽڵ�y
	{
		y=w[i].to;
		if(prt[x]!=y)//x��y�б������Ҳ��ǻر�
		{ 
			if(dfn[y]==0) //yδ������
			{ 
				prt[y]=x; //��x��y�ĸ���
				dfs(y); //xy�Ǹ��ӱߣ��ݹ����x
				low[x]=min(low[x],low[y]);//���ж�������Сֵ
				if(low[y]>dfn[x])//xy�Ǹ��
			}
			else low[x]=min(low[x],dfn[y]); //xy�Ƿ����
		}
	}
}

û�и���ͼ��2-��ͨͼ��������飬G�гɿ�ļ�����ͼ����G�Ŀ顣
��ÿ����������һ���㣬�͵õ�һ���������ı߾����š�
void dfs(ll x)//����ͼ�ķֿ� 
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
