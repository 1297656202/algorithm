给出一个表达式,其中运算符仅包含+,-,*,/,^要求求出表达式的最终值
数据可能会出现括号情况 还有可能出现多余括号情况
数据保证不会出现>maxlongint的数据
数据可能回出现负数情况

#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> opt;stack<int> num;
string s;
int stat,i,cnt;
int solve(int l,int r)
{
	if(l>r) return 0;
	stat=0;
	for(int i=r;i>=l;--i) 
	{
		if(s[i]=='(') --stat;if(s[i]==')') ++stat;
		if(!stat&&(s[i]=='+'||s[i]=='-'))
		{
			int v1=solve(l,i-1),v2=solve(i+1,r);
			if(s[i]=='-') v2*=-1;
			return v1+v2;
		};
	};
	stat=0;
	for(int i=r;i>=l;--i) 
	{
		if(s[i]=='(') --stat;if(s[i]==')') ++stat;
		if(!stat&&(s[i]=='*'||s[i]=='/'))
		{
			int v1=solve(l,i-1),v2=solve(i+1,r);
			if(s[i]=='*') v1*=v2; else v1/=v2;
			return v1;
		};
	};
	stat=0;
	for(int i=r;i>=l;--i) 
	{
		if(s[i]=='(') --stat;if(s[i]==')') ++stat;
		if(!stat&&s[i]=='^')
		{
			int v1=solve(l,i-1),v2=solve(i+1,r);
			int ret=1;while(v2--) ret*=v1;
			return ret;
		};
	};
	if(s[l]=='('&&s[r]==')') return solve(l+1,r-1);
	int ret=0;
	for(int i=l;i<=r;++i) {ret=ret*10+s[i]-'0';};
	return ret;
}
int main()
{
	cin >> s;
	for(i=0;i<=s.length()&&s[i]==')';++i);s.erase(s.begin(),s.begin()+i);
	for(i=s.length()-1;i>=0&&s[i]=='(';--i);s.erase(s.begin()+i+1,s.end());
	for(i=0;i<s.length();++i) 
		{if(s[i]=='(') ++stat;if(s[i]==')') --stat;};
	// printf("stat=%d\n",stat);
	if(stat>0) 
		for(i=0,cnt=0;cnt<stat&&i<s.length();++i) 
			if(s[i]=='(') {s.erase(s.begin()+i);--i;++cnt;};
	if(stat<0)
	{
		stat*=-1;
		for(i=0,cnt=0;cnt<stat&&i<s.length();++i) 
			if(s[s.length()-i-1]==')') {s.erase(s.length()-i-1);++cnt;--i;};
	};
	printf("%d\n",solve(0,s.length()-1));
	return 0;
}
