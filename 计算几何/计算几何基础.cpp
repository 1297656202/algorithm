//�������� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
const double dinf=12345678910,eps=1e-10,pi=acos(-1);
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){ }//���캯�� 
};
typedef point vect;
vect operator + (vect A,vect B){return vect(A.x+B.x,A.y+B.y);}
vect operator - (point A,point B){return vect(A.x-B.x,A.y-B.y);}
vect operator * (vect A,double p){return vect(A.x*p,A.y*p);}
vect operator / (vect A,double p){return vect(A.x/p,A.y/p);}
bool operator < (const point& a,const point& b) {return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int sgn(double x){if(fabs(x)<eps)return 0;else return x<0?-1:1;}//��һ��С���ķ��� 
bool operator == (const point& a, const point& b){return !sgn(a.x - b.x) && !sgn(a.y - b.y);}
double polar_angle(vect A){return atan2(A.y,A.x);}//����������б�� 
inline double d_to_r(double D){return pi/180*D;}//�Ƕ�ת����
double cross(vect A,vect B){return A.x*B.y-B.x*A.y;}//�����������Ĳ����Ϊ�����ʾB��A����ʱ�뷽�� 
double side(point a,point b,point c){return cross(b-a,c-a);}//Ϊ�����ʾ��c(ac����)��ab��������ʱ�뷽�� 
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}//��������   
vect rotate(vect A,double rad)//����������ʱ����תrad�������
{return vect(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}

//ֱ�߲���
struct Line{//ֱ�߶���
    vect v;
    point p;
    point get_point_in_line(double t){//����ֱ����һ��P = v + (p - v)*t
        return v+(p-v)*t;
    }
};

//1 ����� ��-1 ���Ҳ� ��0 ��ֱ����   ��A, B:ֱ����һ��,C:���жϹ�ϵ�ĵ�
int relation(point A,point B,point C)//���ֱ�߹�ϵ
{int c=sgn(cross((B-A),(C-A)));
	if(c<0)return 1;else if(c>0)return -1;
	return 0;
}

point get_line_intersection(point P,vect v,point Q,vect w)//��������ֱ�ߵĽ��� 
{vect u=P-Q;double t=cross(w,u)/cross(v,w);
	return P+v*t;
}
//��������ϸ�ļ��Ǹ�ģ��ϼ���html 
