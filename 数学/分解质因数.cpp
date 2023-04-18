ll cnt=0,p[mn],c[mn]; 
void cal(ll n)
{ll i;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0)
	{
		p[++cnt]=i;
		while(n%i==0){c[cnt]++;n=n/i;}
	}
	if(n!=1){p[++cnt]=n;c[cnt]=1;}
}
