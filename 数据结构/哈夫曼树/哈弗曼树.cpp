luogu2168:����ʷʫ�����ƵĻ��кϲ����� 
��n�����ʣ�����ÿ�����ʳ��ֵĴ����������k���ƴ���ʾ���е��ʵ���С���ȣ�Ȼ����������������k���ƴ��Ƕ೤

��������ÿһ���ڵ��Ȩֵ�����ֵ�Խ��ĳ��Ⱦ����̣����ֵ��ٵĳ��ȿ��Զ�һ�㣬�����ú͹���������˼���࣬
ȨֵԽ������ԽԶ��Ψһֵ��ע����ǵ�һ�κϲ�ʱ�úϲ�(n-2)%(k-1)+2�������������һЩ�սڵ���� 
ans���Ǳ�ʾ���е��ʵ���С���ȣ�Ҳ���Ǵ�Ȩ·�����ܺͣ�ͬʱҲ�Ǻϲ�������Ĵ��ۺͣ�
���һ���ڵ���ȡ�����������ĸ߶ȣ�Ҳ�������k���ƴ��Ƕ೤
�����Ҫ�õ�����������ͽ�ÿһ�δӶ�����������Ľڵ�ĸ��ڵ��¼Ϊ�ϳɵ��½ڵ㣬�Ϳ��Եõ��������
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
struct w{ll v,h;};
ll ans=0,n,m;
bool operator <(w a,w b){return a.v>b.v||(a.v==b.v&&a.h>b.h);}
priority_queue<w>q;//����С���� 
int main()
{
	ll i,j,k,x;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        q.push((w){x,0});
    }
    while((q.size()-1)%(m-1)!=0)q.push((w){0,0});//��ӿսڵ� 
    while(q.size()>1)
    {
        ll h=0,v=0;
        for(i=1;i<=m;i++)
        {
            w u=q.top();q.pop();
            h=max(h,u.h);
            v+=u.v;
        }
        ans+=v;
        q.push((w){v,h+1});
    }
    printf("%lld\n%lld\n",ans,q.top().h);
    return 0;
}
