��2-SAT������ܽ᣺
��Ҫ��˼:���Ǹ���N���飨ÿ����2��Ԫ�أ���M�������ϵ����ÿ��������1��ʹ�ø����Ĳ������κλ����ϵ��
���ǽ����������Ĺؼ��������ڽ�ģ��������ģ���Ƕ������������ݵĵ�i��j��
��ͼ��ʽΪ:i��j'(i��j��ͻ��ѡiֻ��ѡj')��j��i'��i��j��ͻ��ѡjֻ��ѡi')��
��2-SAT������:��ԭͼ��һ��ǿ��ͨ������Ȼ��ÿ���е��������Ƿ�����ͬһ��ǿ��ͨ������
������������������ô�޽�;�����ͼ����һ�����������Ե����ϵ�ѡ��㼴�ɵõ�һ����н⡣

ĳ����n�����ɣ�ÿ�������������ǡ��2������ ����Ҫ������ƽίԱ�� ���û�����
.ÿ�������ں�ƽίԱ��������ֻ��һ������ 
.���ĳ���������ͣ������ǲ��ܶ�����ίԱ��
.����ı�Ŵ�1��2n�����Ϊ2a-1��2a�Ĵ������ڵ�a������ 
���񣺶��뵳�ɵ������͹�ϵ���ѺõĴ���ԣ��������������ƽίԱ���Ƿ���ܣ����У����г�ίԱ��ĳ�Ա��
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll bj[mn],in[mn],num=0,s[mn],
opp[mn],belong[mn],top=0,sign=0,
cnt=0,ge,r,d,n,m,h[mn],dfn[mn],low[mn];
struct w{ll next,to;}a[mn];
void add(ll x,ll y)
{
   cnt++;
   a[cnt].next=h[x];
   a[cnt].to=y;
   h[x]=cnt;
}
void dfs(ll x)
{ll i,y;
	dfn[x]=low[x]=++sign;
	s[++top]=x;
	in[x]=1;
	for(i=h[x];i;i=a[i].next)
	{
	   	y=a[i].to;
	   	if(dfn[y]==0)
	   	{
			dfs(y);
			low[x]=min(low[x],low[y]);
	   	}
	   	else if(in[y])low[x]=min(low[x],low[y]);
	}
	   ll t;
	if(low[x]==dfn[x])
	{
	    num++;
	    do
		{
		    t=s[top--];	
			in[t]=0;
			belong[t]=num;
	    }while(t!=x);
	}
}
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		ll x2,y2;
		cin>>x>>y;
		if(x%2==0)x2=x-1;else x2=x+1;
		if(y%2==0)y2=y-1;else y2=y+1;
		add(x,y2);//ѡ��x�ͱ���ѡy2 
		add(y,x2);//ѡ��y�ͱ���ѡx2
	}
	for(i=1;i<=2*n;i++)
		if(dfn[i]==0)dfs(i);
	for(i=1;i<=n;i++)
	{
		x=i*2;
		y=i*2-1;
		if(belong[x]==belong[y]){cout<<"NIE";return 0;}
	}
	for(i=1;i<=2*n;i++)
	{
		if(i%2==0)x=i-1;else x=i+1;
		opp[belong[i]]=belong[x];
	}
	for(i=1;i<=num;i++)
		if(bj[i]==0)bj[opp[i]]=1;
	for(i=1;i<=2*n;i++)
		if(bj[belong[i]]==0)cout<<i<<endl;
	return 0;
}
