�����Դ�ڵ������һЩ�ܺõ����ʣ�
1�������ϸ�С�ڵ���logn
2���������ÿ��������������е����ԭ�����������Ϊ��������ʱҪ�������ĵ�
3�����������һ����x����·���ϵ�ÿ����Ϊ��������ʱ��������������x
4��������ϵı߲���ԭ���ϵı�
��ô��ô�õ����ʵ�ֶ�̬������أ����ǿ��ǵ������ĳ����Ϊ��������ʱ���������ĵ������һ����ͨ�飬
�������ͨ���еĵ����������������ڵ�����ϵ������е����е㡣
�����ʱÿ������������Ҫ������������ͨ�����õ�������ͨ����ÿ����֮�����Ϣ��
��ô�������ÿ�������Ҫά��������������ÿ����֮�����Ϣ��
�������޸�ĳ�������Ϣʱֻ��Ҫ����������ڵ�����ϵ���·����ÿ����ά������Ϣ��
����ѯʱҲֻ��Ҫ��ѯ������ϴӲ�ѯ�㵽��·���ϵ�ÿ�������Ϣ����ͳ�ơ�
�����м����ط���Ҫע�⣺
1����Ϊÿ����Ҫά�������������е����Ϣ������һ����˵ÿ����ά������Ϣ��Ҫ�����ݽṹ��ά����
Ҳ���ǵ���������ݽṹ
2����Ϊ������ϵı߲���ԭ���ϵıߣ�������Ҫ��ԭ�������LCA�����������룬Ϊ�˲�Ӱ��ʱ�临�Ӷȣ�Ҫ��RMQ��LCA
3����̬�����ͳ�ƴ�һ������ݳ�ķ���
4�����������������һ�鲻ͳ����Ϣ�Ŀյĵ����
5�������̬���������ʱ�����ȿ��ǵ���ѯ���õ������δ�����Ҫ��ʲô��Ϣ��Ȼ����ת��������Ͻ��д���
˵����ô������һ�����⣺��һ��n���ڵ��������ȨΪ1�����е�Ȩ����m�β�����ÿ�β���Ҫô�޸�һ�����Ȩֵ��
Ҫôѯ�ʾ���һ�������С�ڵ���k�����е�ĵ�Ȩ�ͣ�ǿ�����ߣ�n,m<=10^5��
�ʼ�� xx ��ʱ��ֱ�ӽ� xx �����Ľڵ�� xx �Ĺ��׼���𰸼��ɡ��ٿ������������Ĺ����У�
�赱ǰ�ڵ�Ϊ u ���� x�ľ���Ϊ dis����������Ҫ��������� u �����ڵ����� x�����ڵĽڵ�� x�Ĺ��ף�
Ҳ������ u ���������� x�����Ľڵ����� x�ľ��� ��y-dis��y?dis �Ľڵ��Ȩֵ�͡���ô�ݳ�һ�¿��Եõ���
����Ҫ��ľ����� u������ u���� ��y-dis��y-dis �Ľڵ�Ȩֵ�ͼ�ȥ x�������� u���� ��y-dis��y-dis ��Ȩֵ�͡�
���׷��֣�������Ǽ� W_{i,j}Wi,j Ϊ i�������� i�ľ���Ϊ j�Ľڵ�Ȩֵ�ͣ�
��ô����ÿ��ѯ�ʵĶ���wi��ǰ׺�ͣ���ô���ǾͿ�������״������ά����Щ��Ϣ�ˡ�
ע������Ҫ�õ�����Ϣ��������
1.	i�����ڽڵ�� i�Ĺ��ס�
2.	i�ڵ������ڽڵ���� i���׵Ĺ��ס�
���Ƿֱ��� C_{0,i},C_{1,i}��ʾ��������״���顣
��ôÿ�β�ѯ��ʱ��ֻ��Ҫ��������������ɼ��ɣ�ע������ n�ܴ󣬿����� vector ���棬
��СΪ i��������С +1���ھ������Ϊ 00 ����Ҫ����״�����������ƣ�
�����޸Ĳ�������ô����ֻ��Ҫ������������һֱ���������޸�C_{0,i},C_{1,i}���ɣ�����С��logn 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll h[mn],cnt=0,ge,n,m,ans=0,
bj[mn],s[mn],l[mn],d[mn],dfn[mn],tot=0,
f[mn][21],g[mn][21],fa[mn],val[mn],
maxcore,core;
vector<ll>c[2][mn];
//c[0][i][x]ά����i����Ϊx�ĵ�Ȩ�ͣ�c[1][i][x]ά����������ϵĸ��ڵ�fa[i]����Ϊx�ĵ�Ȩ�� 
struct w{ll next,to;}a[2*mn];
void add(ll x,ll y)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
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
void dfs(ll x,ll num,ll prt)//��xΪ��,�ܹ�Num�����
{ll i,y,tmp;
    maxcore=inf;
	find(x,0,num);//����xΪ��������������core������Ҳ�Ǳ����ģ�� 
	bj[core]=1;//��ǣ�Ҳ�Ǳ����ģ�� 
	fa[core]=prt;
	s[core]=num;
	c[0][core].resize(s[core]+2);//��̬����״���飬���Ϊs[x]+2�����Կ���һ���ֹre 
	c[1][core].resize(s[core]+2);
	tmp=core;
	for(i=h[core];i;i=a[i].next)//�������Ķ��ӽ�㴦��
	{
		y=a[i].to;
		if(bj[y]==1)continue;
		dfs(y,s[y],tmp);//���Զ��ӽ��Ϊ���������ݹ鴦��Ҳ��ģ����· 
	}
}
void dfs2(ll x,ll deep)
{ll i,y;
	l[x]=++tot;d[x]=deep;f[tot][0]=deep;g[tot][0]=x;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		if(l[y])continue;
		dfs2(y,deep+1);
		f[++tot][0]=deep;
		g[tot][0]=x;
	}
}
void st()
{ll i,j;
	for(j=1;j<=log2(tot);j++)
		for(i=1;i<=tot-(1<<j)+1;i++)
		if(f[i][j-1]<f[i+(1<<(j-1))][j-1])
		{
			f[i][j]=f[i][j-1];
			g[i][j]=g[i][j-1];
		}
		else 
		{
			f[i][j]=f[i+(1<<(j-1))][j-1];
			g[i][j]=g[i+(1<<(j-1))][j-1];
		}
}
ll lca(ll x,ll y)
{ll k;
	x=l[x];y=l[y];
	if(x>y)swap(x,y);
	k=(ll)log2(y-x+1);
	if(f[x][k]<f[y-(1<<k)+1][k])return g[x][k];
    return g[y-(1<<k)+1][k];
}
ll dis(ll x,ll y) 
{
	return d[x]+d[y]-2*d[lca(x,y)];
}
ll low(ll x){return x&(-x);}
void ad(ll k,ll u,ll x,ll z)
{ll i;
	x++;
	for(i=x;i<=s[u]+1;i+=low(i))
	    c[k][u][i]+=z;
}
ll ask(ll k,ll u,ll x) 
{ll i,ans=0;
	x++;
	x=min(x,s[u]+1);
	for(i=x;i>0;i-=low(i))
	    ans+=c[k][u][i];
	return ans;
}
void ins(ll x,ll v)
{ll i;
	for(i=x;i;i=fa[i])ad(0,i,dis(x,i),v);
	for(i=x;fa[i];i=fa[i])ad(1,i,dis(x,fa[i]),v);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs2(1,0);
	st();
	dfs(1,n,0);
	for(i=1;i<=n;i++)
	ins(i,val[i]);
	ans=0; 
	while(m--)
	{
		scanf("%lld%lld%lld",&k,&x,&y);
		x^=ans;y^=ans;
		if(k==0)
		{
			ans=ask(0,x,y);
			for(i=x;fa[i];i=fa[i])
			{
				ll tmp=dis(x,fa[i]);
				if(y>=tmp)
				ans+=ask(0,fa[i],y-tmp)-ask(1,i,y-tmp);
			}
			printf("%lld\n",ans);
		}
		else 
		{
			ins(x,y-val[x]);
			val[x]=y;
		}
	}
    return 0;
}
