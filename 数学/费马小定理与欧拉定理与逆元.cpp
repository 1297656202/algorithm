同余相关定义
费马小定理:若p是质数，则对于任意整数a,(a不是p的倍数)有:
a^p=a(mod p)
欧拉定理:若p,a为正整数,且p,a互质,
即gcd(p,a)=1,o(p)为p的欧拉函数则 
a^o(p)= 1(mod p)
费马小定理是欧拉定理的特殊情况，因为当p为素数时，o(p)=p-1
所以,若p,a互质,a对p的逆元为a^(o(p)-1),
当p为质数时,逆元为a^(p-2)
在取模运算中,除以一个数等于乘以一个数的逆元 
