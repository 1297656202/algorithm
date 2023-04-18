给定平面上 n个点，求凸包直径。
 
先求出凸包，显然对于每一条边，在凸包上对应有一个距离其最远的点，当边逆时针移动时，点也逆时针移动
所以可以用双指针O（n）求出每条对应的点，然后取边的两个点与对应点距离的最大值，最后求出来的总的最大值为直径

求最远的点方法：对于任意一条边而言边的长度是固定的，距离越远，那么，边和点连成的面积也就越大。 
而这个连成的三角形的面积可以用叉积简单求出 

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
ll n,m,s[mn],top,ans=0;
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
ll area(point a,point b,point c){return cross(b-a,c-a);}//用叉积计算三角形面积的2倍 
ll Dis(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}//两点间距离的平方 
void getlen()//最后计算的是凸包直径的平方  
{ll i,j=3;
	if(top==3){ans=Dis(a[s[1]],a[s[2]]);return ;} 
	for(i=1;i<top;i++)
	{
		while(area(a[s[i]],a[s[i+1]],a[s[j]])<area(a[s[i]],a[s[i+1]],a[s[j+1]]))j=j%(top-1)+1;
		ans=max(ans,max(Dis(a[s[i]],a[s[j]]),Dis(a[s[i+1]],a[s[j]])));
	}
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	andrew();
	getlen();
	cout<<ans<<endl;
	return 0;
}
