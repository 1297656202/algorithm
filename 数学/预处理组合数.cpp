预处理组合数的两种方法： 
1.当mn比较小的时候 
ll c[mn][mn];
void st()
{ll i,j;
  	for(i=0;i<=n;i++)
    	for(j=0;j<=i;j++)
    	if(j==0)c[i][j]=1;
    	else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;//递推公式
}

2.当mn比较大的时候
void st()
{ll i;
	fact[0]=infact[0]=1;
    for(i=1;i<=n;i++)
	{
        fact[i]=i*fact[i-1]%mod;//代表阶乘 
        infact[i]=infact[i-1]*cal(i,mod-2)%mod;//代表逆元的阶乘，cal为快速幂 
    }
} 
ll C(ll n,ll m)
{
	if(n<0||m<0||n<m)return 0;
    return fact[n]*infact[m]%mod*infact[n-m]%mod;
} 
