����һ�� n ���� m���ߵļ�����ͼ��������Ԫ��������
����ͼ G ����Ԫ��ָ����G ��һ����ͼ G_0������ G_0���ҽ��������� u,w,v,�����ҽ��������� u-v,v-w,w-u

��ͳ��ÿ����Ķ���d(u).���d(u)<d(v),��d(u)=d(v)��u<v,�� u���ȼ���v��
��һ����ͼ,����ԭͼ�б�(u,v),��u���ȼ���v��,������ͼ�������u->v(��֮��v->u).��ԭͼ�еĻ�Ϊ(u->v,v->w,u->w)
Ȼ��,ö��u,�������пɴ����ϱ��.�ٿ��������пɴ��v,���������пɴ��w,��w�б��,��+1.

����֤��,���ַ�����ʱ�临�Ӷ���O(m*sqrt(m))��.

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
