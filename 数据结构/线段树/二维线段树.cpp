poj2155������һ������n*n����ʼ��Ϊ0�����ڿ��Խ������ֲ�����
һ���ǲ�ѯĳ�����ֵ�� 0 ���� 1����һ��������������һ���Ӿ����ڵ�ֵȡ����n<=1000,q<=50000,test<=10��
������̫���ˣ�ֻ���ö�ά�߶��� 
#include<bits/stdc++.h>
#define inf 100000000000000000
#define y1 y3
using namespace std;
long long x1,x2,y1,y2,maxx,minn,sum,ans=0,cnt=0,ge,r,n,m;
struct we{int a,b,s;};//������
struct w{we f[4005];long long a,b;}a[4005];//������
void buildy(int p,int v,int l,int r)//��p�ķ�Χ�ڽ��������߶���
{int mid=(l+r)/2;
	a[p].f[v].a=l;
	a[p].f[v].b=r;
	a[p].f[v].s=0;
	if(l==r)return ;
	buildy(p,v*2,l,mid);
	buildy(p,v*2+1,mid+1,r);
}
void buildx(int v,int l,int r)//���������߶���
{int mid;
	a[v].a=l;
	a[v].b=r;
	buildy(v,1,1,n);//����ͨ����Ψһ�Ĳ���������
	if(l==r){return ;}
	mid=(l+r)/2;
	buildx(v*2,l,mid);
	buildx(v*2+1,mid+1,r);
}
void addy(int p,int v)//�ں�����Ļ����ϣ�����������
{
	if(a[p].f[v].a>y2||a[p].f[v].b<y1)return ;
	if(y1<=a[p].f[v].a&&a[p].f[v].b<=y2)
	{a[p].f[v].s++;return ;}
	if(a[p].f[v].a==a[p].f[v].b)return; 
	addy(p,v*2);
	addy(p,v*2+1);
}
void addx(int v)//���������
{
	if(a[v].a>x2||a[v].b<x1)return ;
	if(x1<=a[v].a&&a[v].b<=x2)//����õ�ķ�Χ��x1,x2�ڣ������������Ĳ���
	{addy(v,1);return ;}
	addx(v*2);
	addx(v*2+1);
}
void asky(int p,int v)//�ں�����Ļ����ϣ�����������
{
    if(a[p].f[v].a>y1||y1>a[p].f[v].b)return; 
    if(a[p].f[v].a<=y1&&y1<=a[p].f[v].b)ans+=a[p].f[v].s;//�ҵ��Ǹ��㣬�ۼ�ans
    if(a[p].f[v].a==a[p].f[v].b)return ;
    int mid=(a[p].f[v].a+a[p].f[v].b)/2;
    if(y1<=mid)asky(p,v*2);
    else asky(p,v*2+1);
}
void askx(int p)//���Һ�����
{
    if(a[p].a>x1||x1>a[p].b)return; 
    if(a[p].a<=x1&&x1<=a[p].b)asky(p,1);//����õ�ķ�Χ������x1�����������
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
		buildx(1,1,n);//��������߶���
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
