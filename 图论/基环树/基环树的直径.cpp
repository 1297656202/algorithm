���������ֱ��
ע�⣬�п����������������⣬�п����ǻ�����ɭ�� 
���⣺IOI2008 island���㷨����p383�� 
��������һ��������ȱ����ҳ��������еġ��������ѡ������ϵ�
�ڵ����ϱ�ǡ��軷�ϵĽڵ�Ϊs1,s2,.. .,St
��ÿ��s�������ڲ��������������ڵ��ǰ���£��ٴ�ִ��������ȱ�����
���ɷ���ȥ������֮����siΪ������������������ÿ�������У�
����������ֱ���ķ�������DP�����´𰸣����ɴ���ֱ�����ڻ��ϵ������
ͬʱ�������Լ����D[si]����ʾ�ӽڵ�si����������siΪ�����������ܹ��������Զ�ڵ�ľ��롣
������ǿ���ֱ���ڻ��ϵ���������൱���ҵ�����������ͬ�Ľڵ�si��sj��
ʹ��D[s]+D[sj]+dist(si,sj)�������dis(si,sj)��ʾsi,sj�ڻ��ϵľ��룬
����ʱ�롢˳ʱ�������߷���ȡ�ϳ�����һ�֡���ȼ��ڡ���·���䡱��
�ѻ��Ͽ������ٸ���һ�����õ������м�����O(N)��ʱ���ڽ����
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll bj[mn],v[mn],ins[mn],cir[mn],maxd=0,ed,h[mn],stk[mn],
f[mn],sum[mn],top=0,dis[mn],ans=0,st,
cnt=0,tot=0,n,m;
struct w{ll next,to,z;}a[mn*2];
deque<ll>q;
void add(ll x,ll y,ll z)
{
	a[++cnt]=(w){h[x],y,z};
	h[x]=cnt;
}
void dfs1(ll x,ll fa)
{ll i,y,j,bjj=0;
    stk[++top]=x;
	ins[x]=top;
    for(i=h[x];i;i=a[i].next)
	{
        y=a[i].to;
		if(y==fa&&bjj==0){bjj++;continue;}
		dis[top]=a[i].z;
        if(ins[y])
		for(j=ins[y];j<=ins[x];j++)
		{
			cir[++cir[0]]=stk[j];
			sum[cir[0]]=sum[cir[0]-1]+dis[j];
			bj[stk[j]]=1;
		}
        else 
		{
			dfs1(y,x);
		}
    }
    top--;
}
void dfs(ll x,ll prt,ll deep)
{ll i,y;
	if(deep>maxd){maxd=deep;ed=x;}
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt||bj[y]==1)continue;
		dfs(y,x,deep+a[i].z);
	}
}
ll cal()
{ll i,j,s=0;
	cir[0]=0;
	top=0;
	q.clear();
	dfs1(st,0);
	for(i=1;i<=cir[0];i++)
	{
		maxd=0;
		dfs(cir[i],0,0);
		f[i]=maxd;
		maxd=0;
		if(n>=800000)bj[cir[i]]=0;
		dfs(ed,0,0);
		if(n>=800000)bj[cir[i]]=1;
		s=max(maxd,s);
	}
//	cout<<s<<" "<<cir[1]<<" "<<f[1]<<" "<<f[2]<<endl;
	for(i=1;i<=cir[0];i++)
		f[i+cir[0]]=f[i];
	for(i=cir[0]+1;i<=cir[0]*2;i++)
	{
		sum[i]=sum[i-1]+sum[i-cir[0]]-sum[i-cir[0]-1];
	}
	for(i=1;i<=cir[0]*2;i++)
	{
		while(q.empty()==0&&i-q.front()>=cir[0])
		q.pop_front();
		if(q.empty()==0)s=max(s,f[i]+f[q.front()]+sum[i-1]-sum[q.front()-1]);
		while(q.empty()==0&&f[q.back()]-sum[q.back()-1]<f[i]-sum[i-1])
		q.pop_back();
		q.push_back(i);
	}
	return s;
}
int main()
{
	ll te,x,y,i,j,z,k;
	char ch;	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(i,x,y);
		add(x,i,y);
	}
	for(i=1;i<=n;i++)
	if(ins[i]==0)
	{
		st=i;
		ans+=cal();
	}
	cout<<ans;
    return 0;
}
