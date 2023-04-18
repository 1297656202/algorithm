给定一张n 个点的带权无向图，点从0~n-1标号，求起点0到终点n-1的最短Hamilton路径。
Hamilton路径的定义是0到n-1不重不漏地经过每个点恰好一次。而Hamilton回路则是最后会回到起点的闭合路径。

如果是Hamilton回路，那就是经典的旅行商问题
旅行商问题，即TSP问题(Travelling Salesman Problem）是指一个商人要访问N座城市，且每个城市只能访问一次，
最后回到起点，求走的路程最小的方案。因为是回路，起点无所谓，所以我们可以直接设置起点为0，然后dp即可。 

这个问题有一些变种，比如旅行商可以在某个城市购买某个物品然后在拿到其他城市去卖，根据下面的dp进行改编即可。 

#include<bits/stdc++.h>
#define ll int//这里用的是int，因为数组开大了会爆 
#define inf 1e18
#define mn 25
using namespace std;
ll a[mn][mn],f[1<<20][mn],cnt=0,tot=0,sign=0,m,ans=inf,n;
int main()
{
	ll len,x,y,t,i,j,z,k,l;
	cin>>n;
	for(i=0;i<n;i++)	
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	memset(f,1,sizeof(f));//f置为极大值  
	f[1][0]=0;
	for(i=1;i<1<<n;i++)
		for(j=0;j<n;j++)
		if(i>>j&1)
		{
			for(k=0;k<n;k++)
			if(i>>k&1)f[i][j]=min(f[i][j],f[i^1<<j][k]+a[k][j]);
		}
	//这个答案是到终点n-1的，如果是回路的话则为f[(1<<n)-1][0]，如果终点无限制，遍历求最小值即可 
	cout<<f[(1<<n)-1][n-1];
	return 0;
}
