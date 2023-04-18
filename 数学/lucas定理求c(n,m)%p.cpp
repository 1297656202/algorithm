//求C(n,m)%P的值，其中：n,m是非负整数，P是素数
//一般用于n,m很大而P很小或n,m不大且都大于P的情形
//Lucas(n,m,p)=C(n%p,m%p)*Lucas(n/p,m/p,p)
//Lucas(n,m)即为n个里面选m个的组合数答案 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll a[mn],ans,p;
ll cal(ll x,ll t)
{ll ret=1;
    for(;t;t/=2,x=x*x%p) 
		if(t%2==1)ret=ret*x%p;
    return ret;
}
ll C(ll n,ll m)
{
	if(m>n)return 0;
	return (a[n]*cal(a[m],p-2)%p*cal(a[n-m],p-2)%p);
}
ll lucas(ll n,ll m)
{
	if(m==0)return 1;
	return C(n%p,m%p)*lucas(n/p,m/p)%p;
}
int main()
{
	ll n,m,x,y,z,i,j,k,t;
	char ch;
	cin>>t;
    while(t--)
	{
        cin>>n>>m>>p;
        a[0]=1;
        for(i=1;i<=p;i++)
        	a[i]=(a[i-1]*i)%p;
        cout<<lucas(n+m,n)<<endl;
    }
    return 0;
}
