//不含前导零且相邻两个数字之差至少为2的正整数被称为windy数。
//windy想知道，在a和b之间，包括a和b，总共有多少个windy数？

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll c[20],f[20][20],n,m;
//这里有一点，就是为什么状态里面不用记录前面有无前导零，因为我前导零的时候y=12，已经存储下来了 
ll suan(ll x,ll y,ll iszero,ll bj)//x当前位置,y前一位数,iszero判断前面是否全是0,bj最高位限制 
{ll i,k,s=0;
	if(x==0)return 1;
	if(bj==0&&~f[x][y])return f[x][y];
	if(bj==0)k=9;
	else k=c[x];
	for(i=0;i<=k;i++)
	if(abs(i-y)>=2)
	{
		if(iszero==1&&i==0)s+=suan(x-1,12,1,bj&&i==k);
		else s+=suan(x-1,i,0,bj&&i==k);
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
	return suan(c[0],12,1,1);
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	memset(f,-1,sizeof(f));
	while(cin>>x>>y)
	{
	   	cout<<ask(y)-ask(x-1)<<endl;
	}
    return 0;
}
