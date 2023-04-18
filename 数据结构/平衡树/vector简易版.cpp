您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
1.插入x数
2.删除x数(若有多个相同的数，因只删除一个)
3.查询x数的排名(排名定义为比当前数小的数的个数+1)
4.查询排名为x的数
5.求x的前驱(前驱定义为小于x，且最大的数)
6.求x的后继(后继定义为大于x，且最小的数)
我们用vector可以一定程度上代替平衡树，但是ins和del的复杂度都是o(n)的，一旦操作多了就会tle 

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
