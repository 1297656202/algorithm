����n��num���ٸ���һ����Ϊn�����У����������num�ε��Ӵ�����󳤶�

i�ź�׺����i��ʼ�ĺ�׺
lcp(x,y)���ַ���x���ַ���y�������ǰ׺��������ָx�ź�׺��y�ź�׺�������ǰ׺
ht[i]��lcp(sa[i],sa[i-1])��������Ϊi�ĺ�׺������Ϊi-1�ĺ�׺�������ǰ׺

lcp(sa[i],sa[j])=min(ht[i+1,...j])�� ��rmqά����O(1)��ѯ
ͬʱ��lcp(sa[i],sa[j])�����൱����sa[i]��׺��sa[j]��׺֮��������ǰ׺��
���൱��sa[i],sa[i+1]......sa[j]�����е������ǰ׺

�ص����⣬Ҫʹ����ǰ׺��������ô�϶�����������һ��ģ�������⣬�϶����������ǰ׺���н϶���ͬ�� 
����ֻ��Ҫ���ÿ������Ϊnum-1���䣬Ȼ�����������������ֵ�����ǳ�������num�ε��Ӵ�����󳤶�

���⣬������Ŀ�и�С���ɣ��ܶ�ʱ������������ַ���s=s1+'#'+s2
s1��s2����Ϊ��Ŀ�и����ַ��������䵹�������ַ������������������������������� 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll rak[mn],sa[mn],sum[mn*10], 
tp[mn],ht[mn],s[mn],f[mn][21],
ans,n,m,num;
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
	m=1000000;//mΪ������Ŀ����ĸ��Ҫ���ٸ����������ܿ��ܲ���Ҫ��ô�� 
	for(i=1;i<=n;i++){rak[i]=s[i];tp[i]=i;}//�������ֻ��Сд��ĸ�Ļ�������s[i]-'a'+1 
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
ll lcp(ll x,ll y)//��x��ʼ�ĺ�׺���y��ʼ�ĺ�׺�������ǰ׺ 
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
