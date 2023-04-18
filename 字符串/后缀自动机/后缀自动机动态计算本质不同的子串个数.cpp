//luogu4070 [SDOI2016]生成魔咒：每次往一个字符串的后面加一个字符，求每次加入之后的本质不同的子串数量 
//这道题，因为SAM本来就是在线算法，所以可以每次把一个字符扔到SAM里面，每次将新增节点的贡献计算一下。
//为maxlen(q)-maxlen(fa(q))
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;//数组一般开到字符串长度的两倍 
ll b[mn],c[mn],sz[mn],s[mn],//只有小写字母才是26，sz[]为当前Endpos的集合大小，即i对应字符串集合的出现次数
fa[mn],l[mn],last,tot,//fa[]表示parent树上每个节点的父亲，l[]表示每个节点对应的字符串长度  
ans=0,n,m;
map<ll,ll>ch[mn];//如果当字符本身的范围特别大的时候，就需要用map/unordered_map
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
            ch[nq]=ch[q];//相应的memcpy也要改 
            fa[nq]=fa[q];fa[q]=fa[np]=nq;
            for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
        }
    }
    ans+=l[np]-l[fa[np]];//计算新增节点的贡献 
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	last=tot=1;//last是parent树的上一个节点，tot是parent树/sam上节点的总个数 
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		ins(s[i]);
		printf("%lld\n",ans);
	} 
	return 0;
}
