//����������S1��S2(ֻ�д�д��ĸ)����S1��S2�г����˶��ٴΡ�
//��ȻҲ��kmp��ģ���⣬�����������ַ���hash����� 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
#define inf 1e18
#define mn 1000005
#define p 1000000007
using namespace std;
ll ans,n,m;
ull b[mn],h[mn];
char s[mn],s2[mn];
ull id(char ch){return ch-'A';}
ull cal(ull *h,ll l,ll r)//���Ǽ����һ����������ǰ׺hashֵh[]֮�󣬱����O(1)��������Ӵ���hashֵ 
{
	return h[r]-h[l-1]*b[r-l+1];
}
int main()
{
	ll t,x,y,z,i,j,k;
	char ch;
	cin>>t;
	b[0]=1;
	for(i=1;i<mn;i++)
		b[i]=b[i-1]*p;
	while(t--)
	{
		scanf("%s",s+1);
		scanf("%s",s2+1);
		n=strlen(s+1);m=strlen(s2+1);
		ull sum=0;ans=0;
		for(i=1;i<=n;i++)
			sum=sum*p+id(s[i]);
		for(i=1;i<=m;i++)
			h[i]=h[i-1]*p+id(s2[i]);
		for(i=1;i<=m-n+1;i++)
		if(sum==cal(h,i,i+n-1))ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
