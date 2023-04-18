#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,p,k=0,d[500000]={0},bt[500000]={0},inq[500000]={0},cnt=0,keynum[20]={0},s,num[20][20]={0},map[400][400]={0};
struct KEY{int x,y;}key[20][20];
struct Bian{int num,next,v;}bian[500000];
void Read()
{scanf("%d%d%d",&n,&m,&p);
 for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
       num[i][j]=++k;
 for(int i=1;i<=m*n;i++)map[i][0]=map[0][i]=-1;
 scanf("%d",&k);
 int x1,x2,y1,y2,g;
 for(int i=1;i<=k;i++)
    {scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
     if(g==0)g=-1;
     map[num[x1][y1]][num[x2][y2]]=map[num[x2][y2]][num[x1][y1]]=g;
    }
 scanf("%d",&s);
 for(int i=1;i<=s;i++)
    {int x,y,q;
     scanf("%d%d%d",&x,&y,&q);
     key[q][++keynum[q]].x=x;key[q][keynum[q]].y=y;
    }
}
void lian(int a,int b,int v)
{bian[++cnt].next=bt[a];
 bian[cnt].num=b;
 bian[cnt].v=v;
 bt[a]=cnt;
}
void JianBian()
{int M=m*n,L=1<<p;
 for(int k=0;k<L;k++)
    {int Key[20]={0};
     for(int i=1;i<=p;i++)
        {if(k&(1<<(i-1)))Key[i]=1;
        }
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           {int x=num[i][j],y=num[i][j+1];
            if(y!=0&&map[x][y]!=-1)
              if(map[x][y]==0||Key[map[x][y]])
                {lian(k*M+x,k*M+y,1);
                 lian(k*M+y,k*M+x,1);
                }
            y=num[i+1][j];
            if(y!=0&&map[x][y]!=-1)
              if(map[x][y]==0||Key[map[x][y]])
                {lian(k*M+x,k*M+y,1);
                 lian(k*M+y,k*M+x,1);
                }
           }
     for(int i=1;i<=p;i++)
        if(!Key[i])
          {int t=k|(1<<i-1);
           for(int j=1;j<=keynum[i];j++)
              {int x=num[key[i][j].x][key[i][j].y];
               lian(k*M+x,t*M+x,0);
              }
          }
    }
}
void SPFA()
{queue<int>dui;
 dui.push(1);
 d[1]=0;
 while(!dui.empty())
      {int num=dui.front();
       dui.pop();
       inq[num]=0;
       for(int i=bt[num];i;i=bian[i].next)
          {int now=bian[i].num;
           if(d[now]>d[num]+bian[i].v)
             {d[now]=d[num]+bian[i].v;
              if(!inq[now])
                {inq[now]=1;
                 dui.push(now);
                }
             }
          }
      }
}
int main()
{Read();
 for(int i=1;i<=(1<<p)*n*m;i++)d[i]=0x7fffffff/2;
 JianBian();
 SPFA();
 int ans=0x7fffffff/2;
 for(int i=0;i<(1<<p);i++)ans=min(ans,d[i*m*n+num[n][m]]);
 if(ans==0x7fffffff/2)cout<<"-1\n";
 else cout<<ans;
}
