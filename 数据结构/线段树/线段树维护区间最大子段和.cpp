luogu sp1716 GSS3
����0 x y��A_x�ĳ�y 
����1 l rѯ������[l,r]������Ӷκͣ�Ҳ��������һ�������Ӷ� 

ֵ��ע��������ģ�ͷǳ��м�ֵ
��������ά����ĳ�������ϵĵ�Ϊ��˵㣨�Ҷ˵㣩�ܹ��õ�������Ӷκͣ�������̿����������Ĺ����������
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll b[mn],
sum,ans=0,cnt=0,ge,r,n,m;
struct w{ll a,b,s,ls,rs,res;}a[mn*4];//�߶������鿪4�� 
//s��ʾ��һ�ε��ܺͣ�ls��rs�ֱ��ʾ��������˵���Ҷ˵㿪ʼ������Ӷκͣ�resΪ������Ӷκ� 
void up(ll v)//��һ�ε�ά���������ص� 
{
	a[v].s=a[v*2].s+a[v*2+1].s;
	a[v].ls=max(a[v*2].ls,a[v*2].s+a[v*2+1].ls);
	a[v].rs=max(a[v*2+1].rs,a[v*2+1].s+a[v*2].rs);
	a[v].res=max(a[v*2].rs+a[v*2+1].ls,max(a[v*2].res,a[v*2+1].res)); 
}
void bui(ll v,ll l,ll r)
{ll mid;
	a[v].a=l;
	a[v].b=r;
	if(l==r){a[v].s=a[v].ls=a[v].rs=a[v].res=b[l];return ;}
	mid=(l+r)/2;
	bui(v*2,l,mid);
	bui(v*2+1,mid+1,r);
	up(v);
}
void add(ll v,ll x,ll y)
{
	if(a[v].b<x||a[v].a>x)return;
	if(a[v].a==a[v].b){a[v].s=a[v].ls=a[v].rs=a[v].res=y;return ;}
	add(v*2,x,y);
	add(v*2+1,x,y);
	up(v);
}
w ask(ll v,ll l,ll r)//��һ�ε�ѯ�ʹ���Ҳ���ص� 
{
	if(l<=a[v].a&&r>=a[v].b){return a[v];}
	if(r<a[v*2+1].a)return ask(v*2,l,r);
	if(l>a[v*2].b)return ask(v*2+1,l,r);
	w lv=ask(v*2,l,r),rv=ask(v*2+1,l,r),ret;
	ret.s=lv.s+rv.s;
	ret.ls=max(lv.ls,lv.s+rv.ls);
	ret.rs=max(rv.rs,rv.s+lv.rs);
	ret.res=max(lv.rs+rv.ls,max(lv.res,rv.res));
	return ret;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	bui(1,1,n);
	cin>>m;
	while(m--)
	{
		scanf("%lld",&k);
		if(k==0)
		{
			scanf("%lld%lld",&x,&y);
			add(1,x,y);
		}
		else 
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask(1,x,y).res);
		}
	}
    return 0;
}
