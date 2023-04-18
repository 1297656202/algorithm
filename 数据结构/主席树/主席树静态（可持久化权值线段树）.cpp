给定 n个整数构成的序列 a，将对于指定的闭区间 [l, r] 查询其区间内的第 k 小值。（1≤n，m≤2×10^5） 

使用主席树即可解决，也叫可持久化权值线段树，静态的意思是指整个序列不带修改 
主席树维护的节点是权值，即这个权值的数共有多少个，然后因为权值可能很大，所以要加上离散化 

总结：主席树很多时候，处理的是一个静态的序列，对序列进行多次询问
每次询问一个区间内的第k大值，或者是在权值在[x,y]之间的数的和，最大值，最小值什么的 
前面的那个区间，意味着需要可持久化，后面那个对一段权值上的操作，意味着需要权值线段树 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll a[mn],b[mn],rt[mn],ls[mn*25],rs[mn*25],s[mn*25],//这几个数组要开的很大，最大到n*4+n*logn 
cnt=0,tot,n,m;
void bui(ll &x,ll l,ll r)
{
	x=++cnt;s[x]=0;
	if(l==r)return ;
	ll mid=(l+r)/2;
	bui(ls[x],l,mid);
	bui(rs[x],mid+1,r);
}
//在第l大的节点到第r大的节点中，以x为原来的根节点，y为现在的根节点，在第v大的节点上加上一个插进来的数
ll ins(ll l,ll r,ll x,ll v) 
{ll y=++cnt;
	s[y]=s[x]+1;
	if(l==r)return y;
	ls[y]=ls[x];rs[y]=rs[x];
	ll mid=(l+r)/2;
	if(v<=mid)ls[y]=ins(l,mid,ls[x],v);
	else rs[y]=ins(mid+1,r,rs[x],v);
	return y;
}
ll ask(ll l,ll r,ll x,ll y,ll k)//询问第l大的节点到第r大的节点中，x，y为两个历史版本的根节点，第k小的节点是多少 
{
	if(l==r)return l;
	ll mid=(l+r)/2,tmp=s[ls[y]]-s[ls[x]];
	if(tmp>=k)return ask(l,mid,ls[x],ls[y],k);
	else return ask(mid+1,r,rs[x],rs[y],k-tmp);
}
/*
ll ask(ll l,ll r,ll x,ll y,ll k)//跟上面一致，只不过是第k大 
{
	if(l==r)return l;
	ll mid=(l+r)/2,tmp=s[rs[y]]-s[rs[x]];
	if(tmp>=k)return ask(mid+1,r,rs[x],rs[y],k);
	else return ask(l,mid,ls[x],ls[y],k-tmp);
}
*/
int main()
{
	ll h,x,y,k,i,j,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	   scanf("%lld",&a[i]);
	   b[i]=a[i];
	}
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	bui(rt[0],1,tot);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
		rt[i]=ins(1,tot,rt[i-1],a[i]);
	}
	while(m--)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		printf("%lld\n",b[ask(1,tot,rt[x-1],rt[y],k)]);
	}
	return 0;
}

简述一下题意:给出一个区间(长度最长为10^6),以及m次区间修改和区间的大小n.
然后是n次询问,求出包含x位置的所有区间中的前k个的和.强制在线.

相当于区间修改，单点查询，差分即可 
没错，差分，将区间修改改成左端点加，右端点的右边减的单点修改
那么，我们每次单点查询就相当于求前缀和，也就是一个区间查询

贴一个别人的代码借鉴 

int n,m,num,tot;
int a[N],b[N],root[N<<6];
long long ans=1;
struct tree {
    long long sum; 
    int cnt,l,r;
}t[N<<6];
vector<int>be[N],ed[N];
void update(int &u,int l,int r,int pre,int pos,int v){
    u=++tot; t[u]=t[pre];
    t[u].cnt+=v, t[u].sum+=1ll*v*b[pos];
    if(l==r) return;
    int mid=(l+r)>>1;
    if(pos<=mid) update(t[u].l,l,mid,t[pre].l,pos,v);
    else update(t[u].r,mid+1,r,t[pre].r,pos,v);
}
long long query(int u,int l,int r,int k){
    int num=t[t[u].l].cnt;
    if(l==r) return t[u].sum/(1ll*t[u].cnt)*1ll*k;
    int mid=(l+r)>>1;
    if(k<=num) return query(t[u].l,l,mid,k);
    else return query(t[u].r,mid+1,r,k-num)+t[t[u].l].sum;
}
int main(){
    m=read(),n=read();
    for(int i=1;i<=m;i++) {
        int x=read(),y=read();
        a[i]=read(),b[i]=a[i];
        be[x].push_back(i), ed[y+1].push_back(i);
    }
    sort(b+1,b+1+m); int num=unique(b+1,b+1+m)-b-1;
    for(int i=1;i<=n;i++) {
        root[i]=root[i-1];
        for(int j=0;j<be[i].size();j++) {
            int p=lower_bound(b+1,b+1+num,a[be[i][j]])-b;
            update(root[i],1,num,root[i],p,1);
        }
        for(int j=0;j<ed[i].size();j++) {
            int p=lower_bound(b+1,b+1+num,a[ed[i][j]])-b;
            update(root[i],1,num,root[i],p,-1);
        }
    }
    for(int i=1;i<=n;i++) {
      	int x=read(),a=read(),b=read(),c=read(),k=(1ll*a*ans+b)%c+1;
        if(k>t[root[x]].cnt) ans=t[root[x]].sum;
        else ans=query(root[x],1,num,k);
        printf("%lld\n",ans);
    }
    return 0;
}

