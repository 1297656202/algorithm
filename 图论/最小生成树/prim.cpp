//复杂度O(n^2) 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 507, M = 5000007, INF = 0x3f3f3f3f;
int g[N][N], dist[M], n, m, ans;
bool vis[N];
int prim(){
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    int res = 0;
    for(int i = 0;i < n; ++ i){
        int t = 0;
        for(int j = 1; j <= n; ++ j){
            if(!vis[j] && (t == 0 || dist[j] < dist[t])){
                t = j;
            }
        }
        if(i && dist[t] == INF)return INF;
        if(i)res += dist[t];
        vis[t] = 1;
        for(int y = 1; y <= n; ++ y){
            if(!vis[y])dist[y] = min(dist[y], g[t][y]);
        }
    }
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++ i)g[i][i] = 0;
    for(int i = 1; i <= m; ++ i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    if(prim() == INF)puts("impossible");//不存在最小生成树
    else {
        for(int i = 2; i <= n; ++ i)
        ans += dist[i];
        if(ans == INF)puts("impossible");
        else printf("%d\n", ans);
    }
    return 0;
}


