//用vector实现高精度算法,对不对不清楚,是用copilot生成的
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll ans,n,m;
vector<ll> a,b,c;
void add(vector<ll> &a,vector<ll> &b,vector<ll> &c)
{
	ll t=0;
	for(ll i=0;i<a.size()||i<b.size();i++)
	{
		if(i<a.size()) t+=a[i];
		if(i<b.size()) t+=b[i];
		c.push_back(t%10);
		t/=10;
	}
	if(t) c.push_back(t);
}
void sub(vector<ll> &a,vector<ll> &b,vector<ll> &c)
{
	ll t=0;
	for(ll i=0;i<a.size();i++)
	{
		t=a[i]-t;
		if(i<b.size()) t-=b[i];
		c.push_back((t+10)%10);
		if(t<0) t=1;
		else t=0;
	}
	while(c.size()>1&&c.back()==0) c.pop_back();
}
void mul(vector<ll> &a,ll b,vector<ll> &c)
{
	ll t=0;
	for(ll i=0;i<a.size();i++)
	{
		t+=a[i]*b;
		c.push_back(t%10);
		t/=10;
	}
	while(t)
	{
		c.push_back(t%10);
		t/=10;
	}
}
void div(vector<ll> &a,ll b,vector<ll> &c)
{
	ll t=0;
	for(ll i=a.size()-1;i>=0;i--)
	{
		t=t*10+a[i];
		c.push_back(t/b);
		t%=b;
	}
	reverse(c.begin(),c.end());
	while(c.size()>1&&c.back()==0) c.pop_back();
}
void print(vector<ll> &a)
{
	for(ll i=a.size()-1;i>=0;i--) cout<<a[i];
	cout<<endl;
}
void scan(vector<ll> &a)
{
	string s;
	if(!(cin>>s)) return;
	a.clear();
	for(ll i=s.size()-1;i>=0;i--) a.push_back(s[i]-'0');
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	
	return 0;
}
