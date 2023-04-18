KMP算法，又称模式匹配算法，能够在线性时间内判定字符串A[1~N]是否为字符串B[1~M]的子串,
并求出字符串A在字符串B中各次出现的位置。
详细地讲,KMP算法分为两步:
1.对字符串A进行自我“匹配”，求出一个数组Next，其中Next[i]表示
“A中以i结尾的非前缀子串”与“A的前缀”能够匹配的最长长度，即:
Next[i]=max{i}，其中j<i并且A[i-j+1~i]=A[1~j]
2.对字符串A与B进行匹配，求出一个数组f，其中f[i]表示“B中以i结尾的子串”与“A的前缀”能够匹配的最长长度，即:
f[i]=max{j}，其中j<=i并且B[i-j+1~i=A[1~j]
比如说有a串为abababaac,显然next[7]=5，next[5]=3,那么在求next[8]的时候
设j=next[7],先对比a[j+1]=a[6]是否等于a[8]，如果相同那么则next[8]=next[7]+1
但是显然不同，那么我们就让j=next[j]=3,然后再让a[j+1]比较a[8],
最后直到j==0就停止，这里的问题在于为什么要让j=next[j], 
ab/ababa/ac
   ababa/baac
这是next[7]=5,而next[5]=3则让前五位的前三位和后面5位的后三位相同 
因为前5位的x位和后5位的x位能够匹配的就是5位能匹配的最大位数5，所以可以用3来继续匹配 

for(i=1,j=0;i<=m;i++)//这是求a串在b串中出现的位置或者次数用的 
{ 
	while(j>0&&(j==n||b[i]!=a[j+1]))j=next[j];
	if(b[i]==a[j+1])j++;
	f[i]=j;
	//if(f[i]==n),此时就是A在B中的某一次出现
}

kmp 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define next Next
using namespace std;
ll n,m,next[mn],f[mn];
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	string s,s2;
	cin>>s2>>s;//s2为主串（b串），s为模式串（a串） 
	next[1]=0;
	n=s.length();
	s=" "+s;
	m=s2.length();
	s2=" "+s2;
	for(i=2,j=0;i<=n;i++)//这是a串在自匹配 
	{
		while(j>0&&s[i]!=s[j+1])j=next[j];
		if(s[i]==s[j+1])j++;
		next[i]=j;
	}
	for(i=1,j=0;i<=m;i++)//这是求a串在b串中出现的位置或者次数用的 
	{ 
		while(j>0&&(j==n||s2[i]!=s[j+1]))j=next[j];
		if(s2[i]==s[j+1])j++;
		f[i]=j;
		//if(f[i]==n),此时就是A在B中的某一次出现
	}
	for(i=1;i<=m;i++)
	if(f[i]==n)printf("%lld\n",i-n+1);
	for(i=1;i<=n;i++)
	printf("%lld ",next[i]);
	return 0;
}
