poj2155：给定一个矩阵n*n，初始化为0，现在可以进行两种操作，
一种是查询某个点的值是 0 还是 1，另一种是让这个矩阵的一个子矩阵内的值取反（n<=1000,q<=50000,test<=10）
数据量太大了，只能用二维线段树 
#include<bits/stdc++.h>
#define inf 100000000000000000
#define y1 y3
using namespace std;
long long x1,x2,y1,y2,maxx,minn,sum,ans=0,cnt=0,ge,r,n,m;
struct we{int a,b,s;};//纵坐标
struct w{we f[4005];long long a,b;}a[4005];//横坐标
void buildy(int p,int v,int l,int r)//在p的范围内建立纵向线段树
{int mid=(l+r)/2;
	a[p].f[v].a=l;
	a[p].f[v].b=r;
	a[p].f[v].s=0;
	if(l==r)return ;
	buildy(p,v*2,l,mid);
	buildy(p,v*2+1,mid+1,r);
}
void buildx(int v,int l,int r)//建立横向线段树
{int mid;
	a[v].a=l;
	a[v].b=r;
	buildy(v,1,1,n);//与普通建树唯一的差别就在这里
	if(l==r){return ;}
	mid=(l+r)/2;
	buildx(v*2,l,mid);
	buildx(v*2+1,mid+1,r);
}
void addy(int p,int v)//在横坐标的基础上，插入纵坐标
{
	if(a[p].f[v].a>y2||a[p].f[v].b<y1)return ;
	if(y1<=a[p].f[v].a&&a[p].f[v].b<=y2)
	{a[p].f[v].s++;return ;}
	if(a[p].f[v].a==a[p].f[v].b)return; 
	addy(p,v*2);
	addy(p,v*2+1);
}
void addx(int v)//插入横坐标
{
	if(a[v].a>x2||a[v].b<x1)return ;
	if(x1<=a[v].a&&a[v].b<=x2)//如果该点的范围在x1,x2内，则进行纵坐标的插入
	{addy(v,1);return ;}
	addx(v*2);
	addx(v*2+1);
}
void asky(int p,int v)//在横坐标的基础上，查找纵坐标
{
    if(a[p].f[v].a>y1||y1>a[p].f[v].b)return; 
    if(a[p].f[v].a<=y1&&y1<=a[p].f[v].b)ans+=a[p].f[v].s;//找到那个点，累加ans
    if(a[p].f[v].a==a[p].f[v].b)return ;
    int mid=(a[p].f[v].a+a[p].f[v].b)/2;
    if(y1<=mid)asky(p,v*2);
    else asky(p,v*2+1);
}
void askx(int p)//查找横坐标
{
    if(a[p].a>x1||x1>a[p].b)return; 
    if(a[p].a<=x1&&x1<=a[p].b)asky(p,1);//如果该点的范围包含了x1，则纵向查找
    if(a[p].a==a[p].b)return ;
    int mid=(a[p].a+a[p].b)/2;
    if(x1<=mid)askx(p*2);
    else askx(p*2+1);
}
int main()
{
	long long f1,f2,x,he=0,v,y,len,t,i,j,k,l,r,z,p;
	char ch,s[5];
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		buildx(1,1,n);//建立外层线段树
		for(j=1;j<=m;j++)
		    {
		    	scanf("%c%c",&ch,&ch);
		    	if(ch=='C'){scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);addx(1);}
		    	else 
				{
					scanf("%lld%lld",&x1,&y1);
					ans=0;
					askx(1); 
					printf("%lld\n",ans%2);
		    	}
	     	}
	    printf("\n");
	}
    return 0;
}
