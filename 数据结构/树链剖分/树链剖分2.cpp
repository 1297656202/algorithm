//���⣬��֪һ�ð��� N������������ͨ���޻�����ÿ���ڵ��ϰ���һ����ֵ����Ҫ֧�����²�����
//1 x y z����ʾ������ x �� y ������·�������нڵ��ֵ������ z��
//2 x y����ʾ������ x�� y������·�������нڵ��ֵ֮�͡�
//3 x z����ʾ���� xΪ���ڵ�����������нڵ�ֵ������ z��
//4 x ��ʾ���� xΪ���ڵ�����������нڵ�ֵ֮��
//������Ȩֵ���ǵ�Ȩ������Ǳ�Ȩ���ͽ�(prt[x],x)��Ȩֵ������x�� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],sz[mn],dep[mn],h[mn],son[mn],
id[mn],top[mn],d[mn],fa[mn],sum,
mod,rt=1,cnt=0,tot=0,ans,n,m;
struct w{ll next,to;}a[mn*2];
struct ww{ll a,b,s,add;}c[mn*4];
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
ll dfs(ll x,ll prt,ll deep)//��һ��dfs���ҳ�ÿ���ڵ��dep��fa���ض����������·�� 
{ll i,y,maxx=0;
	dep[x]=deep;
	fa[x]=prt;
	sz[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(y==prt)continue;
		sz[x]+=dfs(y,x,deep+1);
		if(sz[y]>maxx){maxx=sz[y];son[x]=y;}
	}
	return sz[x];
}
void dfs2(ll x,ll tp)//�ڶ���dfs��tp���������Ķ��� 
{ll i,y;
	id[x]=++tot;//x�ڵ��Ӧ�߶����ĵ�tot��Ҷ�ӽڵ� 
	d[tot]=b[x];//�߶����ĵ�tot��Ҷ�ӽڵ��Ȩֵ�Ƕ��� 
	top[x]=tp;
	if(son[x]==0)return ;
	dfs2(son[x],tp);
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(id[y]==0)dfs2(y,y);
	}
}
void up(ll x)//�߶����ϴ���� 
{
	c[x].s=c[x*2].s+c[x*2+1].s;
}
void bui(ll v,ll l,ll r)//�����߶��� 
{
	c[v].a=l;c[v].b=r;
	if(l==r){c[v].s=d[l];return ;}
	ll mid=(l+r)/2;
	bui(2*v,l,mid);
	bui(2*v+1,mid+1,r);
	up(v);
}
void down(ll v)//�߶����´���� 
{
	if(c[v].add)
	{
		c[v*2].s+=c[v].add*(c[v*2].b-c[v*2].a+1);
		c[v*2+1].s+=c[v].add*(c[v*2+1].b-c[v*2+1].a+1);
		c[v*2].add+=c[v].add;
		c[v*2+1].add+=c[v].add;
		c[v].add=0;
	}
}
void segadd(ll v,ll l,ll r,ll x)//���߶�����(l,r)�������x 
{
	if(c[v].b<l||c[v].a>r)return;
	if(l<=c[v].a&&r>=c[v].b)
	{
		c[v].s+=x*(c[v].b-c[v].a+1);
		c[v].add+=x;
		return ;
	}
	down(v);
	segadd(v*2,l,r,x);
	segadd(v*2+1,l,r,x);
	up(v);
}
void segsum(ll v,ll l,ll r)//���߶����ϵ�sum(l,r) 
{
	if(r<c[v].a||l>c[v].b)return ;
	if(l<=c[v].a&&r>=c[v].b){sum=sum+c[v].s;return ;}
	down(v);
	segsum(2*v,l,r);
	segsum(2*v+1,l,r);
}
void add(ll x,ll y,ll z)//������·��x��yÿ�������z 
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		segadd(1,id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	segadd(1,id[x],id[y],z);
	//segadd(1,id[son[x]],id[y]);//��Ȩ
}
ll Sum(ll x,ll y)//������x��y��·���� 
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		segsum(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	segsum(1,id[x],id[y]);
	//segsum(1,id[son[x]],id[y]);//��Ȩ
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m>>rt>>mod;//ԭ���������rt 
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(rt,0,1);
	dfs2(rt,rt);
	bui(1,1,n);
	while(m--)
	{
		scanf("%lld%lld",&k,&x);
		if(k==1)
		{
			scanf("%lld%lld",&y,&z);
			add(x,y,z);
		}
		if(k==2)
		{
			scanf("%lld",&y);
			sum=0;Sum(x,y);
			printf("%lld\n",sum%mod);
		}
		if(k==3)//����Ȼһ����������Ľڵ����߶����϶�������һ��� 
		{
			scanf("%lld",&z);
			segadd(1,id[x],id[x]+sz[x]-1,z);
		}
		if(k==4)
		{
			sum=0;segsum(1,id[x],id[x]+sz[x]-1);
			printf("%lld\n",sum%mod);
		}
	}
	return 0;
}
