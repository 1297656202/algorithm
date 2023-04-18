给你主串的长度l和n个模式串，n个模式串都要包含，让你求出主串共有多少种可能 
并且当可能小于42时，输出所有可能解

总结： 
我们经常通过trie树上的x节点的fail节点到root等于x节点向上一部分这个性质来进行dp或者优化 
因为这个性质实在是太好了，这意味着fail节点上的某些性质x节点上也会包含
比如只求出现多少模式串的ac自动机通过将已经跳过的fail节点置为-1（因为值为-1的我们都确定已经出现过）
，故再次遍历到-1便可以跳过 
比如求每个模式串出现多少次ac自动机的通过fail边建树，因为一个节点被匹配意味着它的所有fail节点又能匹配一次，
而这种链上都+1的情况可以用树统计子树sz的方法来优化而免去暴力跳边 
比如下面的这个题
通过trie树上一个节点x的fail到root等于x向上一部分，则fail能包含的模式串，x也一定包含
这个性质用来进行状压dp从而得知匹配到这个节点包含的模式串同时也匹配到了哪些模式串
而不用去暴力跳边 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1055
using namespace std;
ll cnt=0,ans=0,n,m,f[26][105][mn],h[26*105*mn*2],tot=0;
struct w{ll ch[26],f,num;char z;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn];
char s[mn];
queue<ll>q;
ll sign=0;
string ss[50];
struct ww{ll next,to;char z;}c[26*105*mn*10];
ll cal(ll i,ll j,ll k)
{
	return i*(cnt+1)*(1<<n)+j*(1<<n)+k;
}
void add(ll x,ll y,char z)
{
	c[++tot]=(ww){h[x],y,z};
	h[x]=tot;
}
void dfs(ll x,string s,ll k)
{ll i,y;
	if(k==1)
	{
		ss[++sign]=s;
		return ;
	}
	for(i=h[x];i;i=c[i].next)
	{
		y=c[i].to;
		dfs(y,c[i].z+s,k-1);
	}
}
void ins(char *s,ll z)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		if(a[x].ch[j]==0)
		{
			a[x].ch[j]=++cnt;
			a[cnt].z=s[i];//记录每个节点的字母 
		}
		x=a[x].ch[j];
	}
	a[x].num=(1<<(z-1));
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
			//下面为重点，因为trie树上一个节点x的fail到root等于x向上一部分，则fail能包含的模式串，x也一定包含 
			a[a[x].ch[i]].num|=a[a[a[x].f].ch[i]].num;
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(ll len)//这个函数是ac自动机加dp题的精髓所在 
{ll i,j,l,k,x;
	f[0][0][0]=1;
	for(i=0;i<len;i++)//f[i][j][k]表示的是正在匹配第i个字符时
		for(j=0;j<=cnt;j++)//正好在trie树上的第j个节点
			for(k=0;k<=(1<<n)-1;k++)//k是状压，表示已经包含哪些模式串 
				for(l=0;l<26;l++)//l为j节点下面节点的遍历 
				{
					x=a[j].ch[l];//x为j下面的节点 
					f[i+1][x][k|a[x].num]+=f[i][j][k];//用f[i][j][k]来更新f[i+1][x][k|a[x].num] 
					//如果结果范围在42以内，我们可以对每一次dp有贡献的节点连边，最后倒过来遍历得出可行解  
					if(f[i][j][k]>0&&f[i][j][k]<=42)add(cal(i+1,x,k|a[x].num),cal(i,j,k),a[j].z);
				}
	ans=0;
	for(i=0;i<=cnt;i++)//因为是用前面一个更新后面一个，所以答案在f[len][i(所有节点)][满状态] 
	ans+=f[len][i][(1<<n)-1];
}
int main()
{
	ll t=0,i,j,k,z,y,x;
	char ch;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s,i);
	}
	bui();
	ac(m);
	cout<<ans<<endl;
	if(ans<=42)
	{
		string s="";
		for(i=0;i<=cnt;i++)
		dfs(cal(m,i,(1<<n)-1),a[i].z+s,m);
		sort(ss+1,ss+sign+1);
		for(i=1;i<=sign;i++)
		cout<<ss[i]<<endl;
	}
	return 0;
}
