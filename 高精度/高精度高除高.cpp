#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
void jian(int a[],int d[])
{    
	int i;
	for(i=1;i<=a[0];i++)
	{
		if(a[i]<d[i])
		{
			a[i+1]--;
			a[i]+=10;
		}
		a[i]=a[i]-d[i];
	}
	while(a[0]>0&&a[a[0]]==0)
	a[0]--;
}		
int compare(int a[],int d[])
{int i,bj=0;
  	if(a[0]>d[0])bj=1;
    if(a[0]<d[0])bj=-1;
    if(a[0]==d[0])
    for(i=a[0];i>=1;i--)
	{
	    if(a[i]>d[i]){bj=1;break;}
	    if(a[i]<d[i]){bj=-1;break;}
	}
    return bj;
}            
void fuzhi(int b[],int d[],int i)
{
    for(int j=1;j<=b[0];j++)
    d[j+i-1]=b[j];
    d[0]=b[0]+i-1;
}     
int main()
{int zhong,bj=0,a[1005]={0},b[1005]={0},c[1005]={0},d[1005],num,e,ma,m,n,k,i,j,t,x=0,v,y,z;
   	string s;
   	cin>>s;
   	a[0]=s.length();
   	for(i=1;i<=a[0];i++)
    	a[i]=s[a[0]-i]-'0';
    cin>>s;
    b[0]=s.length();
	for(i=1;i<=b[0];i++)
	b[i]=s[b[0]-i]-'0';
    c[0]=a[0]-b[0]+1;
    for(i=c[0];i>=1;i--)
    {
		memset(d,0,sizeof(d));
       	fuzhi(b,d,i);
       	while(compare(a,d)>=0){c[i]++;jian(a,d);}
    }
	while(c[0]>0&&c[c[0]]==0)c[0]--;
	for(i=c[0];i>=1;i--)
		cout<<c[i];
	cout<<endl;	
	while(a[0]>0&&a[a[0]]==0)a[0]--;
	for(i=a[0];i>=1;i--)
		cout<<a[i];if(a[0]==0)cout<<0;
	return 0;
}
