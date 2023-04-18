#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll n,m,ans,c[mn][2],v[mn],mx[mn],
tag[mn],rev[mn],sum[mn],
key[mn],s[mn],tot=0,rt=0;
void up(ll x)//上传标记 
{ll l=c[x][0],r=c[x][1];
	mx[x]=max(max(mx[l],mx[r]),v[x]);
	sum[x]=sum[l]+sum[r]+v[x];
	s[x]=s[l]+s[r]+1;
}
void down(ll x)//下传标记 
{ll l=c[x][0],r=c[x][1];
	if(tag[x])
	{
		if(l){tag[l]+=tag[x];mx[l]+=tag[x];v[l]+=tag[x];sum[l]+=tag[x]*s[l];}
		if(r){tag[r]+=tag[x];mx[r]+=tag[x];v[r]+=tag[x];sum[r]+=tag[x]*s[r];}
		tag[x]=0;
	}
	if(rev[x])
	{
		rev[x]=0;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}	
}
ll node(ll x)//新建一个权值为x的node 
{
    s[++tot]=1;
    v[tot]=x;
    mx[tot]=x;
    key[tot]=rand();
    return tot;
}
ll merge(ll x,ll y)//合并x和y两个treap 
{ll z;
	down(x);down(y);
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
void split(ll z,ll k,ll &x,ll &y)//当前节点为z，把所有>=k编号的节点分到y中，其他<k的放到x中 
{
    if(!z){x=y=0;return ;}
    down(z);
    if(k<=s[c[z][0]]){y=z;split(c[z][0],k,x,c[z][0]);}
    else {x=z;split(c[z][1],k-s[c[z][0]]-1,c[z][1],y);}
    up(z);
}
void ins(ll k)//插入k 
{ll x,y;
	split(rt,k,x,y);
	rt=merge(merge(x,node(k)),y);
}
void add(ll l,ll r,ll k)
{ll x,y,z;
	split(rt,l-1,x,y);
	split(y,r-l+1,y,z);
	mx[y]+=k;
	tag[y]+=k;
	v[y]+=k;
	sum[y]+=k*s[y];
	rt=merge(merge(x,y),z);
}
void Rev(ll l,ll r)
{ll x,y,z;
	split(rt,l-1,x,y);
	split(y,r-l+1,y,z);
	rev[y]^=1;
	rt=merge(merge(x,y),z);
}
void Max(ll l,ll r)
{ll x,y,z;
    split(rt,l-1,x,y);
    split(y,r-l+1,y,z);
    printf("%lld\n",mx[y]);
    rt=merge(merge(x,y),z);
}
void Sum(ll l,ll r)
{ll x,y,z;
    split(rt,l-1,x,y);
    split(y,r-l+1,y,z);
    printf("%lld\n",sum[y]);
    rt=merge(merge(x,y),z);
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
    cin>>n>>m;
	mx[0]=-inf;//因为up的时候l或r可能等于0 
    for(i=1;i<=n;i++)ins(0);
    while(m--)
    {
    	scanf("%lld%lld%lld",&k,&x,&y);
    	if(k==1){scanf("%lld",&z);add(x,y,z);}
    	if(k==2)Rev(x,y);
    	if(k==3)Max(x,y);
    	if(k==4)Sum(x,y);
	}
    return 0;
}
