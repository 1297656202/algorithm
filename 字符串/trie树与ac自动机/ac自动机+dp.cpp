ac�Զ����Ƚ��ѵ������dp��ϣ�Ȼ����Ŀ�ѶȾͻ�ֱ�����������ﾡ������ģ������⹩�˲���
poj3691��DNA repair 
��һ��DNAĸ������ACGT�ĸ��ַ�����n���²��Ӵ�Ҳ��ACGT��ɵ�
�������޸ļ�����ĸ��ʹĸ�������κ�һ���Ӵ�������������-1 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1005
using namespace std;
ll cnt=0,ans=0,n,m,f[mn][mn];
struct w{ll ch[4],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn];
char s[mn];
queue<ll>q;
ll get(char ch)//�������� 
{
	if(ch=='A')return 0;
	if(ch=='G')return 1;
	if(ch=='C')return 2;
	if(ch=='T')return 3;
}
void ins(char *s,ll z)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=get(s[i]);
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	a[x].num=1;//����²��Ӵ� 
}
void bui()
{ll i,x;
	for(i=0;i<4;i++)
	if(a[0].ch[i])
	{
		a[a[0].ch[i]].f=0;
		q.push(a[0].ch[i]);
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=0;i<4;i++)
		if(a[x].ch[i])
		{
			a[a[x].ch[i]].f=a[a[x].f].ch[i];
			q.push(a[x].ch[i]);
			if(a[a[a[x].f].ch[i]].num)//������Ϊ�ص㣬�������һ���ڵ��fail�ڵ�Ϊ�²��Ӵ�����ǹ���
			a[a[x].ch[i]].num=1;//��ô����ڵ��ǰ��һ���ֱ�ȻҲ���²��Ӵ���ͬ�������ڴ˽ڵ㴦���б�� 
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)//���������ac�Զ�����dp��ľ������� 
{ll i,j,len=strlen(s),x,l,k;
	for(i=0;i<=len;i++)//lenΪ������������ 
		for(j=0;j<=cnt;j++)//cntΪtrie���ڵ��� 
		f[i][j]=inf;
	f[0][0]=0;
	for(i=0;i<len;i++)//���dp������֪f[i][j]ȥ�������ܸ��µ���һ��״̬ 
	{
		x=get(s[i]);
		for(j=0;j<=cnt;j++)
		{
			if(a[j].num)continue;//������²��ڵ����ֱ������ 
			for(k=0;k<=3;k++)//�������j�ڵ�����ļ����ӽڵ�ı��� 
			{
				l=a[j].ch[k];
				if(a[l].num)continue;//������²��ڵ����ֱ������ 
				f[i+1][l]=min(f[i+1][l],f[i][j]+(k==x?0:1));//���k�������ϵ��ַ�xһ������+0������+1 
			}
		}
	}
	//��Ϊ����ǰһ���ڵ���º���һ�����ʴ𰸴���f[len][i] 
	ans=inf;
	for(i=0;i<=cnt;i++)//�������е�trie���ڵ� 
	ans=min(ans,f[len][i]);
}
int main()
{
	ll t=0,i,j,k,z,y,x;
	char ch;
	while(cin>>n)
	{
		if(n==0)break;
		t++;
		for(i=0;i<=cnt;i++)//һ����ԽϺõ����㷽�� 
		{
			memset(a[i].ch,0,sizeof(a[i].ch));
			a[i].f=0;
			a[i].num=0;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			ins(s,i);
		}
		bui();
		scanf("%s",s);
		ac(s);
		if(ans==inf)ans=-1;
		printf("Case %lld: %lld\n",t,ans);
	}
	return 0;
}
