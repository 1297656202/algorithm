01分数规划，简单的来说，就是有一些二元组（si，pi），
从中选取一些二元组，使得∑si / ∑pi最大（最小）。
这种题一类通用的解法就是，我们假设x = ∑si / ∑pi的最大（小）值，
那么就有x * ∑pi = ∑si ，即∑si  - x * ∑pi= 0。
也就是说，当某一个值x满足上述式子的时候，它就是要求的值。
我们可以想到枚举……不过再想想，这个可以二分答案。
所以我们直接二分答案，将每个值都变为si - x * pi，然后将符合条件的加起来，使得其和尽量大， 
如果通过某种选择，使得挑选的数之和>0,说明答案小了，<0则说明答案大了，这样计算即可。
这是一种解决问题的方法，具体应该怎么做我们要看题来分析。
01分数规划有这样几种基本的题型（当然还有很多别的……暂时不在juruo的考虑范围内）
1.01分数规划
2.最优比率生成树
3.最优比率生成环
（当然还有什么最优比率最小割等等……不在juruo当前研究范围之内）
最优比率生成环问题
即找到一个环，其中点权为的d[i],边权为p[i],求环上各点的权值除以环上各边的权值的值最大 
可以二分一个答案，如果求和(i=1~t)mid*p[i]-d[i]<0,则 (i=1~n)mid<d[i]的和/p[i]的和,
也就是二分答案，我们用mid*p[i-j]-d[i]代替(i-j)的权值， 
则用spfa可求出负环，反之则不行，然后根据mid调整答案 

#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef double dd;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=1010;
int n,m;
int a[maxn];
struct node{int v,dis,nxt;}E[5010];
int head[maxn],tot;
int vis[maxn],num[maxn];
dd d[maxn]; 

void add(int u,int v,int dis)
{
    E[++tot].nxt=head[u];
    E[tot].v=v; E[tot].dis=dis;
    head[u]=tot;
}

int check(dd x)
{
    queue<int> q; 
    for(int i=1;i<=n;++i)//因为图不一定连通，所以初始所有结点入队
    {
    	q.push(i);
    	d[i]=0; vis[i]=num[i]=1;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop(); vis[u]=0;
        for(int i=head[u];i;i=E[i].nxt)
        {
            int v=E[i].v; dd dis=(dd)E[i].dis;
            if(d[v]>d[u]+x*dis-(dd)a[u])//边权为mid*Tim[e_i]-Fun[u_i]
            {
                d[v]=d[u]+x*dis-(dd)a[u];
                if(!vis[v])
                {
                    q.push(v); vis[v]=1;
                    if(++num[v]>=n) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),dis=read();
        add(u,v,dis);
    }
    dd L=0,R=1000010,mid;
    while(R-L>1e-4)
    {
        mid=(L+R)/2;
        if(check(mid))L=mid;
        else R=mid;
    }
    printf("%.2lf",L);
    return 0;
}
