����ƽ��������ͨƽ�������������ڣ���ͨƽ����һ��ά������Ȩֵ�����򣬺ܶ�ʱ������������setֱ�ӽ��в�����
������ƽ����һ��ά������һ�����䣬splayά������Ļ���ԭ�����ǽ�����[l,r]�Ķ˵�l-1,��r+1
���ϵ�ͨ����չ������splay��������l-1��չ��������r+1��չ�������Ҷ��ӣ�Ҳ����get(l,r)
��ô[l,r]���������ڸ����Ҷ��ӵ���������ˡ���Ϊ��������������Ծ����õ�����ǡ� 
���⣬���ҵ�ģ�����棬����splay����ͨsplay��spl��������һ�� 
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll rt=0,ans=0,tot=0,n,m,a[mn],
c[mn][2],v[mn],fa[mn],mx[mn],s[mn],
sum[mn],tag[mn],rev[mn];
//mx[]��ʾ����������������Ȩֵ��sum[]��ʾ����������Ȩֵ�ͣ�s[]��ʾ���Ľڵ�������
//v[]��ʾ�ڵ��Ȩֵ ��tag[]�������ǣ���ʾ����ڵ��µĽڵ㶼�ü��϶���
//rev[]�������ǣ���ʾ��������ڵ����Ƿ���Ҫ��ת
void up(ll x)//�ϴ���� 
{ll l=c[x][0],r=c[x][1];
	mx[x]=max(max(mx[l],mx[r]),v[x]);
	sum[x]=sum[l]+sum[r]+v[x];
	s[x]=s[l]+s[r]+1;
}
void down(ll x)//�´���� 
{ll l=c[x][0],r=c[x][1];
	if(tag[x])
	{
		if(l){tag[l]+=tag[x];mx[l]+=tag[x];v[l]+=tag[x];sum[l]+=tag[x]*s[l];}
		if(r){tag[r]+=tag[x];mx[r]+=tag[x];v[r]+=tag[x];sum[r]+=tag[x]*s[r];}
		tag[x]=0;
	}
	if(rev[x])
	{
		rev[x]=0;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}	
}
void rot(ll x,ll &f)//��ת���� 
{ll y=fa[x],z=fa[y],l,r;
	l=(c[y][0]!=x);r=l^1;
	if(y==f)f=x;
	else {if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;}
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	up(y);up(x);
}
void spl(ll x,ll &f)//��x�ڵ���ת��f���λ�� 
{
	while(x!=f)
	{
		ll y=fa[x],z=fa[y];
		if(y!=f){if(c[y][0]==x^c[z][0]==y)rot(x,f);else rot(y,f);}
		rot(x,f);
	}
}
ll bui(ll l,ll r,ll prt)//ֱ�ӽ�����l��r֮���ƽ���� 
{ll x,mid;
    if(l>r)return 0;
	x=++tot;mid=(l+r)/2;
    fa[x]=prt;v[x]=mx[x]=sum[x]=a[mid];
    c[x][0]=bui(l,mid-1,x);c[x][1]=bui(mid+1,r,x);
    up(x);return x;
}
ll find(ll x,ll k)//��xΪ�����������������еĵ�k�����ĸ��ڵ� 
{
	down(x);
	ll l=c[x][0],r=c[x][1];
	if(s[l]+1==k)return x;
	if(s[l]>=k)return find(l,k);
	else return find(r,k-s[l]-1);
}
ll get(ll l,ll r)//������(l,r)��ת�������Ҷ��ӵ�������ϣ����ظ����Ҷ��� 
{ll x=find(rt,l),y=find(rt,r+2);
	spl(x,rt);
	spl(y,c[rt][1]);
	return y;
} 
void ask(ll k)//ѯ�������еĵ�k����Ȩֵ�Ƕ��� 
{ll x=find(rt,k+1);
	spl(x,rt);
	printf("%lld\n",v[rt]);
}
void add(ll l,ll r,ll z)//����l��r������� 
{ll y=get(l,r);
	tag[c[y][0]]+=z;
	v[c[y][0]]+=z;
	mx[c[y][0]]+=z;
	sum[c[y][0]]+=z*s[c[y][0]];
	up(y);
}
void Max(ll l,ll r)//��l��r������ֵ 
{ll y=get(l,r);
	printf("%lld\n",mx[c[y][0]]);
}
void Sum(ll l,ll r)//��l��r���Ȩֵ�� 
{ll y=get(l,r);
	printf("%lld\n",sum[c[y][0]]);
}
void Rev(ll l,ll r)//��תl��r��������� 
{ll y=get(l,r);
	rev[c[y][0]]^=1;
}
void dfs(ll x)//����ƽ�����������,������ 
{
	down(x);
	if(c[x][0])dfs(c[x][0]);
	if(abs(v[x])!=inf)printf("%lld ",v[x]);
	if(c[x][1])dfs(c[x][1]);
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	cin>>n>>m;
	mx[0]=-inf;//��Ϊup��ʱ��l��r���ܵ���0 
	a[1]=inf;a[n+2]=inf;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i+1]);
	rt=bui(1,n+2,0);
	while(m--)
	{
		scanf("%lld%lld",&k,&x);
		if(k==1){ask(x);continue;}
		scanf("%lld",&y);
		if(k==2){scanf("%lld",&z);add(x,y,z);}
		if(k==3)Sum(x,y);
		if(k==4)Max(x,y);
		if(k==5)Rev(x,y);
	}
    return 0;
}
