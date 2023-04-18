您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
1.插入x数
2.删除x数(若有多个相同的数，因只删除一个)
3.查询x数的排名(排名定义为比当前数小的数的个数+1)
4.查询排名为x的数
5.求x的前驱(前驱定义为小于x，且最大的数)
6.求x的后继(后继定义为大于x，且最小的数)

可以用权值线段树实现，以权值为具体维护的每个节点即可，即这个权值的数共有多少个
注意：如果权值有可能很大，或者为负数，就需要离散化一下 

如果要询问某个区间的第k大，则需要用到可持久化权值线段树（主席树） 

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
        if(val[i]!=4)//把所有（除了询问排名为k的数是多少）的询问的数字给离散化处理 
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
