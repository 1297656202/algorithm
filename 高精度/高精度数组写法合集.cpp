//并不能够处理负数的情况  
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 500005
using namespace std;
ll a[mn],c[mn],b[mn],d[mn],ans,n,m,mod;
ll cmp(ll a[],ll b[])
{ll i;
    if(a[0]>b[0])return 1;
    if(a[0]<b[0])return -1;
    if(a[0]==b[0])
    for(i=a[0];i>=1;i--)
    {
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return -1;
    }
    return 0;
}
void jian(ll a[],ll b[])
{ll i;
    for(i=1;i<=a[0];i++)
    {
        if(a[i]<b[i])
        {
        	a[i+1]--;
            a[i]+=10;
        }
        a[i]=a[i]-b[i];
    }
    while(a[0]>0&&a[a[0]]==0)
    a[0]--;
}
void jia(ll a[],ll b[])
{ll i;
	if(a[0]<b[0])a[0]=b[0];
    for(i=1;i<=a[0];i++)
        a[i]=a[i]+b[i];
    for(i=1;i<=a[0];i++)
    {a[i+1]+=a[i]/10;a[i]=a[i]%10;}
    if(a[a[0]+1]>0)a[0]++;
}
void cheng(ll a[],ll b[],ll c[])
{ll i,j;
	c[0]=a[0]+b[0];
	for(i=1;i<=c[0];i++)
		c[i]=0;
    for(i=1;i<=a[0];i++)
        for(j=1;j<=b[0];j++)
           c[i+j-1]+=a[i]*b[j];
    for(i=1;i<=c[0];i++)
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    while(c[0]>0&&c[c[0]]==0)c[0]--;
}
void div(ll a[],ll y,ll c[])//高除单 
{ll i,x=0;
    c[0]=a[0];
    for(i=a[0];i>=1;i--)
    {
        x=x*10+a[i];
        c[i]=x/y;
        x=x%y;
    }
    while(c[c[0]]==0)c[0]--;
}
void div2(ll a[],ll b[],ll c[])//高除高 
{ll i,j; 
	c[0]=a[0]-b[0]+1;
    for(i=c[0];i>=1;i--)
    {
       	for(j=1;j<=b[0]+i-1;j++)
			d[j]=0;
    	for(j=1;j<=b[0];j++)
    		d[j+i-1]=b[j];
    	d[0]=b[0]+i-1;
       	while(cmp(a,d)>=0){c[i]++;jian(a,d);}
    }
	while(c[0]>0&&c[c[0]]==0)c[0]--;//c[]为商 
	while(a[0]>0&&a[a[0]]==0)a[0]--;//a[]为余数 
}
void cpy(ll a[],ll b[])
{ll i;
	a[0]=b[0];
	for(i=1;i<=a[0];i++)
		a[i]=b[i];
}
void read(ll a[])
{string s;ll i;
	cin>>s;
	a[0]=s.length();
	for(i=1;i<=a[0];i++)
    a[i]=s[a[0]-i]-'0';
}
void print(ll a[])
{ll i;
	for(i=a[0];i>=1;i--)
	printf("%lld",a[i]);
}
int main()
{
    ll x,y,z,i,j,t;
    char ch;
    
    return 0;
}
