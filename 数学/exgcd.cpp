exgcd��������Ԫһ�η���gcd(a,b)=ax+by������⣬
��Ϊgcd(a,b)*t����Ϊ�ܶ������ʿ����ƹ㵽������Ԫһ�η��̵�����⣬
���з���ax+by=c,��c%gcd(a,b)==0ʱ,(��Ϊ�Ⱦ�����), 
��d=gcd(a,b), (������exgcd�е�b==0ʱ��d=a����¼һ��gcd(a,b)),
�����ax+by=gcd(a,b)��һ���ؽ�x0,y0, Ȼ����x0,y0ͬʱ����c/d��
�͵õ���ax+by=c��һ���ؽ�(c/d)x0,(c/d)y0,
ͨ��x=c/d*x0+k*b/d,y=c/d*y0-k*a/d,(kΪ����) 

����һ���⣬��a*x=b(mod m),�ȼ���a*x-b=m*(-y),
��Ϊa*x+m*y=b,ֻ��ⲻ������a*x+m*y=b����
����ͬ�෽���н⵱�ҽ���b%gcd(a,m)==0�н�
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1;y=0;return ;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

