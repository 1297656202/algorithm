在n*n(1<=n<=10)的棋盘上放k(0<=k<=n*n)个国王(可攻击相邻的8 个格子)，求使它们无法互相攻击的方案总数。

long long f[11][155][155]={0},Ans;
int c[155],s[155],N,K,num;
void Prepare()
{   int i,j,k;
    num=0;Ans=0;
    memset(f,0,sizeof(f));
    for(i=0;i<(1<<N);i++)   //枚举每行的状态
    {   if(i&(i<<1))continue; //检查当前状态冲突不
         k=0; //统计这种状态放置国王的个数
         for(j=0;j<N;j++)if(i&(1<<j))k++;//统计1的个数
         s[++num]=i;  //保存可用的状态
         c[num]=k; //记录该状态放置的国王数
    }
}
void Dp()
{   int i,j,kk,t,s1,s2;
    f[0][1][0]=1;
    for(i=1;i<=N;i++)//以行为阶段 
        for(j=1;j<=num;j++)//枚举第i行的状态s[j]
             for(kk=0;kk<=K;kk++)//枚举前i行放置的国王数
                    if(kk>=c[j]) 
                         for(t=1;t<=num;t++)//枚举第i-1行的状态s[t]
                                if(!(s[t]&s[j])&&!(s[t]&(s[j]<<1))&&!(s[t]&(s[j]>>1)))
                                           f[i][j][kk]+=f[i-1][t][kk-c[j]];
     for(i=1;i<=num;i++)Ans+=f[N][i][K];
     cout<<Ans<<endl;
}
int main()
{   while(cin>>N>>K)
    {    Prepare();
        Dp();
     }
}
