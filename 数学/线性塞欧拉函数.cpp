void cal(ll n)
{ll i;
	phi[1]=1;
	for(i=2;i<=n;i++)
	{
		if(vis[i]==0){p[++cnt]=i;phi[i]=i-1;}
		for(j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
