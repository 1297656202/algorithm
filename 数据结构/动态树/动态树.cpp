#include<bits/stdc++.h>
#define inf 1000000000000000000
#define ll long long
#define maxn 600005
#define mod 51061
using namespace std;
long long ans=0,cnt=0,ge,r,n,m,
aux[maxn],v[maxn],s[maxn]={0},
rev[maxn]={0},
c[maxn][2],prt[maxn],
bj[maxn]={0},ls[maxn],rs[maxn],
cc[maxn],bj2[maxn],sz[maxn];
inline void read(long long &x){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   x=s*w;
}
void up(ll x)
{
	sz[x]=sz[c[x][0]]+sz[c[x][1]]+1;
	s[x]=(s[c[x][0]]+s[c[x][1]]+v[x])%mod;
}
void chen(ll x,ll y)
{
	s[x]*=y;s[x]%=mod;
	v[x]*=y;v[x]%=mod;
	bj2[x]*=y;bj2[x]%=mod;
	bj[x]*=y;bj[x]%=mod;	
}
void jia(ll x,ll y)
{
	s[x]+=sz[x]*y;s[x]%=mod;
	v[x]+=y;v[x]%=mod;
	bj[x]+=y;bj[x]%=mod;
}
void down(long long x)
{
	if(bj2[x]!=1)
    {
    	chen(c[x][0],bj2[x]);
    	chen(c[x][1],bj2[x]);
  		bj2[x]=1;
    }
    if(bj[x]>0)
    {
    	jia(c[x][0],bj[x]);
    	jia(c[x][1],bj[x]);
    	bj[x]=0;	
    }
    if(rev[x])
    {
        rev[x]=0;
        swap(c[x][0],c[x][1]);
        rev[c[x][0]]^=1;
        rev[c[x][1]]^=1;
    }
}
/*void up(long long x)
{
    if(c[x][0])down(c[x][0]);
    if(c[x][1])down(c[x][1]);
    tot[x]=tot[c[x][0]]+tot[c[x][1]]+v[x];
	if(rs[c[x][0]]==cc[x])tot[x]--;
	if(ls[c[x][1]]==cc[x])tot[x]--;
	if(c[x][0])ls[x]=ls[c[x][0]];
	else ls[x]=cc[x];
	if(c[x][1])rs[x]=rs[c[x][1]];
	else rs[x]=cc[x];
}*/
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
    up(x);
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
    if(find(y)!=x||prt[x]!=y||c[y][0]!=x||c[x][1])return;//Ö±½ÓÁ¬ 
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
	//freopen("count3.in","r",stdin);
	//freopen("1.out","w",stdout);
    long long f1,f2,x,he=0,y,len,t,i,j,k,l,r,z,p;
    char ch;
    cin>>n>>m;
    for(i=1;i<=n;i++)
       {
       v[i]=1;
	   sz[i]=1;
	   bj2[i]=1;
	   }
    for(i=1;i<=n-1;i++)
       {
       	scanf("%lld%lld",&x,&y);
       	link(x,y);
       }
    while(m--)
    {
    	scanf(" %c",&ch);
    	if(ch=='+')
    	{
    		scanf("%lld%lld%lld",&x,&y,&z);
    		ask(x,y);
    		jia(y,z);
    	}
    	if(ch=='-')
    	{
    		scanf("%lld%lld%lld%lld",&x,&y,&z,&k);
			cut(x,y);
			link(z,k);
    	}
		if(ch=='*')
    	{
    		scanf("%lld%lld%lld",&x,&y,&z);
    		ask(x,y);
    		chen(y,z);
    	}
    	if(ch=='/')
    	{
    		scanf("%lld%lld",&x,&y);
    		ask(x,y);
    		printf("%lld\n",s[y]);
    	}
    }
    return 0;
}
