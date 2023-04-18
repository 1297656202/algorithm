//ÀÏ´úÂë 
#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
long long h[100005]={0},top[100005],prt[100005],
d[100005],vv[100005],e[100005],size[100005],p[100005],fp[100005],son[100005]={0},
ans=0,cnt=0,ge,r,n,m,pos=0,maxx;
struct w{int to,next;}a[200005];
struct we{int x,y,z;}b[200005];
struct wee{int l,r,maxx,sum,bj;}c[400005];
void add(int x,int y)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs1(int x,int pre,int deep)
{int i,y;
	d[x]=deep;
	prt[x]=pre;
	size[x]=1;
	for(i=h[x];i;i=a[i].next)
	   {
	   	y=a[i].to;
	   	if(y!=pre)
	   	  {
	   	  	dfs1(y,x,deep+1);	
	   	  	size[x]+=size[y];
	   	  	if(son[x]==0||size[y]>size[son[x]])son[x]=y;
	   	  }
	   }
}
void dfs2(int x,int sp)
{int i,y;
	top[x]=sp;
	p[x]=++pos;
	fp[p[x]]=x;
	if(son[x]!=0)dfs2(son[x],sp);
	for(i=h[x];i;i=a[i].next)
	   {
	   	y=a[i].to;
	   	if(y!=son[x]&&y!=prt[x])
	   	   dfs2(y,y);
	   }
}
void up(int x)
{
	c[x].sum=c[x*2].sum+c[x*2+1].sum;
}
void down(int x)
{
	c[x*2].bj+=c[x].bj;
	c[x*2+1].bj+=c[x].bj;
	c[x*2].sum+=c[x].bj*(c[x*2].r-c[x*2].l+1);
	c[x*2+1].sum+=c[x].bj*(c[x*2+1].r-c[x*2+1].l+1);
	c[x].bj=0;	
}
void bui(int x,int l,int r)
{
	c[x].l=l;
	c[x].r=r;
	c[x].bj=c[x].sum=0;
	if(l==r){return ;}
	int mid=(l+r)/2;
	bui(2*x,l,mid);
	bui(2*x+1,mid+1,r);
}
void ins(int x,int l,int r)
{
	if(r<c[x].l||l>c[x].r)return ;
	if(l<=c[x].l&&r>=c[x].r)
	{
		c[x].bj++;
		c[x].sum+=c[x].r-c[x].l+1;
		return ;
	}
	down(x);
	ins(2*x,l,r);
	ins(2*x+1,l,r);
	up(x);
}
/*int ask(int x,int l,int r)
{
	if(l>c[x].r||r<c[x].l)return -inf;
	if(l<=c[x].l&&r>=c[x].r)return c[x].maxx;
	return max(ask(2*x,l,r),ask(2*x+1,l,r));
}
int Ask(int x,int y)
{int f1=top[x],f2=top[y];
	int tmp=-inf;
	while(f1!=f2)
	  {
	  	if(d[f1]<d[f2]){swap(f1,f2);swap(x,y);}
	  	tmp=max(tmp,ask(1,p[f1],p[x]));
	  	x=prt[f1];
	  	f1=top[x];
	  }
	if(d[x]>d[y])swap(x,y);
	return max(tmp,ask(1,p[x],p[y]));
}*/
long long asksum(int x,int l,int r)
{
	if(l>c[x].r||r<c[x].l)return 0;
	if(l<=c[x].l&&r>=c[x].r)return c[x].sum;
	down(x);
	return asksum(x*2,l,r)+asksum(x*2+1,l,r);
}
long long find(int x,int y)
{int f1=top[x],f2=top[y],ans=0;
	while(f1!=f2)
	   {
	   	if(d[f1]<d[f2]){swap(f1,f2);swap(x,y);}
	   	ans+=asksum(1,p[f1],p[x]);
	   	x=prt[f1];
	   	f1=top[x];
	   }
	if(x==y)return ans;
	if(d[x]>d[y])swap(x,y);
	return ans+asksum(1,p[son[x]],p[y]);
}
void pla(int x,int y)
{
	int f1=top[x],f2=top[y];
	while(f1!=f2)
	{
		if(d[f1]<d[f2]){swap(f1,f2);swap(x,y);}
		ins(1,p[f1],p[x]);
		x=prt[f1];
		f1=top[x];
	}
	if(x==y)return ;
	if(d[x]>d[y])swap(x,y);
	ins(1,p[son[x]],p[y]);
}
int main()
{
	long long f1,f2,x,he=0,v,y,len,t,i,j,k,l,r,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n-1;i++)
	   { 
	   	scanf("%lld%lld",&b[i].x,&b[i].y);
	   	add(b[i].x,b[i].y);
	   	add(b[i].y,b[i].x);
	   }
	dfs1(1,0,0);
	dfs2(1,1);
	bui(1,1,pos);
	while(m--)
	{
		//scanf("%c%lld%lld",&ch,&x,&y);
		cin>>ch>>x>>y;
		if(ch=='P')
		  {
		    pla(x,y);
		  } 
		else 
		{
			printf("%lld\n",find(x,y));
		}
	}
    return 0;
}
