//����ǰ������������������֮������Ϊ2������������Ϊwindy����
//windy��֪������a��b֮�䣬����a��b���ܹ��ж��ٸ�windy����

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll c[20],f[20][20],n,m;
//������һ�㣬����Ϊʲô״̬���治�ü�¼ǰ������ǰ���㣬��Ϊ��ǰ�����ʱ��y=12���Ѿ��洢������ 
ll suan(ll x,ll y,ll iszero,ll bj)//x��ǰλ��,yǰһλ��,iszero�ж�ǰ���Ƿ�ȫ��0,bj���λ���� 
{ll i,k,s=0;
	if(x==0)return 1;
	if(bj==0&&~f[x][y])return f[x][y];
	if(bj==0)k=9;
	else k=c[x];
	for(i=0;i<=k;i++)
	if(abs(i-y)>=2)
	{
		if(iszero==1&&i==0)s+=suan(x-1,12,1,bj&&i==k);
		else s+=suan(x-1,i,0,bj&&i==k);
	}
    if(bj==0)f[x][y]=s;
    return s;
}
ll ask(ll x)
{
	c[0]=0;
	while(x)
	{
		c[++c[0]]=x%10;
		x/=10;
	}
	return suan(c[0],12,1,1);
}
int main()
{
	ll x,y,i,j,k,z;
	char ch;
	memset(f,-1,sizeof(f));
	while(cin>>x>>y)
	{
	   	cout<<ask(y)-ask(x-1)<<endl;
	}
    return 0;
}
