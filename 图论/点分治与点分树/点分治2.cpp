���⣺����һ����n��<=10000���������������m(<=100)��ѯ�ʣ������Ͼ���Ϊk�ĵ���Ƿ���ڡ���ʱ��200ms�� 

˼·�������Ŀ�õ�����Ǳ�Ȼ�ģ����ǣ��������ÿ��ѯ�ʶ����е�֣�
���Ӷ�n*m*logn�����Ͽ��У����ǵ���εĳ������Ӷ�̫�󣬹��޷���ɣ�
���ʱ�����һ�ε���ξ��ܹ�������⣬�Ϳ��Ա���޴�ĳ�����
�����ַ�����1����������� 2���ߵ�ֱ߽��ѯ�� 

ע�⣺һ������µ���ε���Ŀ����Ҫ�޳�����ͬһ��belong��·���Ĵ�

����Ϊ�ߵ�ֱ߽��ѯ�ʵĴ��룺 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn],bel[mn],d0,ok[mn],qus[mn],
maxcore,core;
struct w{ll next,to,z;}a[2*mn];
struct ww{ll d,bl;}d[mn];
bool cmp(ww a,ww b){return a.d<b.d;}
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
void dfss(ll x,ll prt,ll dis,ll belong)//���x��fa�ľ���Ϊdis����������� 
{ll i,y;
	d[++d0]=(ww){dis,belong};
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y]==1||y==prt)continue;
		dfss(y,x,dis+a[i].z,belong);
	}
}
void cal(ll x)//����xΪ��,x�����׾���Ϊlenʱ,���������������ĵ��
{ll i,y;
	d0=0;
	d[++d0]=(ww){0,0};
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y])continue;
		dfss(y,x,a[i].z,y);
	}
	sort(d+1,d+d0+1,cmp);//�������С�������
	for(i=1;i<=m;i++)
	if(ok[i]==0)
	{
		ll l=1,r=d0;//˫ָ��ά����Ϸ�����Ƿ���� 
		while(l<r)
	    if(d[l].d+d[r].d<qus[i])l++;
		else if(d[l].d+d[r].d>qus[i])r--;
		else if(d[l].bl!=d[r].bl){ok[i]=1;break;} 
		else l++;
	}
}
void find(ll x,ll prt,ll num)//�����ģ���һ���ֻ�������ģ�� 
{ll maxx=0,i,y;
	s[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt||bj[y]==1)continue;
		find(y,x,num);
		s[x]+=s[y];
		maxx=max(maxx,s[y]);
	}
	maxx=max(maxx,num-s[x]);
	if(maxcore>maxx){maxcore=maxx;core=x;}//coreΪ��������
}
void dfs(ll x,ll num)//��xΪ��,�ܹ�Num�����
{ll i,y;
    maxcore=inf;
	find(x,0,num);//����xΪ��������������core������Ҳ�Ǳ����ģ�� 
	cal(core);//����coreΪ�������������������ĵ��
	bj[core]=1;//��ǣ�Ҳ�Ǳ����ģ�� 
	for(i=h[core];i;i=a[i].next)//�������Ķ��ӽ�㴦��
	{
		y=a[i].to;
		if(bj[y]==1)continue; 
		dfs(y,s[y]);//���Զ��ӽ��Ϊ���������ݹ鴦��Ҳ��ģ����· 
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
    for(i=1;i<=m;i++)
		scanf("%lld",&qus[i]);
	dfs(1,n);
	for(i=1;i<=m;i++)
	if(ok[i])printf("AYE\n");
	else printf("NAY\n");
    return 0;
}