给定长度为n的序列，q次询问，
每次询问给出L,R，问[L,R]中选择一个子集求和，无法凑出的最小数是多少。
询问强制在线。

数据范围：n<=1e6，q<=1e6，1<=a(i)<=1e9，时限4s。

先考虑给定n个数,如何计算无法凑出的最小数是多少:
1.先判断是否有1,如果有1则可以组成1,否则答案就是1.
2.假设现在能组成[1,x],设在[1,x+1]范围内的数的总和为sum,
那么就可以组成[1,sum],如果sum=x,说明x不能再增长了,答案为x+1,
否则令x=sum,继续求[1,x+1]范围内数的总和,不断递推.
查询[1,x]的和可以用权值线段树.
x的增长至少是斐波那契数列{1,2,3,5,....},因此次数不会太大,我估计是O(log).

这题的询问是对区间的,因此用区间权值线段树就行了,即可持久化权值线段树.算法总复杂度O(n*log*log)

值得注意的是，这道题目是直接对权值进行线段树处理的，因为其题目本身就是在权值上进行的操作
如果要离散化，必须得保证其插入，询问的权值都为离散过后节点对应的权值
不过不行，就不用离散化，直接在权值进行操作也是可以的 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define lim 1000000010
using namespace std;
ll a[mn],b[mn],rt[mn],ls[mn*40],
rs[mn*40],s[mn*40],//这几个数组要开的很大，最大到n*4+n*log(值域)，保险可以开个*40 
cnt=0,tot,sum,n,m;
//插入的位置权值为x，在对应节点上加上val，总范围为(l,r)，当前节点为v，上一个节点为last 
void ins(ll x,ll val,ll l,ll r,ll &v,ll last)
{
	v=++cnt;
	ls[v]=ls[last];
	rs[v]=rs[last];
	s[v]=s[last]+val;
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(x<=mid)ins(x,val,l,mid,ls[v],ls[last]);
	else ins(x,val,mid+1,r,rs[v],rs[last]);
}
//询问范围为(a,b)，当前范围为(l,r)，x，y分别为两个历史版本 
void ask(ll a,ll b,ll l,ll r,ll x,ll y)
{
	if(a<=l&&b>=r){sum+=s[y]-s[x];return ;}
	ll mid=(l+r)/2;
	if(a<=mid)ask(a,b,l,mid,ls[x],ls[y]);
	if(b>mid)ask(a,b,mid+1,r,rs[x],rs[y]);
}
int main()
{
	ll x,y,k,i,j,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		ins(a[i],a[i],1,lim,rt[i],rt[i-1]);
	ll last=0;
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		x=(x+last)%n+1;
		y=(y+last)%n+1;
		if(x>y)swap(x,y);
		ll tmp=0;
		while(1)
		{
			sum=0;ask(1,min(tmp+1,(ll)lim),1,lim,rt[x-1],rt[y]);
			if(sum==tmp)break;
			tmp=sum;
		}
		last=tmp+1;
		printf("%lld\n",last);
	}
	return 0;
}

2022 浙江省赛F. Easy Fix--思维+主席树
给定一个长度为n的序列(假设序列中第i个数为x，a[i]为[1,i-1]中小于x的数的个数，b[i]为[i+1,n]中小于x的数的个数，
c[i]=min(a[i],b[i]))，之后给定一个数m，表示接下来有m次操作，每次操作给定两个数l和r，
表示将序列中l位置和r位置的数进行交换，求交换完后序列对应的c数组的和，注意，每次操作是独立的。

