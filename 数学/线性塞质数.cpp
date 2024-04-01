void prim(ll n)
{ll i,j;
	vis[1]=1;//1不是质数
	for(i=2;i<=n;i++)
	{
		if(vis[i]==0)//vis[i]==0的就是质数
		{
			p[++cnt]=i;
		}
		for(j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
