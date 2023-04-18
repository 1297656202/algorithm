给定一个 n 个点 m条边的简单无向图，求其三元环个数。
无向图 G 的三元环指的是G 的一个子图 G_0，满足 G_0有且仅有三个点 u,w,v,，有且仅有三条边 u-v,v-w,w-u

先统计每个点的度数d(u).如果d(u)<d(v),或d(u)=d(v)且u<v,称 u优先级比v高
建一个新图,对于原图中边(u,v),若u优先级比v高,则在新图连有向边u->v(反之连v->u).则原图中的环为(u->v,v->w,u->w)
然后,枚举u,对其所有可达点打上标记.再考虑其所有可达点v,考虑其所有可达点w,若w有标记,答案+1.

可以证明,这种方法的时间复杂度是O(m*sqrt(m))的.

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll h[mn],bj[mn],d[mn],ans=0,cnt=0,n,m;
struct w{ll next,to;}a[mn*2];
struct ww{ll x,y;}l[mn];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&l[i].x,&l[i].y);
		d[l[i].x]++;d[l[i].y]++;
	}
	for(i=1;i<=m;i++)
	{
		if(d[l[i].x]>d[l[i].y]||(d[l[i].x]==d[l[i].y]&&l[i].x<l[i].y))swap(l[i].x,l[i].y);
		add(l[i].x,l[i].y);
	}
	for(x=1;x<=n;x++)
	{
		for(i=h[x];i;i=a[i].next)bj[a[i].to]=1;
		for(i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			for(j=h[y];j;j=a[j].next)
				if(bj[a[j].to])ans++;
		}
		for(i=h[x];i;i=a[i].next)bj[a[i].to]=0;
	}
	cout<<ans;
	return 0;
}
