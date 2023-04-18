//给出两个串S1，S2(只有大写字母)，求S1在S2中出现了多少次。
//显然也是kmp的模板题，不过这里用字符串hash来求解 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
#define inf 1e18
#define mn 1000005
#define p 1000000007
using namespace std;
ll ans,n,m;
ull b[mn],h[mn];
char s[mn],s2[mn];
ull id(char ch){return ch-'A';}
ull cal(ull *h,ll l,ll r)//我们计算出一个串的所有前缀hash值h[]之后，便可以O(1)求解任意子串的hash值 
{
	return h[r]-h[l-1]*b[r-l+1];
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>t;
	b[0]=1;
	for(i=1;i<mn;i++)
		b[i]=b[i-1]*p;
	while(t--)
	{
		scanf("%s",s+1);
		scanf("%s",s2+1);
		n=strlen(s+1);m=strlen(s2+1);
		ull sum=0;ans=0;
		for(i=1;i<=n;i++)
			sum=sum*p+id(s[i]);
		for(i=1;i<=m;i++)
			h[i]=h[i-1]*p+id(s2[i]);
		for(i=1;i<=m-n+1;i++)
		if(sum==cal(h,i,i+n-1))ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
