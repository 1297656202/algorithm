����Ҫдһ�����ݽṹ���ɲο���Ŀ���⣩����ά��һЩ����������Ҫ�ṩ���²�����
1.����x��
2.ɾ��x��(���ж����ͬ��������ֻɾ��һ��)
3.��ѯx��������(��������Ϊ�ȵ�ǰ��С�����ĸ���+1)
4.��ѯ����Ϊx����
5.��x��ǰ��(ǰ������ΪС��x����������)
6.��x�ĺ��(��̶���Ϊ����x������С����)

������Ȩֵ�߶���ʵ�֣���ȨֵΪ����ά����ÿ���ڵ㼴�ɣ������Ȩֵ�������ж��ٸ�
ע�⣺���Ȩֵ�п��ܴܺ󣬻���Ϊ����������Ҫ��ɢ��һ�� 

���Ҫѯ��ĳ������ĵ�k������Ҫ�õ��ɳ־û�Ȩֵ�߶�������ϯ���� 

#include<cstdio>
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
#define int long long
#define ls (o<<1)
#define rs (ls|1)
int b[100500];
int a[100500];
int val[100500];
int st[405000];
int n;
int tot;
inline void add_or_del(int o,int l,int r,int k,int pos)
{
    st[o]+=pos;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(k<=mid) add_or_del(ls,l,mid,k,pos);
    else add_or_del(rs,mid+1,r,k,pos);
}
inline int x_rank_n(int o,int l,int r,int k)
{
    if(l==r) return 1;
    int mid=(l+r)>>1;
    if(k<=mid) return x_rank_n(ls,l,mid,k);
    else return st[ls]+x_rank_n(rs,mid+1,r,k);
}
inline int n_rank_x(int o,int l,int r,int k)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(st[ls]>=k) return n_rank_x(ls,l,mid,k);
    else return n_rank_x(rs,mid+1,r,k-st[ls]);
}
signed main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        val[i]=read();
        a[i]=read();
        if(val[i]!=4)//�����У�����ѯ������Ϊk�����Ƕ��٣���ѯ�ʵ����ָ���ɢ������ 
            b[++tot]=a[i];
    }
    sort(b+1,b+tot+1);
    for(int i=1;i<=n;i++)
    {
        if(val[i]!=4)
            a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    }
    for(int i=1;i<=n;i++)
    {
        switch(val[i])
        {
            case 1: add_or_del(1,1,tot,a[i],1);break;
            case 2: add_or_del(1,1,tot,a[i],-1);break;
            case 3: put(x_rank_n(1,1,tot,a[i]));putchar('\n');break;
            case 4: put(b[n_rank_x(1,1,tot,a[i])]);putchar('\n');break;
            case 5: put(b[n_rank_x(1,1,tot,x_rank_n(1,1,tot,a[i])-1)]);putchar('\n');break;
            default: put(b[n_rank_x(1,1,tot,x_rank_n(1,1,tot,a[i]+1))]);putchar('\n');
        }
    }
    return 0;
}
