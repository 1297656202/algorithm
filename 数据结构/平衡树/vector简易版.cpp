����Ҫдһ�����ݽṹ���ɲο���Ŀ���⣩����ά��һЩ����������Ҫ�ṩ���²�����
1.����x��
2.ɾ��x��(���ж����ͬ��������ֻɾ��һ��)
3.��ѯx��������(��������Ϊ�ȵ�ǰ��С�����ĸ���+1)
4.��ѯ����Ϊx����
5.��x��ǰ��(ǰ������ΪС��x����������)
6.��x�ĺ��(��̶���Ϊ����x������С����)
������vector����һ���̶��ϴ���ƽ����������ins��del�ĸ��Ӷȶ���o(n)�ģ�һ���������˾ͻ�tle 

#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
vector<ll>s;
vector<ll>::iterator ps;
ll t,op,x,tms;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&op,&x);
		if(op==1)
		{
			ps=lower_bound(s.begin(),s.end(),x);
			s.insert(ps,x);
		}
		if(op==2)
		{
			ps=lower_bound(s.begin(),s.end(),x);
			s.erase(ps);
		}
		if(op==3)
		{
			tms=lower_bound(s.begin(),s.end(),x)-s.begin();
			printf("%lld\n",tms+1);
		}
		if(op==4)
		{
			printf("%lld\n",s[x-1]);
		}
		if(op==5)
		{
			ps=lower_bound(s.begin(),s.end(),x);
			printf("%lld\n",(*(--ps)));
		}
		if(op==6)
		{
			ps=upper_bound(s.begin(),s.end(),x);
			printf("%lld\n",(*ps));
		}
	}
	return 0;
}
