KMP�㷨���ֳ�ģʽƥ���㷨���ܹ�������ʱ�����ж��ַ���A[1~N]�Ƿ�Ϊ�ַ���B[1~M]���Ӵ�,
������ַ���A���ַ���B�и��γ��ֵ�λ�á�
��ϸ�ؽ�,KMP�㷨��Ϊ����:
1.���ַ���A�������ҡ�ƥ�䡱�����һ������Next������Next[i]��ʾ
��A����i��β�ķ�ǰ׺�Ӵ����롰A��ǰ׺���ܹ�ƥ�������ȣ���:
Next[i]=max{i}������j<i����A[i-j+1~i]=A[1~j]
2.���ַ���A��B����ƥ�䣬���һ������f������f[i]��ʾ��B����i��β���Ӵ����롰A��ǰ׺���ܹ�ƥ�������ȣ���:
f[i]=max{j}������j<=i����B[i-j+1~i=A[1~j]
����˵��a��Ϊabababaac,��Ȼnext[7]=5��next[5]=3,��ô����next[8]��ʱ��
��j=next[7],�ȶԱ�a[j+1]=a[6]�Ƿ����a[8]�������ͬ��ô��next[8]=next[7]+1
������Ȼ��ͬ����ô���Ǿ���j=next[j]=3,Ȼ������a[j+1]�Ƚ�a[8],
���ֱ��j==0��ֹͣ���������������ΪʲôҪ��j=next[j], 
ab/ababa/ac
   ababa/baac
����next[7]=5,��next[5]=3����ǰ��λ��ǰ��λ�ͺ���5λ�ĺ���λ��ͬ 
��Ϊǰ5λ��xλ�ͺ�5λ��xλ�ܹ�ƥ��ľ���5λ��ƥ������λ��5�����Կ�����3������ƥ�� 

for(i=1,j=0;i<=m;i++)//������a����b���г��ֵ�λ�û��ߴ����õ� 
{ 
	while(j>0&&(j==n||b[i]!=a[j+1]))j=next[j];
	if(b[i]==a[j+1])j++;
	f[i]=j;
	//if(f[i]==n),��ʱ����A��B�е�ĳһ�γ���
}

kmp 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
#define next Next
using namespace std;
ll n,m,next[mn],f[mn];
int main()
{
	ll i,j,k,z,y,x;
	char ch;
	string s,s2;
	cin>>s2>>s;//s2Ϊ������b������sΪģʽ����a���� 
	next[1]=0;
	n=s.length();
	s=" "+s;
	m=s2.length();
	s2=" "+s2;
	for(i=2,j=0;i<=n;i++)//����a������ƥ�� 
	{
		while(j>0&&s[i]!=s[j+1])j=next[j];
		if(s[i]==s[j+1])j++;
		next[i]=j;
	}
	for(i=1,j=0;i<=m;i++)//������a����b���г��ֵ�λ�û��ߴ����õ� 
	{ 
		while(j>0&&(j==n||s2[i]!=s[j+1]))j=next[j];
		if(s2[i]==s[j+1])j++;
		f[i]=j;
		//if(f[i]==n),��ʱ����A��B�е�ĳһ�γ���
	}
	for(i=1;i<=m;i++)
	if(f[i]==n)printf("%lld\n",i-n+1);
	for(i=1;i<=n;i++)
	printf("%lld ",next[i]);
	return 0;
}
