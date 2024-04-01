然后，树状数组对于很多满足可累积性质的算法都适用，只是需要魔改一下就行，比如说求max和xor值
 
有一个初始为空的序列。维护三种命令：
p1.ADD x：把x加到数列最后；
p2.REMOVE x：在数列中找到等于x的数，删除
p3.XOR between x1 and x2：对于数列中所有值在[x1,x2]中的数异或并
输出结果；
n 加入的数都不超过20000，询问次数<=60000 

对于Remove操作，我们其实可以将其视为Add操作。因为a xor a=0；a xor 0=a，所以Remove(X)相当于add(X)
然后，就把树状数组的代码直接套上去，只是把+改成xor就行

下面是魔改max的算法 
hdu1754的代码，这一题就是一道单点修改和区间查询最大值的题。
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int MAXN = 3e5;
int a[MAXN], h[MAXN];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}
void updata(int x)
{
    int lx, i;
    while (x <= n)
    {
        h[x] = a[x];
        lx = lowbit(x);
        for (i=1; i<lx; i<<=1)
            h[x] = max(h[x], h[x-i]);
        x += lowbit(x);
    }       
}
int query(int x, int y)
{
    int ans = 0;
    while (y >= x)
    {
        ans = max(a[y], ans);
        y --;
        for (; y-lowbit(y) >= x; y -= lowbit(y))
            ans = max(h[y], ans);
    }
    return ans;
}
int main()
{
    int i, j, x, y, ans;
    char c;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=1; i<=n; i++)
            h[i] = 0;
        for (i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            updata(i);
        }
        for (i=1; i<=m; i++)
        {
            scanf("%c",&c);
            scanf("%c",&c);
            if (c == 'Q')
            {
                scanf("%d%d",&x,&y);
                ans = query(x, y);
                printf("%d\n",ans);
            }
            else if (c == 'U')
            {
                scanf("%d%d",&x,&y);
                a[x] = y;
                updata(x);
            }
        }
    }
    return 0;
}