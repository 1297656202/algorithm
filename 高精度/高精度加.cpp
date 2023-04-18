#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{long long zhong,bj=1,a[1005],b[1005],c,d,num,e,ma,m,n,k,i,j,t,x,v,y,z;
	string s;
	cin>>s;
	a[0]=s.length();
	for(i=1;i<=a[0];i++)
    a[i]=s[a[0]-i]-'0';
    cin>>s;
	b[0]=s.length();
	for(i=1;i<=b[0];i++)
    b[i]=s[b[0]-i]-'0';
    if(a[0]<b[0])a[0]=b[0];
    for(i=1;i<=a[0];i++)
        a[i]=a[i]+b[i];
    for(i=1;i<=a[0];i++)
    {a[i+1]+=a[i]/10;a[i]=a[i]%10;}
    if(a[a[0]+1]>0)a[0]++;
    for(i=a[0];i>=1;i--)
        cout<<a[i];
	return 0;
}
