#include<bits/stdc++.h>
#define ll long long 
#define inf 1000000000000000000
#define maxn 1000005
#define next next
using namespace std;
inline ll read()
{
    ll x=0,t=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-'){t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*t;
}
struct w{ll ch[2];ll val,ff,size;}t[maxn];
ll f[maxn];ll root[maxn],tot;ll hh[maxn];ll n,m;
ll gf(ll x)
{
	if(f[x]==x)return x;
	f[x]=gf(f[x]);
	return f[x];
}
void up(ll x)
{
    t[x].size=t[t[x].ch[0]].size+t[t[x].ch[1]].size+1;
}
void rotate(ll x)
{
    ll y=t[x].ff;
    ll z=t[y].ff;
    ll k=t[y].ch[1]==x;
    t[z].ch[t[z].ch[1]==y]=x;t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1];t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y;t[y].ff=x;
    up(y);up(x);
}
void spl(ll x,ll goal)
{
    while(t[x].ff!=goal)
    {
        ll y=t[x].ff,z=t[y].ff;
        if(z!=goal)
            (t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if(goal<=n)root[goal]=x;
}
void insert(ll x,ll bh)
{
    ll u=root[bh],ff=bh;
    while(u&&t[u].val!=x)
        ff=u,u=t[u].ch[x>t[u].val];
    u=++tot;
    t[u].size=1;
    t[u].ff=ff;
    if(ff>n)t[ff].ch[x>t[ff].val]=u;
    t[u].val=x;t[u].ch[0]=t[u].ch[1]=0;
    spl(u,bh);
}
void dfs(ll u,ll kk)
{
    if(t[u].ch[0])dfs(t[u].ch[0],kk);
    if(t[u].ch[1])dfs(t[u].ch[1],kk);
    insert(t[u].val,kk);
}
void link(ll a,ll b)
{
    ll x=gf(a),y=gf(b);
    if(x==y)return;
    if(t[root[x]].size>t[root[y]].size)swap(x,y);
    f[x]=y;
    dfs(root[x],y);
}
ll find(ll bh,ll k)
{
    ll u=root[bh];
    if(t[u].size<k)return -1;
    while(1)
    {
        if(t[t[u].ch[0]].size+1<k)
        {
            k-=t[t[u].ch[0]].size+1;
            u=t[u].ch[1];
        }
        else
            if(t[t[u].ch[0]].size>=k)
                u=t[u].ch[0];
            else
                return t[u].val;
    }
}
int main()
{
    n=read();
	m=read();
    for(ll i=1;i<=n;++i)
	root[i]=i+n,f[i]=i;
    tot=n+n;
    for(ll i=1;i<=n;++i)
    {
        ll x=read();
        hh[x]=i;
        t[i+n].val=x;
		t[i+n].size=1;
		t[i+n].ff=i;
    }
    for(ll i=1;i<=m;++i)
    {
        ll x=read(),y=read();
        link(x,y);
    }
    ll Q=read();
    while(Q--)
    {
        char ch[3];ll a,b;
        scanf("%s",ch);a=read(),b=read();
        if(ch[0]=='B')
        {
            link(a,b);
        }
        else
        {
            ll ans=find(gf(a),b);
            printf("%d\n",ans==-1?ans:hh[ans]);
        }
    }
    return 0;
}
