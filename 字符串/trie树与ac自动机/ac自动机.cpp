//这一文档只能解决最简单的ac自动机问题，更多见后面的ac自动机+dp部分，会更有借鉴意义 
N个模式串，一个主串，问在N个模式串中有几个出现在了主串里。
就相当于很多次kmp 
这种问题可以用ac自动机来解决
ac自动机的精髓在于fail指针，这个指针的作用和kmp的next数组很像，
fail指针指向的跟这个节点的字符是相同的（除非指向root），
并且被指向的节点到root节点的字符串和此节点往上的一部分字符串是相同的，
这意味着：既然你这次都可以匹配到这里，那么你同样可以从root匹配到fail指针处，这点上与kmp中next数组相似
详细见图
 
这种问题还有个很有意思的变形，就是如果想求某个串是否是某个串的前缀或者后缀，
这个时候，虽然我们仍然要进行模式匹配，但是有可能使得主串中间出现的某个部分与模式串相同而被误认为是前缀或者后缀，
这个时候，我们可以将模式串的前面（后面）加上'_'，
（或者是其他没用的符号，最好是有用字符的后面一个，比方说char('z'+1)之类的），这样就可以避免这种情况

例题：现有n个由小写字母组成的单词，然后给定m对小写的前缀与后缀。对于每对前缀与后缀，请你求出在n个单词中有多少个同时包含他们。
做法：将每个单词转化为：单词_单词
比如avtobus转为avtobus_avtobus
在前缀和后缀间添加下划线并反向插入AC自动机
比如abac a转为a_abac
接着依次匹配主串统计个数
注意可能有重复的字符串，需将统计写在树的内部
 
下面为ac自动机的普通版
给定n个模式串和一个文本串t，求有多少个不同的模式串在文本串里出现过。
仅仅只求出现过
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll cnt=0,ans=0,n,m;
struct w{ll ch[26],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[1000005];
char s[1000005];
queue<ll>q;
void ins(char *s)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	a[x].num++;
}
void bui()
{ll i,x;
	for(i=0;i<26;i++)
	if(a[0].ch[i])
	{
		a[a[0].ch[i]].f=0;
		q.push(a[0].ch[i]);
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=0;i<26;i++)
		if(a[x].ch[i])
		{
			a[a[x].ch[i]].f=a[a[x].f].ch[i];
			q.push(a[x].ch[i]);
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)
{ll i,j,t,len=strlen(s),x=0;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		x=a[x].ch[j];
		for(t=x;t&&~a[t].num;a[t].num=-1,t=a[t].f)//这个仅在只求出现过里有用，可以把num值为-1，后面就不用遍历了，因为我已经确认他出现过 
		ans+=a[t].num;
	}
}
int main()
{
	ll t,i,j,k,z,y,x;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	bui();
	scanf("%s",s);
	ac(s);
	cout<<ans;
	return 0;
}

给你一个文本串和n个模式串，请你分别求出每个模式串在文本串中出现的次数。
如果要求每个模式串出现的次数的话，就得遍历到底了
for(t=x;t&&~a[t].num;a[t].num=-1,t=a[t].f)//这个仅在只求出现过里有用，可以把num值为-1，后面就不用遍历了，因为我已经确认他出现过 
	ans+=a[t].num;//这是原来的写法 
for(t=x;t;t=a[t].f)//区别，相当于是在暴力跳fail，在trie树节点少的时候还可以这样用，节点多了就会爆 
	bj[t]++;
for(i=1;i<=n;i++)
ans=max(ans,bj[b[i]]);//b[i]为每个模式串在trie树上的终止节点
但是我们同样能有一种优化
然后的话，很多人用 AC 自动机进行多模匹配时都会暴力跳 fail 边，但这样做复杂度是错误的，
可以被类似于 aaaaa……aaaaa 这样的串卡掉。
因为此时每次跳fail只会使得深度减一，每次都会遍历整个trie树，复杂度为o（n*m） 
正确的做法是建出 fail 树，记录自动机上的每个状态被匹配了几次，只是在第一个匹配的节点++
容易猜到，每一次跳fail的过程，是非常像从树的叶子节点往根节点跳的，那么这条路上的节点的bj[x]都会++
这个过程完全可以用dfs统计子树的bj总和来解决 
以fail节点为prt向x建边，最后从root开始遍历，dfs一次， 
最后求出每个模式串在 Trie 上的终止节点在 fail 树上的子树总匹配次数就可以了。
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2000005
using namespace std;
ll bj[mn],h[mn],cnt=0,ans=0,n,m,b[mn],tot=0;
struct w{ll ch[26],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn];
struct ww{ll next,to;}c[mn];
char s[mn];
queue<ll>q;
void add(ll x,ll y)
{
	c[++tot]=(ww){h[x],y};
	h[x]=tot;
}
void dfs(ll x)
{ll i,y;
	for(i=h[x];i;i=c[i].next)
	{
		y=c[i].to;
		dfs(y);
		bj[x]+=bj[y];
	}
}
void ins(char *s,ll z)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a'; 
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	b[z]=x;
}
void bui()
{ll i,x;
	for(i=0;i<26;i++)
	if(a[0].ch[i])
	{
		a[a[0].ch[i]].f=0;
		q.push(a[0].ch[i]);
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=0;i<26;i++)
		if(a[x].ch[i])
		{
			a[a[x].ch[i]].f=a[a[x].f].ch[i];
			q.push(a[x].ch[i]);
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)
{ll i,j,len=strlen(s),x=0;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		x=a[x].ch[j];
		bj[x]++;//我们仅仅只是在第一个节点++ 
	}
}
int main()
{
	ll t,i,j,k,z,y,x;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s,i);
	}
	bui();
	scanf("%s",s);
	ac(s);
	for(i=1;i<=cnt;i++)
	add(a[i].f,i);
	//容易猜到，每一次跳fail的过程，是非常像从树的叶子节点往根节点跳的，那么这条路上的节点的bj[x]都会++
	//这个过程完全可以用dfs统计子树的bj总和来解决 
	dfs(0);
	for(i=1;i<=n;i++)
	printf("%lld\n",bj[b[i]]);
	return 0;
}
