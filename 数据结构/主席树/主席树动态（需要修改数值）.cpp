����һ������ n���������� ����Ҫ֧�����ֲ�����
Q l r k ��ʾ��ѯ�±������� [l,r]�еĵ� kС����
C x y ��ʾ�� a_x��Ϊ y
1��n��m��10^5

����˵˵��ô����޸���ϯ����
����һ���kth���⣬���ǵ���ϯ�������ǰ׺�ͣ�����������Ŀ����������Ҷ˵����ϯ������¾������kth��
���ǵ�����֮ǰʹ����ϯ�����ص�ά������ǰ׺�ͣ�֧���޸ĵĻ���
ֻҪ��ǰ׺�ͽ����ó�������״����ά������ϯ��ֻҪά���´��λ�þͺá���Ȼά��λ�����Ҫ��ɢ��һ�¡�

���ά������Ԫ��λ�õ����䣺����������ѯ[L,R]�ĵ�kС��
���������ҵ������Ķ�Ӧ[1,R]��[1,L-1]ǰ׺�͵ļ������䣨���Ľڵ㣬�����ڲ��߶����ĸ��ڵ㣩
�������߶��������ã���Ϊ�˰��������ҵ�λ�������Ӧ�ļ����ڲ��߶�����

�ڲ�ά��������ֵ�ĳ��ִ�����ÿ���߶�����ʾ���ڸ��ڵ��Ӧ����������У�ÿ����ֵ���ֵĴ���

Ȼ��Ҫע����ǣ��п��ܿռ�Ὺ�úܴ󣬣�n+m��*logn*logn ����ģ����Ҫ*400���ң��������ࣨ����Ŀ���ƶ��٣� 
�������ɢ��Ϊ��n+m��*logn*logm������ռ�û�б��Ļ���������Ŀ����Ͳ�������ɢ���в��룬ѯ��ֵ��ʱ�� 
Ҳ���Բ���ɢ 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll a[mn],b[mn*2],
t1[mn],t2[mn],rt[mn],ls[mn*400],
rs[mn*400],s[mn*400],cnt=0,tot=0,ge,n,m;
struct w{ll l,r,k;char c[3];}q[mn];
inline ll low(ll i){return i&(-i);}
//���ڵĶ˵�Ϊx����Χ��l��r����Ҫ�����λ��Ϊpos������val 
void ins(ll &x,ll l,ll r,ll pos,ll val) 
{
	if(x==0)x=++cnt;s[x]+=val;
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(pos<=mid)ins(ls[x],l,mid,pos,val);
	else ins(rs[x],mid+1,r,pos,val);
} 
void add(ll k,ll x,ll val)//�����ڲ��߶�����kλ�����λ��x���λ�ã�����val 
{ll i;
	for(i=x;i<=n;i+=low(i))ins(rt[i],1,tot,k,val);
}
ll query(ll l,ll r,ll k)//ѯ�ʵڶ����߶����еĵ�k�� 
{ll i;
	if(l==r)return l;
	ll mid=(l+r)/2,tmp1=0,tmp2=0;
	for(i=1;i<=t1[0];i++)tmp1+=s[ls[t1[i]]];
	for(i=1;i<=t2[0];i++)tmp2+=s[ls[t2[i]]];
	ll tmp=tmp2-tmp1;
	if(tmp>=k)
	{
		for(i=1;i<=t1[0];i++)t1[i]=ls[t1[i]];
		for(i=1;i<=t2[0];i++)t2[i]=ls[t2[i]];
		return query(l,mid,k);
	}
	else 
	{
		for(i=1;i<=t1[0];i++)t1[i]=rs[t1[i]];
		for(i=1;i<=t2[0];i++)t2[i]=rs[t2[i]];
		return query(mid+1,r,k-tmp);
	}
}
ll ask(ll l,ll r,ll k)//ѯ�ʣ�ע������main������ǰ׺�ʹ���  
{ll i;
	t1[0]=t2[0]=0;
	for(i=l;i;i-=low(i))t1[++t1[0]]=rt[i];
	for(i=r;i;i-=low(i))t2[++t2[0]]=rt[i];
	return query(1,tot,k);
}
int main()
{
	ll x,y,k,i,j,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	    scanf("%lld",&a[i]);
        b[i]=a[i];
	}
	tot=n;
	for(i=1;i<=m;i++)
	{
		scanf("%s",q[i].c);
		if(q[i].c[0]=='C')
		{
			scanf("%lld%lld",&q[i].l,&q[i].k);
			b[++tot]=q[i].k;
		}
		else scanf("%lld%lld%lld",&q[i].l,&q[i].r,&q[i].k);
	}
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(i=1;i<=n;i++)
	   a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	for(i=1;i<=n;i++)//
	   add(a[i],i,1);
	for(i=1;i<=m;i++)
	{
		if(q[i].c[0]=='Q')printf("%lld\n",b[ask(q[i].l-1,q[i].r,q[i].k)]);//ѯ�ʣ�l,r���еĵ�k�� 
		else//����֣� ����l��1������r����1��k�൱��r�� 
		{
			add(a[q[i].l],q[i].l,-1);
			x=lower_bound(b+1,b+tot+1,q[i].k)-b;
			a[q[i].l]=x;
			add(a[q[i].l],q[i].l,1);
		}
	}
	return 0;
}

����
2e5�����飬q������
1.��a[x]��Ϊy
2.���±�l��r�����е�a[i]ͨ���ӷ����ܹ��ɵ���С��ֵ

ǰ����ϯ����̬�ĵ���Ŀ�ı��壬���ž�̬�Ĵ���ħ�ļ��� 
