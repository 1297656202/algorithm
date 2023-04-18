//P6139 【模板】广义后缀自动机（广义 SAM）
//给定n个由小写字母组成的字符串，求本质不同的子串个数。（不包含空串）

//随便选一种方式建好自动机，答案为：∑maxlen[i]-maxlen[fa[i]]（原因见后缀自动机的动态计算本质不同的子串个数）
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2000005
using namespace std;//数组一般开到字符串长度的两倍 
//ch[][]对应的是自动机上的边，自动机相当于一颗压缩的trie树，fa[]对应的是parent树上每个节点的父亲
ll b[mn],c[mn],sz[mn],ch[mn][26],//只有小写字母才是26，如果字符范围过大要用map 
//sz[]为当前Endpos的集合大小，即i对应字符串集合的出现次数
fa[mn],l[mn],last,tot,//l[]表示节点对应的endpos对应的最长的字符串长度maxlen 
ans=0,n,m;
char s[mn];
ll ins(ll k)//插入一个新的节点，每个return语句返回的就是最后一个插入的节点 
{ll i;
    if(ch[last][k])
	{
	    ll p=last,x=ch[p][k];
	    if(l[p]+1==l[x])return x;//即最初的特判1
	    else
		{
	 	    ll y=++tot;l[y]=l[p]+1;
	    	for(i=0;i<26;i++)ch[y][i]=ch[x][i];
	    	while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
	    	fa[y]=fa[x];fa[x]=y;
	    	return y;//即最初的特判2
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
    return z;
}
int main()
{
	ll x,y,z,i,j,k;
	cin>>n;
	tot=1;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		last=1;
		for(j=1;s[j];j++)last=ins(s[j]-'a');
	}
	for(i=2;i<=tot;i++)
	ans+=l[i]-l[fa[i]];
	cout<<ans;
	return 0;
}
