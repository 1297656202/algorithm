sa[i]������Ϊi�ĺ�׺��λ�� 
rak[i]���ӵ�i��λ�ÿ�ʼ�ĺ�׺������
tp[i]����������ĵڶ��ؼ��֣�������saһ�������ڶ��ؼ�������Ϊi�ĺ�׺��λ�� 
sum[i]��i��Ԫ�س����˶��ٴΡ������������� 
��rak[sa[i]]=i��sa[rak[i]]=i

height������ܣ� 
i�ź�׺����i��ʼ�ĺ�׺
lcp(x,y)���ַ���x���ַ���y�������ǰ׺��������ָx�ź�׺��y�ź�׺�������ǰ׺
ht[i]��lcp(sa[i],sa[i-1])��������Ϊi�ĺ�׺������Ϊi-1�ĺ�׺�������ǰ׺
H[i]��ht[rak[i]]����i�ź�׺����ǰһ���ĺ�׺�������ǰ׺
���ʣ�H[i]>=H[i-1]-1

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll rak[mn],sa[mn],sum[mn],tp[mn],ht[mn],
ans,n,m;
char s[mn];
//sum[]�����Сȡ����������������ַ��Ĵ�С���������Ļ�����Ҫ��ɢ��  
void getht()//����height���� 
{ll i,j,k=0;
	for(i=1;i<=n;i++)
	{
		if(k)k--;
		j=sa[rak[i]-1];
		while(s[i+k]==s[j+k])k++;
		ht[rak[i]]=k;
	}
}
void cal()//�������� 
{ll i;
	for(i=0;i<=m;i++)sum[i]=0;
	for(i=1;i<=n;i++)sum[rak[i]]++;
	for(i=1;i<=m;i++)sum[i]+=sum[i-1];
	for(i=n;i>=1;i--)sa[sum[rak[tp[i]]]--]=tp[i];
}
void makesa()//������׺����  
{ll i,j,p;
	m=75;//mΪ������Ŀ����ĸ��Ҫ���ٸ���������� 
	for(i=1;i<=n;i++){rak[i]=s[i]-'0'+1;tp[i]=i;}//s[i]��ȥ�����ַ�����Сֵ��+1 
	cal();
	for(j=1,p=0;p<n;m=p,j*=2)
	{
		p=0;
		for(i=1;i<=j;i++)tp[++p]=n-j+i;
		for(i=1;i<=n;i++)if(sa[i]>j)tp[++p]=sa[i]-j;
		cal();
		swap(tp,rak);
		rak[sa[1]]=p=1;
		for(i=2;i<=n;i++)
		rak[sa[i]]=(tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+j]==tp[sa[i]+j])?p:++p;
	}
	for(i=1;i<=n;i++)
	printf("%lld ",sa[i]);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	scanf("%s",s+1);
	n=strlen(s+1);
	makesa();
	getht(); 
	return 0;
}
