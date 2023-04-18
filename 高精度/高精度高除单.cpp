#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{int zhong,bj=0,a[1005]={0},b[1005]={0},c[1005],d,num,e,ma,m,n,k,i,j,t,x=0,v,y,z;
   	string s;
   	cin>>s>>y;
   	a[0]=s.length();
   	for(i=1;i<=a[0];i++)
    a[i]=s[a[0]-i]-'0';
    c[0]=a[0];
    for(i=a[0];i>=1;i--)
    {
    	x=x*10+a[i];
    	c[i]=x/y;
    	x=x%y;
    }
	while(c[c[0]]==0)c[0]--;
	for(i=c[0];i>=1;i--)
	cout<<c[i];
	return 0;
}
