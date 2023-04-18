#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll int
#define inf 1e18
#define maxn 10005
using namespace std;
ll cnt,rt[500005];
struct node{ll l,r;ll size,rnd,v;}t[500005*50];
void update(ll k)
{
    t[k].size=t[t[k].l].size+t[t[k].r].size+1;
}
void newnode(ll &k,ll x)
{
    t[k=++cnt].v=x;t[k].size=1;t[k].rnd=rand();
}
ll he(ll a,ll b)
{
    if(!a||!b)return a+b;
    if(t[a].rnd>t[b].rnd)
    {
        ll p=++cnt;t[p]=t[a];
        t[p].r=he(t[p].r,b);
        update(p);return p;
    }
    else
    {
        ll p=++cnt;t[p]=t[b];
        t[p].l=he(a,t[p].l);
        update(p);return p;
    }
}
void spl(ll now,ll k,ll &x,ll &y)
{
    if(!now)x=y=0;
    else
    {
        if(t[now].v<=k)
        {
            x=++cnt;t[x]=t[now];
            spl(t[x].r,k,t[x].r,y);
            update(x);
        }
        else 
        {
            y=++cnt;t[y]=t[now];
            spl(t[y].l,k,x,t[y].l);
            update(y);
        }
    }
}
void del(ll &root,ll w)
{
    ll x=0,y=0,z=0;
    spl(root,w,x,z);
    spl(x,w-1,x,y);
    y=he(t[y].l,t[y].r);
    root=he(he(x,y),z);
}
void ins(ll &root,ll w)
{
    ll x=0,y=0,z=0;
    spl(root,w,x,y);
    newnode(z,w);
    root=he(he(x,z),y);
}
ll getval(ll k,ll w)
{
    if(w==t[t[k].l].size+1)return t[k].v;
    else if(w<=t[t[k].l].size)return getval(t[k].l,w);
    else return getval(t[k].r,w-t[t[k].l].size-1);
}
ll getkth(ll &root,ll w)
{
    ll x,y;
    spl(root,w-1,x,y);
    ll ans=t[x].size+1;
    root=he(x,y);
    return ans;
}
ll qian(ll &root,ll w)
{
    ll x,y,k,ans;
    spl(root,w-1,x,y);
    if(!x)return -2147483647;
    k=t[x].size;
    ans=getval(x,k);
    root=he(x,y);
    return ans;
}
ll hou(ll &root,ll w)
{
    ll x,y,ans;
    spl(root,w,x,y);
    if(!y)return 2147483647;
    else ans=getval(y,1);
    root=he(x,y);
    return ans;
}
int main()
{
    ll n,f,w,tim;
    cout<<1;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        scanf("%d%d%d",&tim,&f,&w);
        rt[i]=rt[tim];
        if(f==1)ins(rt[i],w);
        else if(f==2)del(rt[i],w);
        else if(f==3)printf("%d\n",getkth(rt[i],w));
        else if(f==4)printf("%d\n",getval(rt[i],w));
        else if(f==5)printf("%d\n",qian(rt[i],w));
        else printf("%d\n",hou(rt[i],w));
    }
    return 0;
}
