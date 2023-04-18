#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
int cheng(int a[],int b[],int c[])
{int i,j;
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
int main()
{int zhong,bj,a[1005],b[1005],c[1005]={0},d,num,e,ma,m,n,k,i,j,t,x,v,y,z;
   string s;
	cin>>s;
	a[0]=s.length();
	for(i=1;i<=a[0];i++)
    a[i]=s[a[0]-i]-'0';
    cin>>s;
	b[0]=s.length();
	for(i=1;i<=b[0];i++)
    b[i]=s[b[0]-i]-'0';
    cheng(a,b,c);
    for(i=c[0];i>=1;i--)
    	cout<<c[i];
}
