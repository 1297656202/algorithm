/*
����һ�鲻��ʽx[i]-x[i]<=c[k](��x[i]-x[i]>=c[k))��
��Ҫ����������в���ʽ��һ���(x[1],x[2]....,x[n])���������������Թ滮��һ������⡣
����ǲ��Լ��ϵͳ��
���Լ��ϵͳ��Ҫͨ����С��ϵ���н�ͼ��Ȼ��ͨ��spfa��⣬ 
�������������·�㷨�����������룬�����ֵ��������������������Ȼ�������ֵ ,
��ʱ��ͼ��ʱ��Ϊ��a[i]-a[j]<=x��add(i->j) 
��֮��С�������·����a[i]-a[j]>=x��add(i->j)
Ȼ��ʹ��spfa�����ڸ�����ʱ���޽�
���Լ��ϵͳ�ؼ�����Ҫ����Լ����ϵ
���⣺
��һ���������У����ǲ�֪�����ĳ����Ƕ���(�������������ĸ���)��������֪����ĳЩ�����������ж��ٸ�������
������ [ai,bi,ci]����������[ai,bi,ci]��ʾ�ڸ������д���[ai,bi]������������������ci����
n ���ڸ������ɸ����������䣬�����������������������г����Ƕ��٣��������������� -1�� 
Լ����ϵ�� ����ǰ׺��s[i]
s[b]-S[a-1]��c[i](1<=i<=m)
S[i]-S[i-1]��0(1<=i<=n)
S[i-1]-S[i]��-1(1<=i<=n) 
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
queue<ll>q;
ll x[25],s[25],used[1005]={0},num[25]={0},d[1005],r[25],cnt=0,h[1005]={0},bj[1005],ge,n,m,t;
struct w{ll next,to,z;}a[1000005];
void add(ll x,ll y,ll z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].z=z;
	h[x]=cnt;
}
ll spfa()
{ll i,x,y;
	for(i=0;i<=24;i++)
	{ 
		q.push(i);
	    s[i]=0;
	    bj[i]=1;
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		bj[x]=0;
		for(i=h[x];i;i=a[i].next)//����������·����Ϊ��С�� 
		{
			y=a[i].to;
			if(s[y]<s[x]+a[i].z)
			{
				used[y]++;
				if(used[y]>=25)return 0;
				s[y]=s[x]+a[i].z;
				if(bj[y]==0)
				{
					q.push(y);
					bj[y]=1;
				}
			}
		}
	}
   return 1;
}
int main()
{
	ll x,y,i,j,k,z,he=0;
    for(i=1;i<=24;i++)
        cin>>r[i];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
		num[++x]++;
	}
	for(i=1;i<=24;i++)
	    he+=num[i];
	for(k=0;k<=he;k++)//�ø��ִ�С��ϵ��ͼ����Щ��С��ϵ������ 
	{
		cnt=0;
	    memset(used,0,sizeof(used));
	    memset(h,0,sizeof(h));  
		for(i=1;i<=24;i++)
	    {
		    add(i,i-1,-num[i]);
		    add(i-1,i,0);
	    }
		for(i=8;i<=24;i++)
		   add(i-8,i,r[i]);
	    s[24]=k;
	    add(24,0,-k);
	    for(j=1;j<=7;j++)
	       add(j+16,j,r[j]-k);
		if(spfa())
		{cout<<k;return 0;}
	}
	cout<<"No Solution!";
	return 0;
}
