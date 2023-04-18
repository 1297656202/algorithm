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
	n=random(10000);
	m=random(10000);
	for(i=1;i<=m;i++)
	{
    ll l=rnd(n);
    ll r=rnd(n);
    if(l>r)swap(l,r);
    printf("%lld%lld\n",l,r);	
	}
	return 0; 
}
