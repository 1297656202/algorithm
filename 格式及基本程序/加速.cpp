inline void in(ll &x)
{ll s=0,w=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
   x=s*w;
}
inline void in(ll &x)
{
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
   x=s*w;
}
inline void in(int &x)
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
   x=s*w;
}

ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

void print(ll x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
#pragma GCC optimize(3)
/*inline char nc()
{
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	char t;int u=0,k=1;t=getchar();
	while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
	while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
	return u*k;
}*/
#define getchar nc
inline char nc()
{
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read()
{
	char t;ll u=0,k=1;t=getchar();
	while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
	while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
	return u*k;
}
