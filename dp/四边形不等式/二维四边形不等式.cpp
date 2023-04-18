#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll int//////////////
#define inf 1e18
#define maxn 5005
#define maxm 2005
#define ii inline
using namespace std;
ll a[maxn],f[maxn][maxm],n,m,ss[maxn][maxm],d[maxn][maxn],
s[maxn][maxn];
int main(){
    ll k,h,t,r,l,te,x,y,len,i,j,z;
    memset(f,1,sizeof(f));
    cin>>n>>m;
    for(i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    	for(j=i;j<=n;j++)
    		s[i][j]=s[i][j-1]+a[j];
    for(l=1;l<=n;l++)
    	for(r=l;r<=n;r++)
    	{ll mid=(l+r)/2;
    		d[l][r]+=(mid-l)*a[mid]-s[l][mid-1];
    		d[l][r]+=s[mid+1][r]-(r-mid)*a[mid];
    	}
    for(i=1;i<=n;i++)
    	f[i][1]=d[1][i];
    for(j=2;j<=m;j++)
    {
    	ss[n+1][j]=n;
    	for(i=n;i>=1;i--)
    		for(k=ss[i][j-1];k<=ss[i+1][j];k++)
			if(f[k][j-1]+d[k+1][i]<f[i][j])
			{
    			f[i][j]=f[k][j-1]+d[k+1][i];
    			ss[i][j]=k;
    		}
    }
    cout<<f[n][m];
    return 0;
}
