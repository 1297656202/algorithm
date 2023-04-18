#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define inf 1e18
#define maxn 1005
#define ii inline
using namespace std;
ll a[2005],sum[2005],f[2005][2005],g[2005][2005],s[2005][2005];
int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i];
        sum[i]=sum[i-1]+a[i];
        s[i][i]=i;
        }
    for(ll i=1+n;i<=n*2;i++){
        sum[i]=sum[i-1]+a[i];
        s[i][i]=i;
        }
    for(ll i=n*2-1;i;i--)
        for(ll j=i+1;j<=n*2;j++)
		{
            ll jc=0,tmp=inf;
            g[i][j]=max(g[i][j-1],g[i+1][j])+sum[j]-sum[i-1];
            for(ll k=s[i][j-1];k<=s[i+1][j];k++)
			{
                ll tt=f[i][k]+f[k+1][j]+(sum[j]-sum[i-1]);
                if(tt<tmp)
				{
                    tmp=tt;
                    jc=k;
                }
            }
            s[i][j]=jc;
            f[i][j]=tmp;
        }
    ll maxx=0,minn=inf;
    for(ll i=1;i<=n;i++){
        maxx=max(maxx,g[i][i+n-1]);
        minn=min(minn,f[i][i+n-1]);
        }
    printf("%lld\n%lld",minn,maxx);
    return 0;
}
