//点与向量 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
const double dinf=12345678910,eps=1e-10,pi=acos(-1);
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){ }//构造函数 
};
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
double cross(vect A,vect B){return A.x*B.y-B.x*A.y;}//求两个向量的叉积，为正则表示B在A的逆时针方向 
double side(point a,point b,point c){return cross(b-a,c-a);}//为正则表示点c(ac向量)在ab向量的逆时针方向 
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}//两点间距离   
vect rotate(vect A,double rad)//计算向量逆时针旋转rad后的向量
{return vect(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}

//直线部分
struct Line{//直线定义
    vect v;
    point p;
    point get_point_in_line(double t){//返回直线上一点P = v + (p - v)*t
        return v+(p-v)*t;
    }
};

//1 在左侧 ，-1 在右侧 ，0 在直线上   ，A, B:直线上一点,C:待判断关系的点
int relation(point A,point B,point C)//点和直线关系
{int c=sgn(cross((B-A),(C-A)));
	if(c<0)return 1;else if(c>0)return -1;
	return 0;
}

point get_line_intersection(point P,vect v,point Q,vect w)//计算两个直线的交点 
{vect u=P-Q;double t=cross(w,u)/cross(v,w);
	return P+v*t;
}
//其他更详细的见那个模板合集的html 
