//洛谷P3804给定一个只包含小写字母的字符串S。
//请你求出S的所有出现次数不为1的子串的出现次数乘上该子串长度的最大值。

//sz[i]代表节点的Endpos集合大小，也可以说是i号点字符串集合在整个串中的出现次数，从parent树上累加即可 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 4000005
using namespace std;//数组一般开到字符串长度的两倍 
//ch[][]对应的是自动机上的边，自动机相当于一颗压缩的trie树，fa[]对应的是parent树上每个节点的父亲
ll b[mn],c[mn],sz[mn],ch[mn][26],//只有小写字母才是26，如果字符范围过大要用map 
//sz[]为当前Endpos的集合大小，即i对应字符串集合的出现次数
fa[mn],l[mn],last,tot,//l[]表示节点对应的endpos对应的最长的字符串长度maxlen 
ans=0,n,m;
char s[mn];
void ins(ll c)//插入一个字符  
{ll p=last,np=++tot;last=np;l[np]=l[p]+1;
    for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
    if(!p)fa[np]=1;
    else
	{
        ll q=ch[p][c];
        if(l[p]+1==l[q])fa[np]=q;
        else
		{
            ll nq=++tot;l[nq]=l[p]+1;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            fa[nq]=fa[q];fa[q]=fa[np]=nq;
            for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
        }
    }
    sz[np]=1;//新插入的节点就是np，可以对np进行初始化 
}
//下面这种是dfs的写法 
struct w{ll next,to;}a[mn*2];ll h[mn],cnt=0;
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
ll dfs(ll x)
{ll i,y;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		sz[x]+=sz[y];
	}
	if(sz[x]!=1)ans=max(ans,sz[x]*l[x]);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	scanf("%s",s+1);
	ll len=strlen(s+1);
	last=tot=1;//last是parent树的上一个节点，tot是parent树/sam上节点的总个数 
	for(i=1;i<=len;i++)ins(s[i]-'a');
	for(i=2;i<=tot;i++)add(fa[i],i);
    dfs(1);
    printf("%lld\n",ans);
	return 0;
}

下面这种是基数排序的做法，前面插入的部分是一样的 
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	scanf("%s",s+1);
	ll len=strlen(s+1);
	last=tot=1;//last是parent树的上一个节点，tot是parent树/sam上节点的总个数 
	for(i=1;i<=len;i++)ins(s[i]-'a');
	//这一段是在基数排序，也可以不用这个的 
	for(i=1;i<=tot;i++)c[l[i]]++;
    for(i=1;i<=tot;i++)c[i]+=c[i-1];
    for(i=1;i<=tot;i++)b[c[l[i]]--]=i;
   	//从大到小枚举，实际上在模拟parent树的DFS
    for(i=tot;i>=1;i--)
	{
        x=b[i];
        sz[fa[x]]+=sz[x];
        if(sz[x]>1)ans=max(ans,sz[x]*l[x]);
    }
    printf("%lld\n",ans);
	return 0;
}
