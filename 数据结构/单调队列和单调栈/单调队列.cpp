//P1886 滑动窗口 /【模板】单调队列 
//有一个长为 n的序列 a，以及一个大小为 k的窗口。现在这个从左边开始向右滑动，每次滑动一个单位，
//求出每次滑动后窗口中的最大值和最小值。
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 10005
using namespace std;
ll n,m,
q1[1000001],q2[1000001],a[1000001];
ll minque()
{
    ll h=1,t=0;
    for(ll i=1;i<=n;i++)
    {
        while(h<=t&&q1[h]+m<=i) h++;
        while(h<=t&&a[i]<a[q1[t]]) t--;
        q1[++t]=i;
        if(i>=m) printf("%lld ",a[q1[h]]);
    }
    cout<<endl;
}
ll maxque()
{
    ll h=1,t=0;
    for(ll i=1;i<=n;i++)
    {
        while(h<=t&&q2[h]+m<=i) h++;
        while(h<=t&&a[i]>a[q2[t]]) t--;
        q2[++t]=i;
		if(i>=m) printf("%lld ",a[q2[h]]);
        
    }
}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    minque();
    maxque();
    return 0;
}
