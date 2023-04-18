ll mul(ll x,ll y)
{ll ret=0;
 	for(;y;y/=2,x=x*2%mod)
 		if(y%2==1)ret=(ret+x)%mod;
 	return ret;
}