思路:
我们这里将原始的序列保存在p数组中。
首先我们拿一个样例进行分析，容易发现交换 l，r不会影响[1,l-1]和[r+1,n]的c[i]。
所以我们只需要对c[l]，c[r]和[l+1,r-1]内的c[i]再算一下。
新的c[l]，c[r]:
对交换的两个端点l和r，p[r]到了l的位置，我们只需计算[1,l-1]有多少个比p[r]小的数，假设有tt个，
则l点的新的c[l]就等于min(tt,p[r]-tt-1)。
p[l]到了r点的位置，计算[r+1,n]有多少个比p[l]小的数，假设有tt个，则l点的新的c[r]就等于min(tt,p[r]-tt-1)。
交换两个数后对[l+1,r-1]内数的c[i]的影响：
当我要交换的两个数p[l]<p[r]，交换完后变成了 p[r] ... p[l]
对[l+1,r-1]区间内数x而言交换完后可能会发生a[i]变成a[i]-1，b[i]变成b[i]+1。
(如果x<p[l]或者x>p[r]，a[i]和b[i]都不变，当p[l]<x<p[r]时，交换完后a[i]就变成了a[i]-1，b[i]就变成了b[i]+1)
可以想象一下，[l+1,r-1]区间内哪些数的贡献会减1。
贡献减1一定是b[i]加1,a[i]减1导致最小值减1，这就要求这个数x首先要满足p[l]<x<p[r]，
且其对应的a[i]>=b[i]时，a[i]再减1就会导致这个数的贡献减1。
同样地，我们考虑一下[l+1,r-1]区间内哪些数的贡献会加1呢。加1也一定是b[i]加1,a[i]减1导致最小值加1，
所以这个数x也首先得满足p[l]<x<p[r]，且要要求b[i]加1，a[i]减1后依旧是b[i]<=a[i]的，
b[i]加1后就等价于最小值加1(这就要求原来的a[i]-1>=b[i]+1)
当我要交换的两个数p[l]>p[r]时，我也同样地像上面那样去考虑。
对[l+1,r-1]区间内数x而言交换完后可能会发生a[i]变成a[i]+1，b[i]变成b[i]-1。
贡献会减1的话，要求p[r]<x<p[l]，a[i]>=b[i]。
贡献会加1的话，要求p[r]<x<p[l]，a[i]+1<=b[i]-1。

const int inf=8e18;
const int maxn=2e5+100;
int a[maxn],c[maxn],p[maxn],b[maxn],d[maxn],pre[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int val)
{
	while(x<maxn)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}
int ask(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
struct node
{
	int l,r;
	int sum;
	int op[5];
} t[maxn*32];
int cnt,root[maxn];
void update(int l,int r,int &x,int y,int num,vector<int>v)
{
	x=++cnt;
	t[x]=t[y];
	t[x].sum++;
	for(auto it:v) t[x].op[it]++;
	//t[x].op[type]++;
	if(l==r)return ;
	int mid=(l+r)>>1;
	if(num<=mid) update(l,mid,t[x].l,t[y].l,num,v);
	else update(mid+1,r,t[x].r,t[y].r,num,v);
}

int query(int l,int r,int x,int y,int num,int type)//查询<= num [type]的个数
{
	if(r<=num)return t[y].op[type]-t[x].op[type];
	int mid=(l+r)>>1;
	int ans=0;
	if(num>=l) ans+=query(l,mid,t[x].l,t[y].l,num,type);
	if(num>mid) ans+=query(mid+1,r,t[x].r,t[y].r,num,type);
	return ans;
}
int query(int l,int r,int x,int y,int num)//查询<= num的个数
{
	if(r<=num)return t[y].sum-t[x].sum;
	int mid=(l+r)>>1;
	int ans=0;
	if(num>=l) ans+=query(l,mid,t[x].l,t[y].l,num);
	if(num>mid) ans+=query(mid+1,r,t[x].r,t[y].r,num);
	return ans;
}
signed main()
{
	IOS
	int n,q;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>p[i];
	}
	for(int i=1; i<=n; i++)
	{
		a[i]=ask(p[i]);
		update(p[i],1);
	}
	for(int i=1; i<=n; i++) update(p[i],-1);
	for(int i=n; i>=1; i--)
	{
		b[i]=ask(p[i]);
		update(p[i],1);
		d[i]=min(a[i],b[i]);
	}
	for(int i=1; i<=n; i++)
	{
		//cout<<b[i]<<" ";
		pre[i]=pre[i-1]+d[i];
	}
	//cout<<"\n";
	for(int i=1; i<=n; i++)
	{
		vector<int>v;
		if(a[i]<=b[i]) v.pb(1);
		if(a[i]-1>b[i]) v.pb(2);
		if(a[i]>=b[i]) v.pb(3);
		if(a[i]<b[i]-1) v.pb(4);
		update(1,(int)1e6,root[i],root[i-1],p[i],v);
	}
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		if(l==r)
		{
			cout<<pre[n]<<"\n";
			continue;
		}
		int ans=pre[n]-d[l]-d[r];
		if(p[l]<p[r])
		{
			int s2=query(1,1e6,root[l],root[r-1],p[r],2)-query(1,1e6,root[l],root[r-1],p[l],2);
			int s1=query(1,1e6,root[l],root[r-1],p[r],1)-query(1,1e6,root[l],root[r-1],p[l],1);
			ans+=s2-s1;
		}
		else
		{
			int s4=query(1,1e6,root[l],root[r-1],p[l],4)-query(1,1e6,root[l],root[r-1],p[r],4);
			int s3=query(1,1e6,root[l],root[r-1],p[l],3)-query(1,1e6,root[l],root[r-1],p[r],3);
			ans+=s4-s3;
		}
		int low_l=query(1,1e6,root[l],root[r],p[l]);
		int low_r=query(1,1e6,root[l-1],root[r-1],p[r]);
		ans+=min(a[l]+low_l,b[l]-low_l);
		ans+=min(a[r]-low_r,b[r]+low_r);
		cout<<ans<<"\n";
	}
}
