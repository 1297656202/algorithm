文艺平衡树和普通平衡树的区别在于，普通平衡树一般维护的是权值的排序，很多时候甚至可以用set直接进行操作，
而文艺平衡树一般维护的是一个区间，splay维护区间的基本原理，就是将区间[l,r]的端点l-1,和r+1
不断的通过伸展操作即splay到根，将l-1伸展到根，将r+1伸展到根的右儿子，也就是get(l,r)
那么[l,r]这段区间就在根的右儿子的左儿子上了。因为是区间操作，所以经常用到懒标记。 
另外，在我的模板里面，文艺splay和普通splay的spl操作并不一样 
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll rt=0,ans=0,tot=0,n,m,a[mn],
c[mn][2],v[mn],fa[mn],mx[mn],s[mn],
sum[mn],tag[mn],rev[mn];
//mx[]表示的是子树里面最大的权值，sum[]表示的是子树的权值和，s[]表示树的节点总数，
//v[]表示节点的权值 ，tag[]是懒惰标记，表示这个节点下的节点都该加上多少
//rev[]是懒惰标记，表示的是这个节点下是否需要旋转
void up(ll x)//上传标记 
{ll l=c[x][0],r=c[x][1];
	mx[x]=max(max(mx[l],mx[r]),v[x]);
	sum[x]=sum[l]+sum[r]+v[x];
	s[x]=s[l]+s[r]+1;
}
void down(ll x)//下传标记 
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
void rot(ll x,ll &f)//旋转操作 
{ll y=fa[x],z=fa[y],l,r;
	l=(c[y][0]!=x);r=l^1;
	if(y==f)f=x;
	else {if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;}
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	up(y);up(x);
}
void spl(ll x,ll &f)//把x节点旋转到f这个位置 
{
	while(x!=f)
	{
		ll y=fa[x],z=fa[y];
		if(y!=f){if(c[y][0]==x^c[z][0]==y)rot(x,f);else rot(y,f);}
		rot(x,f);
	}
}
ll bui(ll l,ll r,ll prt)//直接建立出l到r之间的平衡树 
{ll x,mid;
    if(l>r)return 0;
	x=++tot;mid=(l+r)/2;
    fa[x]=prt;v[x]=mx[x]=sum[x]=a[mid];
    c[x][0]=bui(l,mid-1,x);c[x][1]=bui(mid+1,r,x);
    up(x);return x;
}
ll find(ll x,ll k)//在x为根的子树中找序列中的第k个是哪个节点 
{
	down(x);
	ll l=c[x][0],r=c[x][1];
	if(s[l]+1==k)return x;
	if(s[l]>=k)return find(l,k);
	else return find(r,k-s[l]-1);
}
ll get(ll l,ll r)//将区间(l,r)旋转到根的右儿子的左儿子上，返回根的右儿子 
{ll x=find(rt,l),y=find(rt,r+2);
	spl(x,rt);
	spl(y,c[rt][1]);
	return y;
} 
void ask(ll k)//询问序列中的第k个的权值是多少 
{ll x=find(rt,k+1);
	spl(x,rt);
	printf("%lld\n",v[rt]);
}
void add(ll l,ll r,ll z)//增加l到r这个区间 
{ll y=get(l,r);
	tag[c[y][0]]+=z;
	v[c[y][0]]+=z;
	mx[c[y][0]]+=z;
	sum[c[y][0]]+=z*s[c[y][0]];
	up(y);
}
void Max(ll l,ll r)//求l到r间的最大值 
{ll y=get(l,r);
	printf("%lld\n",mx[c[y][0]]);
}
void Sum(ll l,ll r)//求l到r间的权值和 
{ll y=get(l,r);
	printf("%lld\n",sum[c[y][0]]);
}
void Rev(ll l,ll r)//翻转l到r的这个区间 
{ll y=get(l,r);
	rev[c[y][0]]^=1;
}
void dfs(ll x)//遍历平衡树输出序列,调试用 
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
	mx[0]=-inf;//因为up的时候l或r可能等于0 
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
