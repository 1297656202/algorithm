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
	ll n=random(100000);
	for(i=2;i<=n;i++)
	{
    ll fa=rnd(i-1);
    ll val=rnd(1000000000);
    printf("%lld %lld %lld\n",fa,i,val);
	}
	return 0; 
}
