01�����滮���򵥵���˵��������һЩ��Ԫ�飨si��pi����
����ѡȡһЩ��Ԫ�飬ʹ�á�si / ��pi�����С����
������һ��ͨ�õĽⷨ���ǣ����Ǽ���x = ��si / ��pi�����С��ֵ��
��ô����x * ��pi = ��si ������si  - x * ��pi= 0��
Ҳ����˵����ĳһ��ֵx��������ʽ�ӵ�ʱ��������Ҫ���ֵ��
���ǿ����뵽ö�١������������룬������Զ��ִ𰸡�
��������ֱ�Ӷ��ִ𰸣���ÿ��ֵ����Ϊsi - x * pi��Ȼ�󽫷��������ļ�������ʹ����;����� 
���ͨ��ĳ��ѡ��ʹ����ѡ����֮��>0,˵����С�ˣ�<0��˵���𰸴��ˣ��������㼴�ɡ�
����һ�ֽ������ķ���������Ӧ����ô������Ҫ������������
01�����滮���������ֻ��������ͣ���Ȼ���кܶ��ġ�����ʱ����juruo�Ŀ��Ƿ�Χ�ڣ�
1.01�����滮
2.���ű���������
3.���ű������ɻ�
����Ȼ����ʲô���ű�����С��ȵȡ�������juruo��ǰ�о���Χ֮�ڣ�
���ű������ɻ�����
���ҵ�һ���������е�ȨΪ��d[i],��ȨΪp[i],���ϸ����Ȩֵ���Ի��ϸ��ߵ�Ȩֵ��ֵ��� 
���Զ���һ���𰸣�������(i=1~t)mid*p[i]-d[i]<0,�� (i=1~n)mid<d[i]�ĺ�/p[i]�ĺ�,
Ҳ���Ƕ��ִ𰸣�������mid*p[i-j]-d[i]����(i-j)��Ȩֵ�� 
����spfa�������������֮���У�Ȼ�����mid������ 

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
    for(int i=1;i<=n;++i)//��Ϊͼ��һ����ͨ�����Գ�ʼ���н�����
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
            if(d[v]>d[u]+x*dis-(dd)a[u])//��ȨΪmid*Tim[e_i]-Fun[u_i]
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
