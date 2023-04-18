//不要62和4 
//其实f数组里面是可以带上bj这一维的，只不过每一次开始的时候都要将f数组清为-1 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll c[20],f[20][2],n,m;
ll suan(ll x,ll y,ll bj)
{ll i,k,s=0;
	if(x==0)return 1;
	if(bj==0&&~f[x][y])return f[x][y];
	if(bj==0)k=9;
	else k=c[x];
	for(i=0;i<=k;i++)
	{
		if(i==4||(y&&i==2))continue;
		s+=suan(x-1,i==6,bj&&i==k);
	}
    if(bj==0)f[x][y]=s;
    return s;
}
ll ask(ll x)
{
	c[0]=0;
	while(x)
	{
		c[++c[0]]=x%10;
		x/=10;
	}
	return suan(c[0],0,1);
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	memset(f,-1,sizeof(f));
	while(cin>>x>>y)
	{
	   	if(x==0&&y==0)break;
	   	cout<<ask(y)-ask(x-1)<<endl;
	}
    return 0;
}
