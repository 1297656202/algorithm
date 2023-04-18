#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll n,m,ans,c[mn][2],v[mn],key[mn],s[mn],tot=0,rt=0;
void up(ll x)
{
	s[x]=s[c[x][0]]+s[c[x][1]]+1;
}
ll node(ll x)//新建一个权值为x的node 
{
    s[++tot]=1;
    v[tot]=x;
    key[tot]=rand();
    return tot;
}
ll merge(ll x,ll y)//合并x和y两个treap 
{
    if(x==0||y==0)return x+y;
    if(key[x]<key[y])
    {
        c[x][1]=merge(c[x][1],y);
        up(x);
        return x;
    }
    else
    {
        c[y][0]=merge(x,c[y][0]);
        up(y);
        return y;
    }
}
void split(ll z,ll k,ll &x,ll &y)//当前节点为z，把所有<=k的权值的节点分到x中，其他>k的放到y中 
{
    if(!z)x=y=0;
    else
    {
        if(v[z]<=k){x=z;split(c[z][1],k,c[z][1],y);}
        else {y=z;split(c[z][0],k,x,c[z][0]);}
        up(z);
    }
}
ll kth(ll x,ll k)//在x的子树里面查找排名为k的值
{
    while(1)
    {
        if(k<=s[c[x][0]])x=c[x][0];
        else if(k==s[c[x][0]]+1)return x;
        else {k-=s[c[x][0]]+1;x=c[x][1];}
    }
}
void ins(ll k)//插入k 
{ll x,y;
	split(rt,k,x,y);
	rt=merge(merge(x,node(k)),y);
}
void del(ll k)//删除k 
{ll x,y,z;
	split(rt,k,x,z);
    split(x,k-1,x,y);
    y=merge(c[y][0],c[y][1]);
    rt=merge(merge(x,y),z);
}
void find(ll k)//查询k的排名 
{ll x,y;
    split(rt,k-1,x,y);
    printf("%lld\n",s[x]+1);
    rt=merge(x,y);
}
void findk(ll k)//查询排名为k的数 
{
	printf("%lld\n",v[kth(rt,k)]);
}
void qian(ll k)//求k的前驱 
{ll x,y;
	split(rt,k-1,x,y);
    printf("%lld\n",v[kth(x,s[x])]);
    rt=merge(x,y);
}
void hou(ll k)//求k的后继  
{ll x,y;
	split(rt,k,x,y);
    printf("%lld\n",v[kth(y,1)]);
    rt=merge(x,y);
}
void dfs(ll x)//遍历平衡树输出序列,调试用 
{
	if(c[x][0])dfs(c[x][0]);
	if(abs(v[x])!=inf)printf("%lld ",v[x]);
	if(c[x][1])dfs(c[x][1]);
}
int main()
{
    srand((unsigned)time(0));
    ll t,i,j,k,x,y,z;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&k,&x);
        if(k==1)ins(x);
        if(k==2)del(x); 
        if(k==3)find(x);
        if(k==4)findk(x);
        if(k==5)qian(x);
		if(k==6)hou(x);
    }
}
