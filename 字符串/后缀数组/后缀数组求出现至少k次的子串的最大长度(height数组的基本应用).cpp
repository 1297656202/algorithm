给你n和num，再给你一个长为n的序列，求出现至少num次的子串的最大长度

i号后缀：从i开始的后缀
lcp(x,y)：字符串x与字符串y的最长公共前缀，在这里指x号后缀与y号后缀的最长公共前缀
ht[i]：lcp(sa[i],sa[i-1])，即排名为i的后缀与排名为i-1的后缀的最长公共前缀

lcp(sa[i],sa[j])=min(ht[i+1,...j])， 用rmq维护，O(1)查询
同时，lcp(sa[i],sa[j])不仅相当于这sa[i]后缀和sa[j]后缀之间的最长公共前缀，
还相当于sa[i],sa[i+1]......sa[j]的所有的最长公共前缀

回到例题，要使公共前缀更长，那么肯定是排名连在一起的（感性理解，肯定排名相近的前缀会有较多相同） 
我们只需要检查每个长度为num-1区间，然后求出所有区间的最大值，就是出现至少num次的子串的最大长度

另外，这类题目有个小技巧，很多时候真正处理的字符串s=s1+'#'+s2
s1，s2可能为题目中给的字符串或者其倒过来的字符串或者其他东西，具体情况具体分析 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll rak[mn],sa[mn],sum[mn*10], 
tp[mn],ht[mn],s[mn],f[mn][21],
ans,n,m,num;
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
	m=1000000;//m为整个题目的字母需要多少个数字来表达，很可能不需要这么多 
	for(i=1;i<=n;i++){rak[i]=s[i];tp[i]=i;}//这里如果只是小写字母的话，就是s[i]-'a'+1 
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
void st()
{ll i,j;
	for(i=1;i<=n;i++)
		f[i][0]=ht[i];
	for(j=1;(1<<j)<=n;j++)
	    for(i=1;i+(1<<j)-1<=n;i++)
	    f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
ll ask(ll l,ll r)
{ll x;
	x=(ll)(log(r-l+1)/log(2));
	return min(f[l][x],f[r-(1<<x)+1][x]); 
}
ll lcp(ll x,ll y)//从x开始的后缀与从y开始的后缀的最长公共前缀 
{ll l=min(rak[x],rak[y])+1,r=max(rak[x],rak[y]);
	return ask(l,r);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n>>num;
	for(i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	makesa();
	getht();
	st();
	for(i=2;i+num-2<=n;i++)
		ans=max(ans,ask(i,i+num-2));
	cout<<ans;
	return 0;
}
