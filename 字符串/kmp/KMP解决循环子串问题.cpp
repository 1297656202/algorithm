�������a���Ƿ���Ա�ʾΪһ���Ӵ���ѭ�� 
����:����S�ĳ���Ϊlen����S����ѭ���Ӵ������ҽ���,len���Ա�len - next[len]���������ѭ���Ӵ�ΪS[len - next[len]] 
֤��:��S=q1q2q3q4q5q6q7q8������next[8]=6����ʱstr = S[len -next[len]]=q1q2�����ַ�����������next�Ķ����֪��
q1q2q3q4q5q6=q3q4q5q6q7q8������q1q2=q3q4��q3q4=q5q6,q5q6=q7q8��q1q2Ϊѭ���Ӵ�������֪Ϊ���ѭ���Ӵ���
�����Ϲ��̿�֪����len���Ա�len - next[len]��������S����ѭ���Ӵ������򲻴��ڡ�
�ⷨ:����KMP�㷨�����ַ�������������next��
��len���Ա�len - next[len]�����������ѭ������nΪlen/(len - next[len])������Ϊ1��

����Ϊ��ѭ���Ӵ��Ĵ��� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define next Next
using namespace std;
ll n,m,next[mn];
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	string s;
	while(cin>>s)
	{
		if(s[0]=='.')break;
		next[1]=0;
		n=s.length();
		s=" "+s;
		for(i=2,j=0;i<=n;i++)//����a������ƥ�� 
		{
			while(j>0&&s[i]!=s[j+1])j=next[j];
			if(s[i]==s[j+1])j++;
			next[i]=j;
		}
		if(n%(n-next[n])==0)
		   cout<<n/(n-next[n])<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
