��n*n(1<=n<=10)�������Ϸ�k(0<=k<=n*n)������(�ɹ������ڵ�8 ������)����ʹ�����޷����๥���ķ���������

long long f[11][155][155]={0},Ans;
int c[155],s[155],N,K,num;
void Prepare()
{   int i,j,k;
    num=0;Ans=0;
    memset(f,0,sizeof(f));
    for(i=0;i<(1<<N);i++)   //ö��ÿ�е�״̬
    {   if(i&(i<<1))continue; //��鵱ǰ״̬��ͻ��
         k=0; //ͳ������״̬���ù����ĸ���
         for(j=0;j<N;j++)if(i&(1<<j))k++;//ͳ��1�ĸ���
         s[++num]=i;  //������õ�״̬
         c[num]=k; //��¼��״̬���õĹ�����
    }
}
void Dp()
{   int i,j,kk,t,s1,s2;
    f[0][1][0]=1;
    for(i=1;i<=N;i++)//����Ϊ�׶� 
        for(j=1;j<=num;j++)//ö�ٵ�i�е�״̬s[j]
             for(kk=0;kk<=K;kk++)//ö��ǰi�з��õĹ�����
                    if(kk>=c[j]) 
                         for(t=1;t<=num;t++)//ö�ٵ�i-1�е�״̬s[t]
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
