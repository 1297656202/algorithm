#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define mn 100005
ll rnd(ll l,ll r)
{
    return rand()*rand()%(r-l+1)+l;
}
ll rnd(ll n)
{
	return rand()*rand()%n+1;
}
int main()
{
	srand((unsigned)time(0));
	ll i; 
	ll n=rnd(100000);
	ll m=1000000000;
	cout<<n<<endl;
	for(i=1;i<=n;i++) 
	{
//    	printf("%lld ",random(2*m+1)-m);
		printf("%lld ",rnd(m)); 
	}
}
