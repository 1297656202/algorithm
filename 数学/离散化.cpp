for(i=1;i<=n;i++)
   b[i]=a[i];
sort(b+1,b+n+1);
ll tot=unique(b+1,b+n+1)-b-1;
for(i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
