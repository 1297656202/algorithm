hdu4162����һ���ַ���������ַ�������β������һ��ģ�Ҫ��Ѱ��һ��λ�ã�
�Ը�λ��Ϊ�����ַ������ֵ��������е��ַ���������С��
��Сѭ����ʾ���Է���ļ��������ѭ���ַ����Ƿ���ȡ������ַ�����ȣ����ҽ������ǵ���Сѭ����ʾ��ȡ�
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll ans=0,tot=1,sign=0,cnt=0,m,n;
char s1[mn],s2[mn];
ll cal(char s[])
{ll i,j=2,k;
	for(i=1;i<=n;i++)
	{
		s[i+n]=s[i];
	}
	i=1;
	while(i<=n&&j<=n)
	{
		for(k=0;k<n&&s[i+k]==s[j+k];k++)
		if(k==n)break;
		if(s[i+k]>s[j+k])
		{
			i=i+k+1;
			if(i==j)i++;
		}
		else 
		{
			j=j+k+1;
			if(i==j)j++;
		}
	}
	return min(i,j);
}
int main()
{
	ll x,y,t,i,j,z,k;
	char ch;
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	if(n!=m){cout<<"No";return 0;}
	x=cal(s1);
	y=cal(s2);
	s1[x+n]=s2[y+n]=0;
	for(i=x,j=y;i<=x+n-1;i++,j++)
	if(s1[i]!=s2[j]){cout<<"No";return 0;}
	cout<<"Yes"<<endl;
	printf("%s",s1+x);
	return 0;
}
