给定一张包含n个点、m条边的有向图，并且给定起始点s和终点t，
求从s到t的最短路线和比最短路线多一个单位距离的路线的总方案数。

求s到t的最短路与次短路（这里要求只比最短路多1）的条数之和   
联想到最小，次小的一种更新关系： 
if(x<最小)更新最小，次小 
else if(==最小)更新方法数 
else if(x<次小)更新次小 
else if(x==次小)更新方法数 

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int head[2005],nxt[20005],to[20005],wei[20005],dis[2005][2],ans[2005][2],vis[2005][2],cnt=1,n,m,s,t;
int read(){
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    int res=0;
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res;
}
void add(int u,int v,int w){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
    wei[cnt]=w;
}
void init(){
    memset(head,0,sizeof head);
    memset(nxt,0,sizeof nxt);
    memset(to,0,sizeof to);
    memset(wei,0,sizeof wei);
    memset(dis,0x3f,sizeof dis);
    memset(ans,0,sizeof ans);
    memset(vis,0,sizeof vis);
    cnt=1;
}
struct node{
    int p,d,c;
    bool operator < (const node& other)const{
        return d>other.d;
    }
    bool operator > (const node& other)const{
        return d<other.d;
    }
};
priority_queue<node> q;
void solve(){
    while(!q.empty())q.pop();
    dis[s][0]=0;
    ans[s][0]=1;
    q.push((node){s,0,0});
    while(!q.empty()){
        node top=q.top();
        q.pop();
        int u=top.p,c=top.c,d=top.d;
        if(vis[u][c])continue;
        vis[u][c]=true;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i],w=wei[i];
            if(dis[v][0]>d+w){
                if(dis[v][0]!=0x3f3f3f3f){
                    dis[v][1]=dis[v][0];
                    ans[v][1]=ans[v][0];
                    q.push((node){v,dis[v][1],1});
                }
                dis[v][0]=d+w;
                ans[v][0]=ans[u][c];
                q.push((node){v,dis[v][0],0});
            }else if(dis[v][0]==d+w){
                ans[v][0]+=ans[u][c];
            }else if(dis[v][1]>d+w){
                dis[v][1]=d+w;
                ans[v][1]=ans[u][c];
                q.push((node){v,dis[v][1],1});
            }else if(dis[v][1]==d+w){
                ans[v][1]+=ans[u][c];
            }
        }
    }
}
int main(){
    int T=read();
    while(T--){
        init();
        n=read(),m=read();
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),w=read();
            add(u,v,w);
        }
        s=read(),t=read();
        solve();
		//dis[t][0]为最短路的方案数，dis[t][1]为次短路的方案数
		//这道题求从s到t的最短路线和比最短路线多一个单位距离的次短路的总方案数 
        if(dis[t][1]==dis[t][0]+1){
            printf("%d\n",ans[t][0]+ans[t][1]);
        }else{
            printf("%d\n",ans[t][0]);
        }
    }
    return 0;
}
