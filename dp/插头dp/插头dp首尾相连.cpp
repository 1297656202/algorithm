#include<bits/stdc++.h>
#define ll long long//////////////
#define inf 1e18
#define maxn 100005///////////////
#define maxh 19997///////////////
#define maxs 20000///////////////
#define hash h
#define ii inline
using namespace std;
ll f[2][maxs],num[2],state[2][maxs],
a[15],b[15][15],p[15],q[15],hash[maxh],k1=0,k2,s1,last,X,Y,
ans=0,tot=0,cnt=0,sign=0,n,m,s,t;
void get(ll *a,ll s)
{ll i=1;
	while(s){a[i++]=s%3;s/=3;}
	while(i<=m+1)a[i++]=0;
}
void up(ll s2)
{ll i=s2%maxh;
	while(hash[i])
	{
		if(state[k2][hash[i]]==s2)
		{
			f[k2][hash[i]]+=f[k1][last];
			return ;
		}
		i=(i+1)%maxh;
	}
	hash[i]=++num[k2];
	state[k2][hash[i]]=s2;
	f[k2][hash[i]]=f[k1][last];
}
void shift(ll x,ll y)
{ll i,bra;
	if(b[x][y]==0){up(s1);return ;}
	if(p[y]==0&&p[y+1]==0&&b[x+1][y]&&b[x][y+1])
	{
		up(s1+a[y-1]+2*a[y]);
		return ;
	}
	if(p[y]==0&&p[y+1]!=0)
	{
		if(b[x][y+1])up(s1);
		if(b[x+1][y])up(s1-p[y+1]*a[y]+p[y+1]*a[y-1]);
	}
	if(p[y]!=0&&p[y+1]==0)
	{
		if(b[x+1][y])up(s1);
		if(b[x][y+1])up(s1-p[y]*a[y-1]+p[y]*a[y]);
	}
	if(p[y]==2&&p[y+1]==1)up(s1-2*a[y-1]-a[y]);
	if(p[y]==1&&p[y+1]==1)
	{
		bra=1;
		for(i=y+2;i<=m+1;i++)
		{
			if(p[i]==1)bra++;
			if(p[i]==2)bra--;
			if(bra==0)break;
		}
		up(s1-a[y-1]-a[y]-a[i-1]);
	}
	if(p[y]==2&&p[y+1]==2)
	{
		bra=1;
		for(i=y-1;i>0;i--)
		{
			if(p[i]==2)bra++;
			if(p[i]==1)bra--;
			if(bra==0)break;
		}
		up(s1-2*(a[y]+a[y-1])+a[i-1]);
	}
	if(p[y]==1&&p[y+1]==2&&x==X&&y==Y)
		up(s1-a[y-1]-2*a[y]);
}
int main()
{
    ll r,k,l,te,x,y,len,i,j,z;
    char ch;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    	for(j=1;j<=m;j++)
    	{
    		cin>>ch;
    		b[i][j]=(ch=='.');
    		if(b[i][j]){X=i;Y=j;}
    	}
    for(i=1,a[0]=1;i<=13;i++)
    	a[i]=a[i-1]*3;
    num[0]=1;state[0][1]=0;f[0][1]=1;
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=m;j++)
    	{
    		num[k2=(k1^1)]=0;
    		memset(hash,0,sizeof(hash));
    		for(last=1;last<=num[k1];last++)
    		{
    			s1=state[k1][last];
    			get(p,s1);
    			shift(i,j);
    		}
    		k1=k2;
    	}
    	for(j=1;j<=num[k2];j++)
    		state[k2][j]*=3;
	}	
	for(i=1;i<=num[k2];i++)
		ans+=f[k2][i];
	cout<<ans;
	return 0;
}
