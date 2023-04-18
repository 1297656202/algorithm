//p1912 [NOI2009] 诗人小G 题解 
#include<cstdio>
#include<cmath>
#include<cstring>
#define RG register
#define R RG int
#define G c=getchar()
#define Calc(i,j) f[j]+qpow(abs(s[i]-s[j]-L))//计算函数值
using namespace std;
typedef long double LD;//开long double
const int N=1e5+9;
int n,L,P,s[N],q[N],k[N],pr[N];
LD f[N];
char str[N][33];
inline int in(){
    RG char G;
    while(c<'-')G;
    R x=c&15;G;
    while(c>'-')x*=10,x+=c&15,G;
    return x;
}
inline LD qpow(RG LD b){//自己写快速幂
    RG LD a=1;
    for(R k=P;k;k>>=1,b*=b)
        if(k&1)a*=b;
    return a;
}
inline int bound(R x,R y){//二分临界值
    R l=x,r=n+1,m;//左端点设为x减小常数
    while(l<r){
        m=(l+r)>>1;
        Calc(m,x)>=Calc(m,y)?r=m:l=m+1;
    }
    return l;
}
int main(){
    R T=in(),i,h,t;
    while(T--){
        n=in();L=in()+1;P=in();//把L处理了一下
        for(i=1;i<=n;++i){
            if(scanf("%s",str[i]));
            s[i]=s[i-1]+strlen(str[i])+1;//记前缀和
        }
        for(q[i=h=t=1]=0;i<=n;++i){
            while(h<t&&k[h]<=i)++h;
            f[i]=Calc(i,q[h]);pr[i]=q[h];//记录转移位置方便输出方案
            while(h<t&&k[t-1]>=bound(q[t],i))--t;
            k[t]=bound(q[t],i);q[++t]=i;
        }
        if(f[n]>1e18)puts("Too hard to arrange");
        else{
            printf("%.0Lf\n",f[n]);
            for(q[t=0]=i=n;i;q[++t]=i=pr[i]);
            for(;t;--t){
                for(i=q[t]+1;i<q[t-1];++i)
                    printf("%s ",str[i]);
                puts(str[i]);//行末不要搞空格
            }
        }
        puts("--------------------");
    }
    return 0;
}
