#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll ans,n,m;
inline void scan(__int128 &x)
{x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
inline void print(__int128 x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int main()
{
	__int128 x,y;
	char ch;
	scan(x);scan(y);
	print(x*y); 
	return 0;
}
