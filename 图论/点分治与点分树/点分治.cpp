luogu4178
����Σ����������ģ����·����һ������£������������㷨��ҪO��n*n��
������ο��Խ����ӶȽ�ΪO��nlogn�� 
����һ�� n ���ڵ������ÿ�����б�Ȩ����������������С�ڵ��� k �ĵ��������

˼·��
������һ��·�������������
�ٹ������
����һ��������
�������ǿ���ʹ�÷����㷨��
·���������е����ֻ��ݹ鴦���ɣ�������������δ���·���������������
��d(i)��ʾ��i��������·�����ȣ�Belong(i)=X��XΪ������ĳ�����ӣ��ҽ��i����
XΪ���������ڣ�����ô����Ҫͳ�Ƶľ��ǣ�
����d(i)+d(j)<=K��Belong(i)��Belong(j)��(i,j)����
=����d(i)+d(j)<=K��(i,j)����-����d(i)+d(j)<=K��Belong(i)=Belong(j)��(i,j)����
���������������֣�����Ҫ�������Ai+Aj<=K��(i,j)�Ķ�������A[]��������õ����ԣ���
˫ָ��ά�����������׵ó�һ��O(N)���㷨�����Կ�����O(NlogN)��ʱ����������⡣

ע�⣺һ������µ���ε���Ŀ����Ҫ�޳�����ͬһ��belong��·���Ĵ𰸣�
��Ϊ����ͬһ��belong���������·�����ȸ��������������㵽��ʱ���ڵ�ĳ��ȵľ���ͣ�
����֮���·��������������ʱ�ĸ��ڵ� 

���룺 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn], 
maxcore,core,d[mn],lim;
struct w{ll next,to,z;}a[2*mn];
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
void dfss(ll x,ll prt,ll dis)//���x��fa�ľ���Ϊdis����������� 
{ll i,y;
	d[++d[0]]=dis;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(bj[y]==1||y==prt)continue;
		dfss(y,x,dis+a[i].z);
	}
}
void cal(ll x,ll len,ll dlt)//����xΪ��,x�����׾���Ϊlenʱ,���������������ĵ��
{   d[0]=0;
	dfss(x,x,len);//��Ϊ�����ǵ���ǰ�����ĸ��ڵ�ľ��룬�������ͬһ��������·��������Ҫ����x��fa�ľ��� 
	sort(d+1,d+d[0]+1);//�������С�������
	ll l=1,r=d[0];//˫ָ��ά����Ϸ������Ŀ
	while(l<r)
    if(d[l]+d[r]<=lim){ans+=(r-l)*dlt;l++;}
		else r--;
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
	cal(core,0,1);//����coreΪ�������������������ĵ��
	bj[core]=1;//��ǣ�Ҳ�Ǳ����ģ�� 
	for(i=h[core];i;i=a[i].next)//�������Ķ��ӽ�㴦��
	{
		y=a[i].to;
		if(bj[y]==1)continue; 
		cal(y,a[i].z,-1);//��ȥ�������������������ĵ��
		dfs(y,s[y]);//���Զ��ӽ��Ϊ���������ݹ鴦��Ҳ��ģ����· 
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
    cin>>lim;
	dfs(1,n);
	cout<<ans;
    return 0;
}
