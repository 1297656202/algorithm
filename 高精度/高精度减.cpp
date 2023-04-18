#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{int zhong,bj=0,a[1005]={0},b[1005]={0},c,d,num,e,ma,m,n,k,i,j,t,x,v,y,z;
   	string s;
   	cin>>s;
   	a[0]=s.length();
   	for(i=1;i<=a[0];i++)
    a[i]=s[a[0]-i]-'0';
    cin>>s;
   	b[0]=s.length();
   	for(i=1;i<=b[0];i++)
    b[i]=s[b[0]-i]-'0';
    if(a[0]>b[0])bj=1;
    if(a[0]<b[0])bj=-1;
    if(a[0]==b[0])
    for(i=a[0];i>=1;i--)
	{
        if(a[i]>b[i]){bj=1;break;}
        if(a[i]<b[i]){bj=-1;break;}
	}
    if(bj==0){cout<<0;return 0;}
    if(bj==1)
	{
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
	if(bj==-1)
	{
		cout<<"-";
		for(i=1;i<=b[0];i++)
		{
		    if(b[i]<a[i])
			{
			    b[i+1]--;
			    b[i]+=10;
		    }
		    a[i]=b[i]-a[i];	   
		}
		a[0]=b[0];
		while(a[0]>0&&a[a[0]]==0)a[0]--;
	}
	for(i=a[0];i>=1;i--)
	    cout<<a[i];
	return 0;
}
