#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;
ll rak[mn],sa[mn],sum[mn],tp[mn],ht[mn],
ans,n,m;
char s[mn];
//sum[]数组大小取决于整个串的最大字符的大小，如果过大的话还需要离散化  
void getht()//创建height数组 
{ll i,j,k=0;
	for(i=1;i<=n;i++)
	{
		if(k)k--;
		j=sa[rak[i]-1];
		while(s[i+k]==s[j+k])k++;
		ht[rak[i]]=k;
	}
}
void cal()//基数排序 
{ll i;
	for(i=0;i<=m;i++)sum[i]=0;
	for(i=1;i<=n;i++)sum[rak[i]]++;
	for(i=1;i<=m;i++)sum[i]+=sum[i-1];
	for(i=n;i>=1;i--)sa[sum[rak[tp[i]]]--]=tp[i];
}
void makesa()//创建后缀数组  
{ll i,j,p;
	m=75;//m为整个题目的字母需要多少个数字来表达 
	for(i=1;i<=n;i++){rak[i]=s[i]-'0'+1;tp[i]=i;}//s[i]减去所有字符的最小值再+1 
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
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n; 
	scanf("%s",s+1);
	makesa();
	getht();
	for(i=2;i<=n;i++)
		ans+=ht[i];
	cout<<n*(n+1)/2-ans;
	return 0;
}
