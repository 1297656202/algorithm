#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define maxn 1000005
using namespace std;
ll ans[maxn*3]={0},maxx,minn,cnt=0,tot=0,ge,n,m;
struct w{ll ty,i,v;
bool operator<(const w &a)const{
return i==a.i?ty<a.ty:i<a.i;
}}a[maxn*3],tmp[maxn*3];
void cdq(ll l,ll r)
{ll i;
	if(l==r)return ;
	ll mid=(l+r)/2;
	cdq(l,mid);
	cdq(mid+1,r);
	ll sum=0;
	ll p=l,q=mid+1,o=l;
	while(p<=mid&&q<=r)
	{
		if(a[p]<a[q])
		{
			if(a[p].ty==1)sum+=a[p].v;
			tmp[o++]=a[p++];
		}
		else 
		{
			if(a[q].ty==2)ans[a[q].v]-=sum;
			else if(a[q].ty==3)ans[a[q].v]+=sum;
			tmp[o++]=a[q++];
		}
	}
	while(p<=mid)tmp[o++]=a[p++];
	while(q<=r)
	{
		if(a[q].ty==2)ans[a[q].v]-=sum;
		else if(a[q].ty==3)ans[a[q].v]+=sum;
		tmp[o++]=a[q++];
	}
	for(i=l;i<=r;i++)
	   a[i]=tmp[i];
}
int main()
{
	ll h,f1,f2,x,y,k,len,t,i,j,z;
	char ch[10];
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%s%lld%lld",&ch,&x,&y);
		if(ch[1]=='d'){a[++cnt].ty=1;a[cnt].i=x;a[cnt].v=y;}
		if(ch[0]=='S'){a[++cnt].ty=1;a[cnt].i=x;a[cnt].v=-y;}
		if(ch[1]=='s')
		{
			a[++cnt].ty=2;a[cnt].i=x-1;a[cnt].v=++tot;
			a[++cnt].ty=3;a[cnt].i=y;a[cnt].v=tot;
		}
	}
	cdq(1,cnt);
	for(i=1;i<=tot;i++)
	   printf("%lld\n",ans[i]);
	return 0;
}
