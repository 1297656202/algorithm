luogu2168:荷马史诗，类似的还有合并果子 
有n个单词，给出每个单词出现的次数，求出用k进制串表示所有单词的最小长度，然后在这种情况下最长的k进制串是多长

次数就是每一个节点的权值，出现的越多的长度尽量短，出现得少的长度可以多一点，这正好和哈夫曼树的思想差不多，
权值越大的离跟越远，唯一值得注意的是第一次合并时该合并(n-2)%(k-1)+2个，可以先添加一些空节点凑数 
ans就是表示所有单词的最小长度，也就是带权路径的总和，同时也是合并果子里的代价和，
最后一个节点提取出来就是树的高度，也就是最长的k进制串是多长
如果想要得到具体的树，就将每一次从堆里面提出来的节点的父节点记录为合成的新节点，就可以得到具体的树
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
struct w{ll v,h;};
ll ans=0,n,m;
bool operator <(w a,w b){return a.v>b.v||(a.v==b.v&&a.h>b.h);}
priority_queue<w>q;//构造小根堆 
int main()
{
	ll i,j,k,x;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        q.push((w){x,0});
    }
    while((q.size()-1)%(m-1)!=0)q.push((w){0,0});//添加空节点 
    while(q.size()>1)
    {
        ll h=0,v=0;
        for(i=1;i<=m;i++)
        {
            w u=q.top();q.pop();
            h=max(h,u.h);
            v+=u.v;
        }
        ans+=v;
        q.push((w){v,h+1});
    }
    printf("%lld\n%lld\n",ans,q.top().h);
    return 0;
}
