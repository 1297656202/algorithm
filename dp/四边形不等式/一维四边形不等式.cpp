//p1912 [NOI2009] ʫ��СG ��� 
#include<cstdio>
#include<cmath>
#include<cstring>
#define RG register
#define R RG int
#define G c=getchar()
#define Calc(i,j) f[j]+qpow(abs(s[i]-s[j]-L))//���㺯��ֵ
using namespace std;
typedef long double LD;//��long double
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
inline LD qpow(RG LD b){//�Լ�д������
    RG LD a=1;
    for(R k=P;k;k>>=1,b*=b)
        if(k&1)a*=b;
    return a;
}
inline int bound(R x,R y){//�����ٽ�ֵ
    R l=x,r=n+1,m;//��˵���Ϊx��С����
    while(l<r){
        m=(l+r)>>1;
        Calc(m,x)>=Calc(m,y)?r=m:l=m+1;
    }
    return l;
}
int main(){
    R T=in(),i,h,t;
    while(T--){
        n=in();L=in()+1;P=in();//��L������һ��
        for(i=1;i<=n;++i){
            if(scanf("%s",str[i]));
            s[i]=s[i-1]+strlen(str[i])+1;//��ǰ׺��
        }
        for(q[i=h=t=1]=0;i<=n;++i){
            while(h<t&&k[h]<=i)++h;
            f[i]=Calc(i,q[h]);pr[i]=q[h];//��¼ת��λ�÷����������
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
                puts(str[i]);//��ĩ��Ҫ��ո�
            }
        }
        puts("--------------------");
    }
    return 0;
}
