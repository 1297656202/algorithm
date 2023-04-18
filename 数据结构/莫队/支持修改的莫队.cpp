#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
#define sqr(i) i*i
using namespace std;
ll p[maxn],mark[maxn]={0},b[maxn],
c[maxn],pos[maxn],cnt[maxn],A[maxn],blo,ans=0,maxx,minn,
ccnt=0,qcnt=0,ge,n,m,l,r;
struct w{ll x,y,id,last;}a[maxn];
struct we{ll id,l,r,lb,rb,tim;}q[maxn];
bool cmp(const we&a,const we&b)
{
	if(a.lb==b.lb)
	{
		if(a.rb==b.rb)return a.tim<b.tim;
		return a.rb<b.rb;
	}
	return a.lb<b.lb;
}
void chan(ll x,ll col)
{
	if(l<=x&&x<=r)
	{
		cnt[c[x]]--;
		if(cnt[c[x]]==0)ans--;
		c[x]=col;
		if(cnt[c[x]]==0)ans++;
		cnt[c[x]]++;
	}
	else c[x]=col;
}
void up(ll x,ll add)
{ll tmp=cnt[c[x]];
	cnt[c[x]]+=add;
	if(tmp==0&&cnt[c[x]]==1)ans++;
	else if(tmp==1&&cnt[c[x]]==0)ans--;
}
ll getb(ll x)
{
	return (x-1)/blo+1;
}
int main()
{
	ll h,k,f1,f2,x,he=0,v,y,len,t,i,j,z;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	   {
	   scanf("%d",&b[i]);
	   c[i]=b[i];
	   }
	/*sort(tmp,tmp+n+1);
	for(i=1;i<=n;i++)
	    c[i]=lower_bound(tmp+1,tmp+n+1,c[i])-tmp;*/
	blo=(long long)sqrt(n);
	for(i=1;i<=n;i++)
	   pos[i]=(i-1)/blo+1;
	for(i=1;i<=m;i++)
	   {
	   	scanf(" %c",&ch);
	   	if(ch=='R')
	   	{
	   		ccnt++;
	   		scanf("%lld%lld",&a[ccnt].x,&a[ccnt].y);
	   		a[ccnt].last=b[a[ccnt].x];
	   		b[a[ccnt].x]=a[ccnt].y;
	   	}
	   	else 
	   	{
	   		qcnt++;
	   		scanf("%lld%lld",&q[qcnt].l,&q[qcnt].r);
	   		q[qcnt].id=qcnt;
	   		q[qcnt].lb=getb(q[qcnt].l);
	   		q[qcnt].rb=getb(q[qcnt].r);
	   		q[qcnt].tim=ccnt;
	   	}
	   }
	sort(q+1,q+qcnt+1,cmp);
	for(i=1,h=0,l=1,r=0;i<=qcnt;i++)
	{
		while(h>q[i].tim)
		{
			chan(a[h].x,a[h].last);
			h--;
		}
		while(h<q[i].tim)
		{
			h++;
			chan(a[h].x,a[h].y);
		}
		while(r<q[i].r)r++,up(r,1);
		while(l>q[i].l)l--,up(l,1);
		while(r>q[i].r)up(r,-1),r--;
		while(l<q[i].l)up(l,-1),l++;
		A[q[i].id]=ans;
	}
	for(i=1;i<=qcnt;i++)
	   printf("%d\n",A[i]);
    return 0;
}
