Ԥ��������������ַ����� 
1.��mn�Ƚ�С��ʱ�� 
ll c[mn][mn];
void st()
{ll i,j;
  	for(i=0;i<=n;i++)
    	for(j=0;j<=i;j++)
    	if(j==0)c[i][j]=1;
    	else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;//���ƹ�ʽ
}

2.��mn�Ƚϴ��ʱ��
void st()
{ll i;
	fact[0]=infact[0]=1;
    for(i=1;i<=n;i++)
	{
        fact[i]=i*fact[i-1]%mod;//����׳� 
        infact[i]=infact[i-1]*cal(i,mod-2)%mod;//������Ԫ�Ľ׳ˣ�calΪ������ 
    }
} 
ll C(ll n,ll m)
{
	if(n<0||m<0||n<m)return 0;
    return fact[n]*infact[m]%mod*infact[n-m]%mod;
} 
