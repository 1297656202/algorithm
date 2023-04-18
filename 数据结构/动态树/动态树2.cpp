//µØ∑…√‡—Ú 
#include<bits/stdc++.h>
#define inf 1000000000000000000
#define ll long long
using namespace std;
long long sz=0,rt=0,ans=0,cnt=0,ge,r,n,m,
aux[600005],v[600005],tot[600005]={0},
mx[600005],rev[600005]={0},
c[600005][2],prt[600005],s[600005];
inline void read(long long &x){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   x=s*w;
}
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
    tot[x]=tot[c[x][0]]+tot[c[x][1]]+1;
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
    if(find(y)!=x||prt[x]!=y||c[y][0]!=x||c[x][1])return;//÷±Ω”¡¨ 
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
    char ch[20];
    cin>>n;
    for(i=1;i<=n;i++)
       {
       scanf("%lld",&v[i]);
	   }
    for(i=1;i<=n;i++)
	if(i+v[i]<=n)
	link(i+v[i],i);
	else link(n+1,i);
    cin>>m;
    while(m--)
    {
		scanf("%lld",&k);
		if(k==1)
		{
			scanf("%lld",&x);
			x++;
			ask(x,n+1);
			printf("%lld\n",tot[n+1]-1);
		}
		if(k==2)
		{
			scanf("%lld%lld",&x,&y);
			x++;
			if(x+v[x]<=n)cut(x+v[x],x);
			else cut(n+1,x);
			v[x]=y;
			if(x+v[x]<=n)
			link(x+v[x],x);
			else link(n+1,x);
		}
	}
    return 0;
}
