小数三分： 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 10005
#define eps 1e-10
using namespace std;
ll f[mn][105]={0},n,m,ans,b[mn],a[mn];
double H,h,d;
double cal(double x){return (h*d-H*x)/(d-x)+x;}
double div3(double l,double r)//现在是求解极大值，极小值则为 cal(mid)<cal(midd)
{
	while(l+eps<r)
	{
		double mid=l+(r-l)/3;
		double midd=r-(r-l)/3;
		if(cal(mid)>cal(midd))r=midd;
		else l=mid;
	}
	return l;
}
int main()
{
	ll t,i,j,k,z,y,x;
	char ch;
	cin>>t;
	while(t--)
	{
		cin>>H>>h>>d;
		cout<<fixed<<setprecision(3)<<cal(div3(0.0,h/H*d))<<endl;
	}
	return 0;
}

整数三分： 
ll div3(ll l,ll r)//现在是求解极大值，极小值则为 cal(mid)<cal(midd)
{
	while(l<r)
	{
		ll mid=l+(r-l)/3;
		ll midd=r-(r-l)/3;
		if(cal(mid)>cal(midd))r=midd-1;
		else l=mid+1;
	}
	return l;
}
