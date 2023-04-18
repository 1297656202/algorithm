//给出一个长为 n 的数列，以及 n 个操作，操作涉及区间加法，询问区间内小于某个值 x 的前驱（比其小的最大元素）。
//别人的代码，这道题目主要是告诉我们在快里面嵌套set等其他数据结构的思路 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,t;
ll v[mn],pos[mn],tag[mn];
set<ll>st[505];
void add(ll a,ll b,ll c)
{ll i;
    for(i=a;i<=min(pos[a]*t,b);i++)
    {
        st[pos[a]].erase(v[i]);
        v[i]+=c;
        st[pos[a]].insert(v[i]);
    }
    if(pos[a]!=pos[b])
    {
        for(i=(pos[b]-1)*t+1;i<=b;i++)
        {
            st[pos[b]].erase(v[i]);
            v[i]+=c;
            st[pos[b]].insert(v[i]);
        }
    }
    for(i=pos[a]+1;i<=pos[b]-1;i++)
        tag[i]+=c;
}
ll query(ll a,ll b,ll c)
{ll i;
    ll ans=-1;
    for(i=a;i<=min(pos[a]*t,b);i++)
    {
        ll val=v[i]+tag[pos[a]];
        if(val<c)ans=max(val,ans);
    }
    if(pos[a]!=pos[b])        
        for(i=(pos[b]-1)*t+1;i<=b;i++)        
        {
            ll val=v[i]+tag[pos[b]];
            if(val<c)ans=max(val,ans);
        }
    for(i=pos[a]+1;i<=pos[b]-1;i++)
    {
        ll x=c-tag[i];
        set<ll>::iterator it=st[i].lower_bound(x);
        if(it==st[i].begin())continue;
        --it;
        ans=max(ans,*it+tag[i]);
    }
    return ans;
}
int main()
{ll i;
    n=read();t=sqrt(n);
    for(i=1;i<=n;i++)v[i]=read();
    for(i=1;i<=n;i++)
    {
        pos[i]=(i-1)/t+1;
        st[pos[i]].insert(v[i]);
    }
    for(i=1;i<=n;i++)//原题正好是n个操作  
    {
        ll f=read(),a=read(),b=read(),c=read();
        if(f==0)add(a,b,c);
        if(f==1)printf("%lld\n",query(a,b,c));
    }
    return 0;
}
