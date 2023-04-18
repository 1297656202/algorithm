#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int s[1000005],c[3000005][2],ln[3000005],rn[3000005],v[3000005],prt[3000005]
,ans=0,cnt=0,ge,r,n,m,maxx,tmp,tot=0,root[3000005],mid,w[100005],num[30000005];
void rot(int x)
{ int y=prt[x],z=prt[y];
  int l=(c[y][0]!=x),r=l^1;
	if(z)
	{
	if(c[z][0]==y) c[z][0]=x;
	else c[z][1]=x;
	}
	prt[x]=z;
	prt[y]=x;prt[c[x][r]]=y;
	if(l)
	{
	rn[y]=ln[x];
	ln[x]=ln[y]+rn[y]+num[y];
	}
	else
	{
	ln[y]=rn[x];
	rn[x]=rn[y]+ln[y]+num[y];
	}
	c[y][l]=c[x][r];c[x][r]=y;
}
void splay(int k,int x)
{
	while(prt[x])
	{ int y=prt[x],z=prt[y];
	if(z)
	{
	if(c[y][0]==x^c[z][0]==y) rot(x);
	else rot(y);
	}
	rot(x);
	}
	root[k]=x;
}
void add(int k,int x)
{ int p,f;
	p=root[k];
	while(p)
	{ f=p;
	if(x==v[p]){num[p]++;splay(k,p);return;}
	if(x<v[p]){ln[p]++;p=c[p][0];}
	else if(x>v[p]){rn[p]++;p=c[p][1];}
	}
	tot++;
	v[tot]=x;prt[tot]=0;
	c[tot][1]=c[tot][0]=0;
	ln[tot]=rn[tot]=0;num[tot]=1;
	if(root[k]==0){root[k]=tot;return;}
	prt[tot]=f;
	if(x<v[f])c[f][0]=tot;
	else c[f][1]=tot;
	splay(k,tot);
}
void found(int k,int d)
{ int p=root[k];
	while(p)
	{ if(d==v[p]){splay(k,p);return;}
	if(d<v[p]) p=c[p][0];
	else p=c[p][1];
	}
}
void del(int v,int d)
{ found(v,d);
	int p=root[v];
	num[p]--;
	if(num[p]) return;
	int ls=c[p][0],rs=c[p][1];
	if(!ls&&!rs){root[v]=0;return;}
	if(!rs){root[v]=ls;prt[ls]=0;return;}
	if(!ls){root[v]=rs;prt[rs]=0;return;}
	p=ls;
	prt[ls]=0;
	while(c[p][1]) p=c[p][1];
	splay(v,p);
	c[p][1]=rs;prt[rs]=p;
	rn[p]=rn[rs]+ln[rs]+num[rs];
}
void change(int k,int L,int r,int x,int d,int a)
{ del(k,a);
	add(k,d);
	int mid=(L+r)/2;
	if(L==r)return;
	if(x<=mid) change(k*2,L,mid,x,d,a);
	else change(k*2+1,mid+1,r,x,d,a);
}
void build(int v,int L,int r,int x,int sum)
{   add(v,sum);
	if(L==r) return;
	int mid=(L+r)/2;
	if(x<=mid) build(v*2,L,mid,x,sum);
	else build(v*2+1,mid+1,r,x,sum);
}
void FIND(int p,int x)
{ if(!p) return;
	if(v[p]<=x)
	{
	tmp+=num[p]+ln[p];FIND(c[p][1],x);
	}
	else FIND(c[p][0],x);
}
void cal(int v,int L,int r,int x,int y,int sum)
{ if(L==x&&r==y){FIND(root[v],sum);return;}
	int mid=(L+r)/2;
	if(mid>=y) cal(v*2,L,mid,x,y,sum);
	else if(mid<x) cal(v*2+1,mid+1,r,x,y,sum);
	else{
	cal(v*2,L,mid,x,mid,sum);
	cal(v*2+1,mid+1,r,mid+1,y,sum);
	}
}
int main()
{ 
    int f1,f2,x,he=0,v,y,len,t,i,j,k,l,r,z;
	char ch;
	memset(root,0,sizeof(root));
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)build(1,1,n,i,s[i]);
	while(m--)
	{ while(ch=getchar())
	if(ch=='Q'||ch=='C') break;
	if(ch=='C')
	{ scanf("%d%d",&x,&y);
	change(1,1,n,x,y,s[x]);
	s[x]=y;
	}
	else
	{ 	scanf("%d%d%d",&x,&y,&z);
	int L=0,r=1000000000,ans;
	while(L<=r)
	{ 	mid=(L+r)/2;
		tmp=0;
		cal(1,1,n,x,y,mid);
		if(tmp>=z){ans=mid;r=mid-1;}
		else L=mid+1;
		}
		printf("%d\n",ans);
		}
	}
	return 0;
}
