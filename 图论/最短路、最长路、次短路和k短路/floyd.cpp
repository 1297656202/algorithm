//floyd算法：可以有负权边，但不能有负权回路 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 505
using namespace std;
ll f[mn][mn],ans[mn],g[mn][mn],n,m;
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(i!=j)f[i][j]=inf;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		f[x][y]=f[y][x]=z;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    return 0;
}
