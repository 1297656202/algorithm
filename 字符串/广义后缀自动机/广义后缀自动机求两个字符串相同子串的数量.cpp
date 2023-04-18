//P3181 [HAOI2016]找相同字符
//两个字符串，求出在两个字符串中各取出一个子串使得这两个子串相同的方案数。

//如上黑体字所说，两个串的 |endpos|分开计算，可以开一个二维数组，用siz[x][id]表示节点x在串id的{endpos}大小。
//则答案为：∑siz[i][0]×siz[i][1]×(maxlen[i]-maxlen[fa[i]]) 。 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;//数组一般开到字符串长度的两倍 
//ch[][]对应的是自动机上的边，自动机相当于一颗压缩的trie树，fa[]对应的是parent树上每个节点的父亲
ll b[mn],c[mn],sz[mn][2],ch[mn][26],//只有小写字母才是26，如果字符范围过大要用map 
//sz[]为当前Endpos的集合大小，即i对应字符串集合的出现次数
fa[mn],l[mn],last,tot,ru[mn],//l[]表示节点对应的endpos对应的最长的字符串长度maxlen 
ans=0,n,m;
char s[mn];
queue<ll>q;
ll ins(ll k,ll id)//插入一个新的节点，每个return语句返回的就是最后一个插入的节点 
{ll i;
    if(ch[last][k])
	{
	    ll p=last,x=ch[p][k];
	    if(l[p]+1==l[x]){sz[x][id]=1;return x;}//即最初的特判1
	    else
		{
	 	    ll y=++tot;l[y]=l[p]+1;
	    	for(i=0;i<26;i++)ch[y][i]=ch[x][i];
	    	while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
	    	fa[y]=fa[x];fa[x]=y;
	    	sz[y][id]=1;return y;//即最初的特判2
		}
    }
    ll z=++tot,p=last;l[z]=l[last]+1;
    while(p&&!ch[p][k]){ch[p][k]=z;p=fa[p];}
    if(!p)fa[z]=1;
    else
	{
        ll x=ch[p][k];
        if(l[p]+1==l[x])fa[z]=x;
        else
		{
            ll y=++tot;l[y]=l[p]+1;
            for(i=0;i<26;++i)ch[y][i]=ch[x][i];
            while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
            fa[y]=fa[x];fa[z]=fa[x]=y;
        }
    }
    sz[z][id]=1;
    return z;
}
int main()
{
	ll x,y,z,i,j,k;
	tot=1;
	for(i=0;i<=1;i++)
	{
		scanf("%s",s+1);
		last=1;
		for(j=1;s[j];j++)last=ins(s[j]-'a',i);
	}
	for(i=2;i<=tot;i++)++ru[fa[i]];
    for(i=1;i<=tot;i++)if(!ru[i])q.push(i);
    while(!q.empty())
	{
        x=q.front();q.pop();
        sz[fa[x]][0]+=sz[x][0];
        sz[fa[x]][1]+=sz[x][1];
        if(!(--ru[fa[x]]))q.push(fa[x]);
    }
    for(i=2;i<=tot;i++)
        ans+=sz[i][0]*sz[i][1]*(l[i]-l[fa[i]]);
    printf("%lld\n",ans);
	return 0;
}
