����ƽ���� n���㣬��͹��ֱ����
 
�����͹������Ȼ����ÿһ���ߣ���͹���϶�Ӧ��һ����������Զ�ĵ㣬������ʱ���ƶ�ʱ����Ҳ��ʱ���ƶ�
���Կ�����˫ָ��O��n�����ÿ����Ӧ�ĵ㣬Ȼ��ȡ�ߵ����������Ӧ���������ֵ�������������ܵ����ֵΪֱ��

����Զ�ĵ㷽������������һ���߶��Աߵĳ����ǹ̶��ģ�����ԽԶ����ô���ߺ͵����ɵ����Ҳ��Խ�� 
��������ɵ������ε���������ò������� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
const double dinf=12345678910,eps=1e-10,pi=acos(-1);
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){ }//���캯��
}a[mn];
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
double cross(vect A,vect B){return A.x*B.y-B.x*A.y;}//�����������Ĳ��  
double side(point a,point b,point c){return cross(b-a,c-a);}//Ϊ�����ʾ��c(ac����)��ab��������ʱ�뷽�� 
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}//��������  
vect rotate(vect A,double rad)//����������ʱ����תrad�������
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
ll area(point a,point b,point c){return cross(b-a,c-a);}//�ò�����������������2�� 
ll Dis(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}//���������ƽ�� 
void getlen()//���������͹��ֱ����ƽ��  
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
