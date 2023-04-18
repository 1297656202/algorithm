//无向图全局最小割，也就是一张无向图如何以最小的代价划分为两个连通块 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxm=505;
const int inf=1e9;
int g[maxm][maxm];
int v[maxm];//v[i]表示i合并到的顶点
int dis[maxm];//dis表示该点与A集合中所有点之间的边的长度之和
bool mark[maxm];//标记已经合并到集合里的数
int n,m;
int sw(){
    int res=inf;
    for(int i=0;i<n;i++){//开始把合并的顶点设置成自己
        v[i]=i;
    }
    while(n>1){
        int pre=0;//pre表示之前加入A集合的点，以0点为第一个加入A集合的点
        memset(mark,0,sizeof mark);
        memset(dis,0,sizeof dis);
        for(int i=1;i<n;i++){
            int k=-1;
            for(int j=1;j<n;j++){
                if(!mark[v[j]]){
                    dis[v[j]]+=g[v[pre]][v[j]];
                    if(k==-1||dis[v[k]]<dis[v[j]]){
                        k=j;
                    }
                }
            }
            mark[v[k]]=1;
            if(i==n-1){
                res=min(res,dis[v[k]]);
                for(int j=0;j<n;j++){
                    g[v[j]][v[pre]]=g[v[pre]][v[j]]+=g[v[j]][v[k]];
                }
                v[k]=v[--n];
            }
            pre=k;
        }
    }
    return res;
}
signed main(){
    while(scanf("%d%d",&n,&m)!=EOF){
   		memset(g,0,sizeof g);
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]=g[b][a]+=c;
        }
        printf("%d\n",sw());
    }
    return 0;
}
