exgcd可以求解二元一次方程gcd(a,b)=ax+by的特殊解，
因为gcd(a,b)*t可以为很多数，故可以推广到其他二元一次方程的特殊解，
若有方程ax+by=c,当c%gcd(a,b)==0时,(此为先决条件), 
设d=gcd(a,b), (可以在exgcd中当b==0时用d=a来记录一下gcd(a,b)),
先求出ax+by=gcd(a,b)的一组特解x0,y0, 然后令x0,y0同时乘上c/d，
就得到了ax+by=c的一组特解(c/d)x0,(c/d)y0,
通解x=c/d*x0+k*b/d,y=c/d*y0-k*a/d,(k为整数) 

还有一种题，求a*x=b(mod m),等价求a*x-b=m*(-y),
即为a*x+m*y=b,只需解不定方程a*x+m*y=b即可
线性同余方程有解当且仅当b%gcd(a,m)==0有解
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1;y=0;return ;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

