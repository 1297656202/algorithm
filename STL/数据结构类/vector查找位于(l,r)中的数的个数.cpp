ll ask(ll l,ll r)
{
	return upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
}
