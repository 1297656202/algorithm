//����ͼȫ����С�Ҳ����һ������ͼ�������С�Ĵ��ۻ���Ϊ������ͨ�� 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxm=505;
const int inf=1e9;
int g[maxm][maxm];
int v[maxm];//v[i]��ʾi�ϲ����Ķ���
int dis[maxm];//dis��ʾ�õ���A���������е�֮��ıߵĳ���֮��
bool mark[maxm];//����Ѿ��ϲ������������
int n,m;
int sw(){
    int res=inf;
    for(int i=0;i<n;i++){//��ʼ�Ѻϲ��Ķ������ó��Լ�
        v[i]=i;
    }
    while(n>1){
        int pre=0;//pre��ʾ֮ǰ����A���ϵĵ㣬��0��Ϊ��һ������A���ϵĵ�
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
