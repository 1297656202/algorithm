void prim(ll n)
{
	for(i=2;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			p[++cnt]=i;
		}
		for(j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
