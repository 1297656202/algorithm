����dp���ž����� p2014 
�������ѧn�ſο��Ի����Ӧ��ѧ��v[i],��ѧһ�ſα�����ѧϰ�������޿�
������ѧ�Ŀγ���m�����ܵõ����ѧ�֡�

�ܾ��䣬����һ�����ϵ�01������ע�⵹��ö�١���Ȼ�����������е���Ŀ�����Ե���ö�ٴӶ�ʵ��ѹά�ģ� 
�е�ʱ��������Ҫͨ��tmp�����ǰһ�ε�״̬���м�¼��Ȼ����f�����tmp����ת���Ա����鷳 

Ȼ�󣬻��о�����һ�����Ŀ�ܶ�ʱ��һ��ʼҪ�����е�״̬��Ϊ-1����-inf�����ķǷ�ֵ��
������dp�����к����׳��ִ��� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2005
using namespace std;
ll h[mn],v[mn],f[mn][mn],ans,cnt=0,n,m;
struct w{ll next,to;}a[mn*2];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
void dfs(ll x)
{ll i,y,j,k;
	f[x][1]=v[x]; 
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		for(j=m;j>=1;j--)//����ö�٣������������һ��01���� 
            for(k=j-1;k>=1;k--)
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]);
	}
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&v[i]);
		add(x,i);
	}
	m++;// ����0�ڵ�Ĳ��룬m��Ҫ�Լ�1
	dfs(0);//����0�Žڵ�
    cout<<f[0][m];
	return 0;
}

������ʵ����һ���Ż�����ĳЩ��Ŀ��������õõ������ǰ�dfs���ָ�һ�ģ���sz[]����ķ�Χ����һ��
���Կ�������ʵ�Ż�֮���κ�һ�����ֻ������lca����ͳ���ˣ��������۸��Ӷ���O��n*m��
�������Ҫ�Ż�����Ҫ��д�Ļ���д�����Ǹ�����Ҫ�Ż���д�����Ǹ� 

void dfs(ll x)
{ll i,y,j,k;
	f[x][1]=v[x];sz[x]=1; 
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		for(j=sz[x];j>=1;j--)//����ö�٣������������һ��01���� 
            for(k=min(sz[y],m-j);k>=1;k--)
                f[x][j+k]=max(f[x][j+k],f[x][j]+f[y][k]);
		sz[x]+=sz[y];
	}
}
P3177 [HAOI2015] ����Ⱦɫ
��һ�õ���Ϊ n �����������б�Ȩ������һ���� 0��n ֮�ڵ������� k ��
��Ҫ���������ѡ�� k���㣬����Ⱦ�ɺ�ɫ���������� �� n-k ����Ⱦ�ɰ�ɫ�������е�Ⱦɫ��
����úڵ�����֮��ľ�����ϰ׵�����֮��ľ���ĺ͵����档���������ֵ�Ƕ��١�

������Ҫ�õ�������Ǹ��Ż������ӶȽ���O��n*m������������Ż����ܱ���ܶ��鷳

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2005
using namespace std;
ll f[mn][mn],h[mn],sz[mn],
ans=0,cnt=0,n,m,p;
struct w{ll next,to,z;}a[mn*2];
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
void dfs(ll x,ll prt)
{ll i,y,j,k;
	sz[x]=1;
	f[x][0]=f[x][1]=0;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		dfs(y,x);
		for(j=min(sz[x],m);j>=0;j--)
			for(k=min(sz[y],m-j);k>=0;k--)
				f[x][j+k]=max(f[x][j+k],
				f[x][j]+f[y][k]+k*(m-k)*a[i].z+(sz[y]-k)*(n-m-(sz[y]-k))*a[i].z);
		sz[x]+=sz[y];
	}
}
int main()
{
	ll te,x,y,i,j,k,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
			f[i][j]=-inf;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout<<f[1][m];
    return 0;
}

