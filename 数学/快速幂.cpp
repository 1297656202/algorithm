ll cal(ll x,ll t)
{ll ret=1;
    for(;t;t/=2,x=x*x%mod) 
		if(t%2==1)ret=ret*x%mod;
    return ret;
}
