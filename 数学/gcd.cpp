ll gcd(ll x,ll y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
