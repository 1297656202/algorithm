#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll num[mn],v[mn],s[mn],fa[mn],c[mn][2],rt=0,tot=0,
ans,n,m;
void up(ll x)//�ϴ���� 
{
	s[x]=s[c[x][0]]+s[c[x][1]]+num[x];
}
void rot(ll x)//��ת 
{ll y=fa[x],z=fa[y],k=(c[y][1]==x);
	c[z][c[z][1]==y]=x;fa[x]=z;
	c[y][k]=c[x][k^1];fa[c[x][k^1]]=y;
	c[x][k^1]=y;fa[y]=x;
	up(y);up(x);
}
void spl(ll x,ll k)//��x�ڵ���ת��k���Ҷ���
{ll y,z;
	while(fa[x]!=k)
	{
		y=fa[x];z=fa[y];
		if(z!=k)(c[y][0]==x)^(c[z][0]==y)?rot(x):rot(y);
		rot(x);
	}
	if(k==0)rt=x;
}
void ins(ll x)
{ll y=rt,f=0;
	while(y&&v[y]!=x){f=y;y=c[y][x>v[y]];}
    if(y)num[y]++;
    else
    {
        y=++tot;
    	if(f)c[f][x>v[f]]=y;
        c[tot][0]=0;c[tot][1]=0;
        fa[tot]=f;v[tot]=x;
        num[tot]=1;s[tot]=1;
    }
    spl(y,0);
}
//��ѯx���ֵ����������xС�����ĸ���+1�����������ر�xС�����ĸ���������ǰ����-inf���Ͳ���+1 
ll find(ll x)
{ll y=rt;
	if(y==0)return 0;
	while(c[y][x>v[y]]&&x!=v[y]) 
    	y=c[y][x>v[y]]; 
    spl(y,0);
    return x>v[rt]?s[c[rt][0]]+num[rt]:s[c[rt][0]];
}
ll Next(ll x,ll f)//����ǰ׺(f=0)���׺(f=1)
{
	find(x);ll y=rt;
	if((v[y]>x&&f)||(v[y]<x&&!f))return y; 
    y=c[y][f];
    while(c[y][f^1])y=c[y][f^1];
    return y;
}
void del(ll x)
{ll last=Next(x,0),nxt=Next(x,1);
    spl(last,0);spl(nxt,last);
    ll y=c[nxt][0];
    if(num[y]>1)
    {
        num[y]--; 
        spl(y,0);
    }
    else c[nxt][0]=0; 
}
void dell(ll l,ll r)//��l��r֮�䣨�����䣩�����нڵ�ɾ�� 
{ll x,y;
	if(l==-inf)l++;if(r==inf)r--;
	ins(l);ins(r);
	find(l);x=rt;
	find(r);y=rt;
	spl(x,0);
	spl(y,x);
	c[y][0]=0;
	del(l);del(r);
}
ll findk(ll x)//��������Ϊx��ֵ
{ll z=rt;
	if(s[z]<x)return 0;
    while(1)
	{
        ll y=c[z][0];
        if(x>s[y]+num[z])
        {
	        x-=s[y]+num[z];
	        z=c[z][1]; 
        }
        else if(s[y]>=x)z=y;
        else return v[z];
    }
}
void dfs(ll x)//����ƽ�����������,������ 
{
	if(c[x][0])dfs(c[x][0]);
	if(abs(v[x])!=inf)printf("%lld ",v[x]);
	if(c[x][1])dfs(c[x][1]);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	ins(-inf);
	ins(inf);
	cin>>n;
	while(n--)
	{
		scanf("%lld%lld",&k,&x);
		if(k==1)ins(x);
		if(k==2)del(x);
		if(k==3)printf("%lld\n",find(x));
		if(k==4)printf("%lld\n",findk(x+1));//�ǵ�+1��ǰ�滹�и�-inf 
		if(k==5)printf("%lld\n",v[Next(x,0)]);
		if(k==6)printf("%lld\n",v[Next(x,1)]);
	}
	return 0;
}
