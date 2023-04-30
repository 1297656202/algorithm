#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Log=12;
const int N=610;
const int inf=1e9;
int n,m,Q;
int maxv[Log][Log][N][N];
int pre[N],val[N][N]; 
void init(){
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)maxv[0][0][i][j]=val[i][j];
	pre[2]=pre[3]=1;
	for(int i=4,up=max(n,m);i<=up;i++)pre[i]=pre[i>>1]+1;
	int up1=pre[n]+1,up2=pre[m]+1;
	for(int l1=0;l1<=up1;l1++){
		for(int l2=0;l2<=up2;l2++){
			if(!l1&&!l2) continue;
			for(int i=1;(i+(1<<l1)-1)<=n;i++){
				for(int j=1;(j+(1<<l2)-1)<=m;j++){
					if(l2)maxv[l1][l2][i][j]=max(maxv[l1][l2-1][i][j],maxv[l1][l2-1][i][j+(1<<(l2-1))]);
					else maxv[l1][l2][i][j]=max(maxv[l1-1][l2][i][j],maxv[l1-1][l2][i+(1<<(l1-1))][j]);
				}
			}
		}
	}
}
int query(int x1,int y1,int x2,int y2){
	int p=pre[x2-x1+1],q=pre[y2-y1+1];
	int ans=-inf;
	ans=max(maxv[p][q][x1][y1],maxv[p][q][x1][y2-(1<<q)+1]);
	ans=max(ans,max(maxv[p][q][x2-(1<<p)+1][y1],maxv[p][q][x2-(1<<p)+1][y2-(1<<q)+1]));
	return ans;
}
int x1,x2,y1,y2;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&val[i][j]);
	init();
	for(int i=1;i<=Q;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",query(x1,y1,x2,y2));
	}
	return 0;
}

