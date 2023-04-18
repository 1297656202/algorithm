#include<bits/stdc++.h>
#define ll long long
#define inf 100000000000000000
using namespace std;
ll cnt=0,ge,n,m,ans=0,l,r;string s[10005];
struct w{ll x,len,prt,l,r;}a[10005];
priority_queue<ll,vector<ll>,greater<ll> >q;
void bui(ll k)
{ll i,minn=inf,t;
	for(i=1;i<=k-1;i++)
		if(a[i].prt==0)
		if(a[i].x<minn)//这一步可以用堆优化，因为相当于求取所有树根节点的最小值 
	    {minn=a[i].x;t=i;}
	a[t].prt=k;
	a[k].l=t;
	minn=inf;
	for(i=1;i<=k-1;i++)
		if(a[i].prt==0)
	    if(a[i].x<minn)//这一步可以用堆优化，因为相当于求取所有树根节点的最小值  
	    {minn=a[i].x;t=i;}
	a[t].prt=k;
	a[k].r=t;
	a[k].x=a[a[k].l].x+a[a[k].r].x;
	if(k<2*n-1)bui(k+1);
}
string cal(ll i,string s)//这个是求哈夫曼编码 
{
	if(a[i].prt==0)return s;
	if(a[a[i].prt].l==i)s='0'+s;
	if(a[a[i].prt].r==i)s='1'+s;
	return cal(a[i].prt,s);
}
int main()
{
	ll h,t,minn,maxx,x,l1,l2,he=0,v,y,len,i,j,k,z;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].l=0;
		a[i].r=0;
	}
	bui(n+1);
	for(i=1;i<=n;i++)
		s[i]=cal(i,"");
	sort(s+1,s+n+1);
	for(i=1;i<=n;i++)
	    cout<<s[i]<<endl;
    return 0;
}
