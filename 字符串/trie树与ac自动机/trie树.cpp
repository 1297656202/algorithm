#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll cnt=0,n,m;
struct w{ll ch[26],bj;
void st()
{
	bj=0;
	memset(ch,0,sizeof(ch));
}
}a[mn];
void ins(string s)//将字符串s插入trie树 
{ll i,rt=0,y;
	for(i=0;i<s.length();i++)	
	{
		y=s[i]-'a';//这里根据题目进行变化 
		if(a[rt].ch[y]==0)
		{
			a[rt].ch[y]=++cnt;
			a[cnt].st();//这是输入多组数据用的 
			rt=cnt;
		}
		else rt=a[rt].ch[y];
	}
	a[rt].bj=1;
}
ll find(string s)//查找字符串在trie树中的位置 
{ll y,i,rt=0;
	for(i=0;i<s.length();i++)
	{
		y=s[i]-'a';//这里根据题目进行变化 
		if(a[rt].ch[y]==0)return 0;
		rt=a[rt].ch[y];
	}
	if(a[rt].bj)return 1;
	return 0;
}
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	string s;
	while(cin>>s)
	{
		
	}
	cout<<cnt+1;//这个是加上了根节点的 
	return 0;
}
