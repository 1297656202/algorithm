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
pair<ll,ll>e[1000005]; 
map<pair<ll,ll>,bool>h;
int main()
{
	srand((unsigned)time(0));
	ll i;
	ll n=rnd(100000);
	ll m=rnd(n,n*2);
	// 保证无重边 
	// 先生成一棵树保证联通 
	for(i=1;i<n;i++)
	{
    	ll fa=rnd(i);
    	e[i]=make_pair(fa,i+1);
    	h[e[i]]=h[make_pair(i+1,fa)]=1;
	}
// 在声称m-n+1条边 
	for(i=n;i<=m;i++)
	{
    ll x,y;
    do
	{
        x=rnd(n),y=rnd(n);
    } 
	while(x==y||h[make_pair(x,y)]);
    e[i]=make_pair(x, y);
    h[e[i]]=h[make_pair(y,x)]=1;
	}
	// 打乱边顺序 
	random_shuffle(e+1,e+m+1);
	for(i=1;i<=m;i++)
    printf("%lld %lld\n",e[i].first,e[i].second);
    //printf("%lld %lld %lld\n",e[i].first,e[i].second,rnd(100000));
	return 0; 
}
