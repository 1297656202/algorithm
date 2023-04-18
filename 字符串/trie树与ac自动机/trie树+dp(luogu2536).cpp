每个RNA片段都是由A、C、T、G组成的序列。科学家们也总结出了Samuel星球上的"病毒模版片段"。
一个模版片段是由A、C、T、G的序列加上通配符 * 和 ? 来表示。
其中 * 的意思是可以匹配上0个或任意多个字符，而 ? 的意思是匹配上任意一个字母。
如果一个RNA片段能够和"病毒模版片段"相匹配，那么这个RNA片段就是未知的病毒。
例如，假设"病毒模版片段"为A*G?C。RNA片段：AGTC，AGTGTC都是未知的病毒，而RNA片段AGTGC则不是病毒。
现在请你为小联编写程序统计哪些RNA片段不是病毒。
思路：因为是从头匹配到尾，所以只用trie树就可以了，不需要用ac自动机
就是过RNA片段构造trie树，然后让模式串去bfs他能够构造出来的所有串，
(ww){x,y}为在trie树上的x节点处，模式串的第y个字符
因为只bfs会超时，所以要用bitset作为vis数组优化（如果用bool会爆内存） 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1005
using namespace std;
ll cnt=0,ans=0,n,m;
struct w{ll ch[4],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn*mn];
char ss[mn];
char s[mn];
struct ww{ll x,y;};
queue<ww>q;
ll get(char ch)//此题特有 
{
	if(ch=='A')return 0;
	if(ch=='G')return 1;
	if(ch=='C')return 2;
	if(ch=='T')return 3;
	if(ch=='*')return 4;
	if(ch=='?')return 5;
}
void ins(char *s)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=get(s[i]);
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	a[x].num++;//标记致病子串 
}
bitset<1005>vis[505*505];
int main()
{
	ll t=0,i,j,k,z,y,x;
	char ch;
	scanf("%s",ss);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	ll len=strlen(ss);
	q.push((ww){0,0});
	while(q.empty()==0)
	{
		ww u=q.front();
		q.pop();
		x=u.x;
		y=u.y;
		if(vis[x][y])continue;
		vis[x][y]=1;
		if(y==len)
		{
			ans+=a[x].num;
			a[x].num=0;
			continue;
		}
		k=get(ss[y]);
		if(k<=3)
		{
			if(a[x].ch[k]&&vis[a[x].ch[k]][y+1]==0)
			q.push((ww){a[x].ch[k],y+1});
		}
		else if(k==5)
		{
			for(i=0;i<=3;i++)
			if(a[x].ch[i]&&vis[a[x].ch[i]][y+1]==0)q.push((ww){a[x].ch[i],y+1});
		}
		else 
		{
			q.push((ww){x,y+1});
			for(i=0;i<=3;i++)
			if(a[x].ch[i])
			{
				if(vis[a[x].ch[i]][y]==0)q.push((ww){a[x].ch[i],y});
				if(vis[a[x].ch[i]][y+1]==0)q.push((ww){a[x].ch[i],y+1});
			}
		}
	}
	cout<<n-ans;
	return 0;
}
