inv[1]=1;
for(i=2;i<=n;i++)
	inv[i]=mod-1ll*(mod/i)*inv[i-1]%mod;
