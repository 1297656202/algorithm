ac自动机比较难的题会与dp结合，然后题目难度就会直线上升，这里尽量给出模板和例题供人参悟
poj3691：DNA repair 
给一个DNA母串包含ACGT四个字符，和n个致病子串也是ACGT组成的
问最少修改几个字母能使母串不含任何一个子串，如果不能输出-1 
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
ll get(char ch)//此题特有 
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
	a[x].num=1;//标记致病子串 
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
			if(a[a[a[x].f].ch[i]].num)//这两行为重点，就是如果一个节点的fail节点为致病子串被标记过，
			a[a[x].ch[i]].num=1;//那么这个节点的前面一部分必然也是致病子串，同样该在在此节点处进行标记 
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)//这个函数是ac自动机加dp题的精髓所在 
{ll i,j,len=strlen(s),x,l,k;
	for(i=0;i<=len;i++)//len为整个主串长度 
		for(j=0;j<=cnt;j++)//cnt为trie树节点数 
		f[i][j]=inf;
	f[0][0]=0;
	for(i=0;i<len;i++)//这个dp是用已知f[i][j]去更新他能更新的下一个状态 
	{
		x=get(s[i]);
		for(j=0;j<=cnt;j++)
		{
			if(a[j].num)continue;//如果是致病节点可以直接跳过 
			for(k=0;k<=3;k++)//这个就是j节点下面的几个子节点的遍历 
			{
				l=a[j].ch[k];
				if(a[l].num)continue;//如果是致病节点可以直接跳过 
				f[i+1][l]=min(f[i+1][l],f[i][j]+(k==x?0:1));//如果k和主串上的字符x一样，则+0，否则+1 
			}
		}
	}
	//因为是用前一个节点更新后面一个，故答案存于f[len][i] 
	ans=inf;
	for(i=0;i<=cnt;i++)//遍历所有的trie树节点 
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
		for(i=0;i<=cnt;i++)//一种相对较好的清零方法 
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
