//树的统计，但是代码只有90分 
#include<bits/stdc++.h>
#define inf 1000000000000000000
#define ll long long
using namespace std;
long long sz=0,rt=0,ans=0,cnt=0,ge,r,n,m,
aux[160005],v[160005],tot[160005]={0},
mx[160005],rev[160005]={0},
c[160005][2],prt[160005];
void down(long long x)
{
    if(rev[x])
    {
        rev[x]=0;
        swap(c[x][0],c[x][1]);
        rev[c[x][0]]^=1;
        rev[c[x][1]]^=1;
    }
}
void up(long long x)
{
    tot[x]=tot[c[x][0]]+tot[c[x][1]]+v[x];
    mx[x]=max(mx[c[x][0]],max(mx[c[x][1]],v[x]));
}
void rot(long long x)
{long long y=prt[x],z=prt[y],l,r;
    l=(c[y][0]!=x);
    r=l^1;
    if(aux[y]){if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;}
        else {aux[y]=1;aux[x]=0;}
    prt[x]=z;
    prt[y]=x;
    prt[c[x][r]]=y;
    c[y][l]=c[x][r];
    c[x][r]=y;
    up(y);
    up(x);
}
void spl(long long x)
{
    down(x);
    while(aux[x])
    {
        long long y=prt[x],z=prt[y];
        if(aux[y])down(z);
        down(y);
        down(x);
        if(aux[y])
		{
		if(c[y][0]==x^c[z][0]==y)rot(x);
		else rot(y);
		}
        rot(x);
    }
}
void acc(long long x)
{
    long long y=0;
    while(x)
        {
            spl(x);
            aux[c[x][1]]=0;
            aux[y]=1;
            c[x][1]=y;
            prt[y]=x;
            y=x;
			up(x);
            x=prt[x];
        }
}
long long find(long long x)
{
    acc(x);
    spl(x);
    while(c[x][0])
        {
            down(x);
            x=c[x][0];
        }
    return x;
}
void fan(long long x)
{
    acc(x);
    spl(x);
    rev[x]^=1;
}
void cut(long long x,long long y)
{
    fan(x);
    acc(y);
    spl(y);
    prt[c[y][0]]=0;
    aux[c[y][0]]=0;
    c[y][0]=0;
}
void link(long long x,long long y)
{
    fan(y);
    prt[y]=x;
}
void ask(ll x,ll y)
{
    fan(x);
    acc(y);
    spl(y);
}
int main()
{
    long long f1,f2,x,he=0,y,len,t,i,j,k,l,r,z,p;
    char ch[10];
    cin>>n;
    memset(mx,-2,sizeof(mx));
    for(i=1;i<=n-1;i++)
      {
      	scanf("%lld%lld",&x,&y);
      	link(x,y);
      }
    for(i=1;i<=n;i++)
       scanf("%lld",&v[i]);
    cin>>m;
    while(m--)
    {
        scanf("%s%lld%lld",&ch,&x,&y);
        if(ch[0]=='C')
        {
            acc(x);
            spl(x);
            v[x]=y;
        }
        if(ch[1]=='S')
        {
            if(x==y){printf("%lld\n",v[x]);continue;}
            ask(x,y);
            printf("%lld\n",tot[y]);
        }
        if(ch[1]=='M')
        {
            if(x==y){printf("%lld\n",v[x]);continue;}
            ask(x,y);
            printf("%lld\n",mx[y]);
        }
    }
    return 0;
}
