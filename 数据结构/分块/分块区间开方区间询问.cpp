#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 5000005//℅?o??a米?(n+m)米?芍?㊣? 
using namespace std;
const double pi=acos(-1);
ll n,m,res,ans[mn];
ll limit=1;//21??米?2米???那y?YN
ll maxl;//?t????米???那y
ll r[mn];//?t????﹞-℅a
struct com
{
    double x,y;
    com(double x=0,double y=0):x(x),y(y){}
}a[mn],b[mn];
com operator * (com j,com q){return com(j.x*q.x-j.y*q.y,j.x*q.y+j.y*q.x);}//?∩那y3?﹞“㏒o?㏒3∟?角3?㏒?﹞迄?豕?角?車
com operator - (com j,com q){return com(j.x-q.x,j.y-q.y);}
com operator + (com j,com q){return com(j.x+q.x,j.y+q.y);}
void fft(com *a,ll type)//fft～?℅車
{ll i,mid,k,len,pos;
    for(i=0;i<limit;i++)
    if(i<r[i])swap(a[i],a[r[i]]);
    for(mid=1;mid<limit;mid<<=1)
	{
        com wn(cos(pi/mid),type*sin(pi/mid));//那1車?3?那??‘o‘那y米?～足﹞“ 
        for(len=mid<<1,pos=0;pos<limit;pos+=len)
		{
            com w(1,0);//那1車?3?那??‘o‘那y米?～足﹞“ 
            for(k=0;k<mid;k++,w=w*wn)
			{
                com x=a[pos+k];
                com y=w*a[pos+mid+k];
                a[pos+k]=x+y;
                a[pos+mid+k]=x-y;
            }
        }
    }
    if(type==1)return ;
    for(i=0;i<=limit;i++){a[i].x/=limit;a[i].y/=limit;}
}
void st()
{ll i; 
	while(limit<=n+m){limit<<=1;maxl++;}
    for(i=0;i<limit;i++)
        r[i]=(r[i>>1]>>1)|((i&1)<<(maxl-1));
}
int main()
{
	ll x,y,z,i,j,k;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<=n;i++)
        scanf("%lf",&a[i].x);
    for(i=0;i<=m;i++)
        scanf("%lf",&a[i].y);//～?b(x)﹞?米?a(x)米?D谷2?谷?
    st();
    fft(a,1);
    for(i=0;i<=limit;i++)
        a[i]=a[i]*a[i];//?車3?a(x)^2
    fft(a,-1);
    for(i=0;i<=n+m;i++)
        printf("%lld ",(ll)(a[i].y/2+0.5)); 
        //D谷2?豕?3?角∩3y2㏒?℅⊿辰a辰a+0.5㏒?﹞??辰???豕?芍車D?那足a,?a角?米?xo赤y??那?double
}