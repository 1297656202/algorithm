铺砖问题(PKU2411)1816
有一个W行H列的棋盘，你可以在里放1*2的长方形，长方形之间互相不重叠，问放满整个棋盘有多少种方案数。

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll s,t,f[12][5000],cnt=0,ge,n,m;
ll check(ll x)//检验x这种状态是否合法，即连续偶数个1，只有这样一行才能被1*2的长方形构成
{ll cnt=0;
   	while(x>0)
	{
		if(x&1)cnt++;
		else if(cnt&1)return 0;
		x>>=1;
	}
	if(cnt&1)return 0;
	return 1;
}
ll ok(ll a,ll b)//检验当前行状态为a，前一行状态为b是否兼容  
{ll i;
	for(i=1;i<(1<<m);)
	{
		if((a&i)==0&&(b&i)==0)return 0;//都为0，则不兼容
		if((a&i)&&(b&i))//都为1，则需要判断后一位 
		{
			if((a&(i<<1))&&(b&(i<<1))){i<<=2;continue;}	
			else return 0;
		}
		i<<=1;
	}
	return 1;
}
int main()
{
	ll x,y,i,j,k,l,z;
	char ch;
	while(cin>>n>>m)
	{
		if(n*m%2==1){cout<<0<<endl;continue;}
	    if(n<m)swap(n,m);
	    memset(f,0,sizeof(f));
		k=1<<m;
	    for(i=0;i<=k-1;i++) 	
	    if(check(i))f[1][i]=1;
	    for(i=2;i<=n;i++)
	    	for(j=0;j<=k-1;j++)
	    	    for(l=0;l<=k-1;l++)
	    	    if(ok(j,l))f[i][j]+=f[i-1][l];
	    cout<<f[n][k-1]<<endl;
	}
	return 0;
}
