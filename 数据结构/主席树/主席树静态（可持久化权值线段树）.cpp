���� n���������ɵ����� a��������ָ���ı����� [l, r] ��ѯ�������ڵĵ� k Сֵ����1��n��m��2��10^5�� 

ʹ����ϯ�����ɽ����Ҳ�пɳ־û�Ȩֵ�߶�������̬����˼��ָ�������в����޸� 
��ϯ��ά���Ľڵ���Ȩֵ�������Ȩֵ�������ж��ٸ���Ȼ����ΪȨֵ���ܴܺ�����Ҫ������ɢ�� 

�ܽ᣺��ϯ���ܶ�ʱ�򣬴������һ����̬�����У������н��ж��ѯ��
ÿ��ѯ��һ�������ڵĵ�k��ֵ����������Ȩֵ��[x,y]֮������ĺͣ����ֵ����Сֵʲô�� 
ǰ����Ǹ����䣬��ζ����Ҫ�ɳ־û��������Ǹ���һ��Ȩֵ�ϵĲ�������ζ����ҪȨֵ�߶��� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;
ll a[mn],b[mn],rt[mn],ls[mn*25],rs[mn*25],s[mn*25],//�⼸������Ҫ���ĺܴ����n*4+n*logn 
cnt=0,tot,n,m;
void bui(ll &x,ll l,ll r)
{
	x=++cnt;s[x]=0;
	if(l==r)return ;
	ll mid=(l+r)/2;
	bui(ls[x],l,mid);
	bui(rs[x],mid+1,r);
}
//�ڵ�l��Ľڵ㵽��r��Ľڵ��У���xΪԭ���ĸ��ڵ㣬yΪ���ڵĸ��ڵ㣬�ڵ�v��Ľڵ��ϼ���һ�����������
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
ll ask(ll l,ll r,ll x,ll y,ll k)//ѯ�ʵ�l��Ľڵ㵽��r��Ľڵ��У�x��yΪ������ʷ�汾�ĸ��ڵ㣬��kС�Ľڵ��Ƕ��� 
{
	if(l==r)return l;
	ll mid=(l+r)/2,tmp=s[ls[y]]-s[ls[x]];
	if(tmp>=k)return ask(l,mid,ls[x],ls[y],k);
	else return ask(mid+1,r,rs[x],rs[y],k-tmp);
}
/*
ll ask(ll l,ll r,ll x,ll y,ll k)//������һ�£�ֻ�����ǵ�k�� 
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

����һ������:����һ������(�����Ϊ10^6),�Լ�m�������޸ĺ�����Ĵ�Сn.
Ȼ����n��ѯ��,�������xλ�õ����������е�ǰk���ĺ�.ǿ������.

�൱�������޸ģ������ѯ����ּ��� 
û����֣��������޸ĸĳ���˵�ӣ��Ҷ˵���ұ߼��ĵ����޸�
��ô������ÿ�ε����ѯ���൱����ǰ׺�ͣ�Ҳ����һ�������ѯ

��һ�����˵Ĵ����� 

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

��������Ϊn�����У�q��ѯ�ʣ�
ÿ��ѯ�ʸ���L,R����[L,R]��ѡ��һ���Ӽ���ͣ��޷��ճ�����С���Ƕ��١�
ѯ��ǿ�����ߡ�

���ݷ�Χ��n<=1e6��q<=1e6��1<=a(i)<=1e9��ʱ��4s��

�ȿ��Ǹ���n����,��μ����޷��ճ�����С���Ƕ���:
1.���ж��Ƿ���1,�����1��������1,����𰸾���1.
2.�������������[1,x],����[1,x+1]��Χ�ڵ������ܺ�Ϊsum,
��ô�Ϳ������[1,sum],���sum=x,˵��x������������,��Ϊx+1,
������x=sum,������[1,x+1]��Χ�������ܺ�,���ϵ���.
��ѯ[1,x]�ĺͿ�����Ȩֵ�߶���.
x������������쳲���������{1,2,3,5,....},��˴�������̫��,�ҹ�����O(log).

�����ѯ���Ƕ������,���������Ȩֵ�߶���������,���ɳ־û�Ȩֵ�߶���.�㷨�ܸ��Ӷ�O(n*log*log)

ֵ��ע����ǣ������Ŀ��ֱ�Ӷ�Ȩֵ�����߶�������ģ���Ϊ����Ŀ���������Ȩֵ�Ͻ��еĲ���
���Ҫ��ɢ��������ñ�֤����룬ѯ�ʵ�Ȩֵ��Ϊ��ɢ����ڵ��Ӧ��Ȩֵ
�������У��Ͳ�����ɢ����ֱ����Ȩֵ���в���Ҳ�ǿ��Ե� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define lim 1000000010
using namespace std;
ll a[mn],b[mn],rt[mn],ls[mn*40],
rs[mn*40],s[mn*40],//�⼸������Ҫ���ĺܴ����n*4+n*log(ֵ��)�����տ��Կ���*40 
cnt=0,tot,sum,n,m;
//�����λ��ȨֵΪx���ڶ�Ӧ�ڵ��ϼ���val���ܷ�ΧΪ(l,r)����ǰ�ڵ�Ϊv����һ���ڵ�Ϊlast 
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
//ѯ�ʷ�ΧΪ(a,b)����ǰ��ΧΪ(l,r)��x��y�ֱ�Ϊ������ʷ�汾 
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

2022 �㽭ʡ��F. Easy Fix--˼ά+��ϯ��
����һ������Ϊn������(���������е�i����Ϊx��a[i]Ϊ[1,i-1]��С��x�����ĸ�����b[i]Ϊ[i+1,n]��С��x�����ĸ�����
c[i]=min(a[i],b[i]))��֮�����һ����m����ʾ��������m�β�����ÿ�β�������������l��r��
��ʾ��������lλ�ú�rλ�õ������н������󽻻�������ж�Ӧ��c����ĺͣ�ע�⣬ÿ�β����Ƕ����ġ�

˼·:
�������ｫԭʼ�����б�����p�����С�
����������һ���������з��������׷��ֽ��� l��r����Ӱ��[1,l-1]��[r+1,n]��c[i]��
��������ֻ��Ҫ��c[l]��c[r]��[l+1,r-1]�ڵ�c[i]����һ�¡�
�µ�c[l]��c[r]:
�Խ����������˵�l��r��p[r]����l��λ�ã�����ֻ�����[1,l-1]�ж��ٸ���p[r]С������������tt����
��l����µ�c[l]�͵���min(tt,p[r]-tt-1)��
p[l]����r���λ�ã�����[r+1,n]�ж��ٸ���p[l]С������������tt������l����µ�c[r]�͵���min(tt,p[r]-tt-1)��
�������������[l+1,r-1]������c[i]��Ӱ�죺
����Ҫ������������p[l]<p[r]������������� p[r] ... p[l]
��[l+1,r-1]��������x���Խ��������ܻᷢ��a[i]���a[i]-1��b[i]���b[i]+1��
(���x<p[l]����x>p[r]��a[i]��b[i]�����䣬��p[l]<x<p[r]ʱ���������a[i]�ͱ����a[i]-1��b[i]�ͱ����b[i]+1)
��������һ�£�[l+1,r-1]��������Щ���Ĺ��׻��1��
���׼�1һ����b[i]��1,a[i]��1������Сֵ��1�����Ҫ�������x����Ҫ����p[l]<x<p[r]��
�����Ӧ��a[i]>=b[i]ʱ��a[i]�ټ�1�ͻᵼ��������Ĺ��׼�1��
ͬ���أ����ǿ���һ��[l+1,r-1]��������Щ���Ĺ��׻��1�ء���1Ҳһ����b[i]��1,a[i]��1������Сֵ��1��
���������xҲ���ȵ�����p[l]<x<p[r]����ҪҪ��b[i]��1��a[i]��1��������b[i]<=a[i]�ģ�
b[i]��1��͵ȼ�����Сֵ��1(���Ҫ��ԭ����a[i]-1>=b[i]+1)
����Ҫ������������p[l]>p[r]ʱ����Ҳͬ��������������ȥ���ǡ�
��[l+1,r-1]��������x���Խ��������ܻᷢ��a[i]���a[i]+1��b[i]���b[i]-1��
���׻��1�Ļ���Ҫ��p[r]<x<p[l]��a[i]>=b[i]��
���׻��1�Ļ���Ҫ��p[r]<x<p[l]��a[i]+1<=b[i]-1��

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

int query(int l,int r,int x,int y,int num,int type)//��ѯ<= num [type]�ĸ���
{
	if(r<=num)return t[y].op[type]-t[x].op[type];
	int mid=(l+r)>>1;
	int ans=0;
	if(num>=l) ans+=query(l,mid,t[x].l,t[y].l,num,type);
	if(num>mid) ans+=query(mid+1,r,t[x].r,t[y].r,num,type);
	return ans;
}
int query(int l,int r,int x,int y,int num)//��ѯ<= num�ĸ���
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
