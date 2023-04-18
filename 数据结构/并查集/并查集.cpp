ll gf(ll x)
{
	if(prt[x]==x)return x;
	prt[x]=gf(prt[x]);
	return prt[x];
}
for(i=1;i<=n;i++)
	prt[i]=i;
