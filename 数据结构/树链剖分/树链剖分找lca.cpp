ll lca(ll x,ll y)
{
	while(top[x]!=top[y])
	{
    	if(dep[top[x]]<dep[top[y]])
        	swap(x,y);
        x=fa[top[x]];  
    }
    if(dep[x]<dep[y])return x;
    return y;
}
