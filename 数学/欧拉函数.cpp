ll phi(ll n)
{ll ret=n,i;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0)
	{
		ret=ret/i*(i-1);
		while(n%i==0)n=n/i;
	}
	if(n>1)ret=ret/n*(n-1); 
	return ret;
} 
