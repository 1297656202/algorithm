如果想求a串是否可以表示为一个子串的循环 
定理:假设S的长度为len，则S存在循环子串，当且仅当,len可以被len - next[len]整除，最短循环子串为S[len - next[len]] 
证明:设S=q1q2q3q4q5q6q7q8，并设next[8]=6，此时str = S[len -next[len]]=q1q2，由字符串特征向量next的定义可知，
q1q2q3q4q5q6=q3q4q5q6q7q8，即有q1q2=q3q4，q3q4=q5q6,q5q6=q7q8即q1q2为循环子串，且易知为最短循环子串。
由以上过程可知，若len可以被len - next[len]整除，则S存在循环子串，否则不存在。
解法:利用KMP算法，求字符串的特征向量next，
若len可以被len - next[len]整除，则最大循环次数n为len/(len - next[len])，否则为1。

以下为求循环子串的代码 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define next Next
using namespace std;
ll n,m,next[mn];
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	string s;
	while(cin>>s)
	{
		if(s[0]=='.')break;
		next[1]=0;
		n=s.length();
		s=" "+s;
		for(i=2,j=0;i<=n;i++)//这是a串在自匹配 
		{
			while(j>0&&s[i]!=s[j+1])j=next[j];
			if(s[i]==s[j+1])j++;
			next[i]=j;
		}
		if(n%(n-next[n])==0)
		   cout<<n/(n-next[n])<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
