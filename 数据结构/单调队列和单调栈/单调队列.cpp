//P1886 �������� /��ģ�塿�������� 
//��һ����Ϊ n������ a���Լ�һ����СΪ k�Ĵ��ڡ������������߿�ʼ���һ�����ÿ�λ���һ����λ��
//���ÿ�λ����󴰿��е����ֵ����Сֵ��
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 10005
using namespace std;
ll n,m,
q1[1000001],q2[1000001],a[1000001];
ll minque()
{
    ll h=1,t=0;
    for(ll i=1;i<=n;i++)
    {
        while(h<=t&&q1[h]+m<=i) h++;
        while(h<=t&&a[i]<a[q1[t]]) t--;
        q1[++t]=i;
        if(i>=m) printf("%lld ",a[q1[h]]);
    }
    cout<<endl;
}
ll maxque()
{
    ll h=1,t=0;
    for(ll i=1;i<=n;i++)
    {
        while(h<=t&&q2[h]+m<=i) h++;
        while(h<=t&&a[i]>a[q2[t]]) t--;
        q2[++t]=i;
		if(i>=m) printf("%lld ",a[q2[h]]);
        
    }
}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    minque();
    maxque();
    return 0;
}
