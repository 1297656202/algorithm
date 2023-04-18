//∏¥‘”∂»O(mlogm) 
bool cmp(w a,w b){return a.z<b.z;}
ll gf(ll x)
{
	if(prt[x]==x)return x;
	prt[x]=gf(prt[x]);	
	return prt[x];
}
	for(i=1;i<=n;i++)
	prt[i]=i;	
	sort(l+1,l+cnt+1,cmp);
	for(i=1;i<=cnt;i++)
	{
		f1=gf(l[i].x);f2=gf(l[i].y);
		if(f1==f2)continue;
		prt[f1]=f2;
		tot++;
		ans+=l[i].z;
		if(tot==n-1)break;
	}
	if(tot<n-1)printf("-1.000");else 
	cout<<fixed<<setprecision(3)<<ans;
