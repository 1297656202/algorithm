给出的点的坐标，计算最短的能够围住这些点的围栏的长度。（1<=n<=10^5，-10^6<=xi,yi<=10^6,保留两位小数） 
其实就是给出坐标，让你求出凸包的周长 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
const double dinf=12345678910,eps=1e-10,pi=acos(-1);
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){ }//构造函数
}a[mn];
typedef point vect;
vect operator + (vect A,vect B){return vect(A.x+B.x,A.y+B.y);}
vect operator - (point A,point B){return vect(A.x-B.x,A.y-B.y);}
vect operator * (vect A,double p){return vect(A.x*p,A.y*p);}
vect operator / (vect A,double p){return vect(A.x/p,A.y/p);}
bool operator < (const point& a,const point& b) {return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int sgn(double x){if(fabs(x)<eps)return 0;else return x<0?-1:1;}//求一个小数的符号 
bool operator == (const point& a, const point& b){return !sgn(a.x - b.x) && !sgn(a.y - b.y);}
double polar_angle(vect A){return atan2(A.y,A.x);}//求向量的倾斜角 
inline double d_to_r(double D){return pi/180*D;}//角度转弧度
double cross(vect A,vect B){return A.x*B.y-B.x*A.y;}//求两个向量的叉积  
double side(point a,point b,point c){return cross(b-a,c-a);}//为正则表示点c(ac向量)在ab向量的逆时针方向 
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}//两点间距离  
vect rotate(vect A,double rad)//计算向量逆时针旋转rad后的向量
{return vect(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
//bool cmp(point A,point B)//一种常见的将凸包极角排序的方法,k为点关于a[1]点的斜率 
//{return A.k<B.k||(A.k==B.k&&dis(A,a[1])<dis(B,a[1]));}
ll n,m,s[mn],top;
double ans=0;
void andrew()
{ll i,tmp;
	sort(a+1,a+n+1);
	s[1]=1;s[2]=2;
	top=2;
	for(i=3;i<=n;i++)
	{
		while(top>1&&side(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
	}
	tmp=top;
	for(i=n-1;i>=1;i--)
	{
		while(top>tmp&&side(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	//if(n<3){printf("-1\n");return ;}//有的时候如果可能凸包为一段首尾相接的线段 
	andrew();//这样s[]里面存的就是凸包节点的编号，并且s[top]=s[1](首尾相接) 
	for(i=1;i<=top-1;i++)
	ans+=dis(a[s[i]],a[s[i+1]]);
	printf("%.2lf",ans);
	return 0;
}
