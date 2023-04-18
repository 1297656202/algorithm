#include<bits/stdc++.h>
#define ll long long//////////////
#define inf 1e18
#define maxn 100005///////////////
#define ii inline
using namespace std;
ll hs=19997,k,last,h[19997],tot[2],h0,f[2][50005],ans
,Next[50005],val[50005],state[2][50005],n,m,now;
void up(ll x)
{  ll i,hp=x%hs;
   for(i=h[hp];i;i=Next[i])if(val[i]==x)break;
   if(i){f[now][i]+=f[last][k];return;}
   i=++h0;val[i]=x;
   Next[i]=h[hp];h[hp]=i;
   f[now][i]=f[last][k];tot[now]++;
   state[now][i]=x;
}
ll findr(ll s,ll x)
{  ll i,j,top=0;
   for(i=x;i<=m;i++)
   {  j=(s>>(i<<1))&3;
      if(j==1)top++;
      if(j==2)top--;
      if(!top)break;
   }
   return i;
}
ll findl(ll s,ll x)
{  ll i,j,top=0;
   for(i=x;i>=0;i--)
   {  j=(s>>(i<<1))&3;
      if(j==2)top++;
      if(j==1)top--;
      if(!top)break;
   }
   return i;
}
void work(ll x,ll y,ll s)
{  ll i,t1,t2,p1,p2,indep=0;
   p1=(y-1)<<1;p2=y<<1;
   t1=(s>>p1)&3;t2=(s>>p2)&3;
   for(i=0;i<=m;i++)if(((s>>(i<<1))&3)==3)indep++;
   if(t1==0&&t2==0)
   {  if(x<n&&y<m)up(s+(1<<p1)+(2<<p2));
      if(x<n&&indep<2)up(s+(3<<p1));
      if(y<m&&indep<2)up(s+(3<<p2));
   }
   if(t1==3&&t2==3&&x==n&&y==m)up(s-(t1<<p1)-(t2<<p2));
   if(t1==3&&t2>0&&t2<3)
   {  if(t2==1)
      {  i=findr(s,y);
         up(s-(t1<<p1)-(t2<<p2)+(1<<(i<<1)));
      }
      else
      {  i=findl(s,y);
         up(s-(t1<<p1)-(t2<<p2)+(2<<(i<<1)));
      }
   }
   if(t1>0&&t1<3&&t2==3)
   {  if(t1==1)
      {  i=findr(s,y-1);
         up(s-(t1<<p1)-(t2<<p2)+(1<<(i<<1)));
      }
      else
      {  i=findl(s,y-1);
         up(s-(t1<<p1)-(t2<<p2)+(2<<(i<<1)));
      }
   }
   if(t1==2&&t2==1)up(s-(t1<<p1)-(t2<<p2));
   if(t1==1&&t2==1)
   {  i=findr(s,y);
      up(s-(t1<<p1)-(t2<<p2)-(1<<(i<<1)));
   }
   if(t1==2&&t2==2)
   {  i=findl(s,y-1);
      up(s-(t1<<p1)-(t2<<p2)+(1<<(i<<1)));
   }
   if(t1>0&&t2==0)
   {  if(x<n)up(s);
      if(y<m)up(s-(t1<<p1)+(t1<<p2));
      if(t1==1&&indep<2)
      {  i=findr(s,y-1);
         up(s-(t1<<p1)+(1<<(i<<1)));
      }
      if(t1==2&&indep<2)
      {  i=findl(s,y-1);
         up(s-(t1<<p1)+(2<<(i<<1)));
      }
      if(t1==3&&x==n&&y==m)up(s-(t1<<p1));
   }
   if(t2>0&&t1==0)
   {  if(y<m)up(s);
	  if(x<n)up(s-(t2<<p2)+(t2<<p1));
      if(t2==1&&indep<2)
      {  i=findr(s,y);
         up(s-(t2<<p2)+(1<<(i<<1)));
      }
      if(t2==2&&indep<2)
      {  i=findl(s,y);
         up(s-(t2<<p2)+(2<<(i<<1)));
      }
      if(t2==3&&x==n&&y==m)up(s-(t2<<p2));
   }
}
int main()
{  scanf("%lld%lld",&n,&m);
   tot[0]=f[0][1]=1;state[0][1]=0;
   ll i,j;
   for(i=1;i<=n;i++)
   {  for(j=1;j<=m;j++)
      {  now=!last;
         memset(h,0,sizeof(h));
         tot[now]=h0=0;
         for(k=1;k<=tot[last];k++)work(i,j,state[last][k]);
         last=now;
      }
      for(k=1;k<=tot[now];k++)state[now][k]<<=2;
   }
   for(i=1;i<=tot[now];i++)ans+=f[now][i];
   printf("%lld\n",ans);
   return 0;
}
