//luogu4070 [SDOI2016]����ħ�䣺ÿ����һ���ַ����ĺ����һ���ַ�����ÿ�μ���֮��ı��ʲ�ͬ���Ӵ����� 
//����⣬��ΪSAM�������������㷨�����Կ���ÿ�ΰ�һ���ַ��ӵ�SAM���棬ÿ�ν������ڵ�Ĺ��׼���һ�¡�
//Ϊmaxlen(q)-maxlen(fa(q))
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 200005
using namespace std;//����һ�㿪���ַ������ȵ����� 
ll b[mn],c[mn],sz[mn],s[mn],//ֻ��Сд��ĸ����26��sz[]Ϊ��ǰEndpos�ļ��ϴ�С����i��Ӧ�ַ������ϵĳ��ִ���
fa[mn],l[mn],last,tot,//fa[]��ʾparent����ÿ���ڵ�ĸ��ף�l[]��ʾÿ���ڵ��Ӧ���ַ�������  
ans=0,n,m;
map<ll,ll>ch[mn];//������ַ�����ķ�Χ�ر���ʱ�򣬾���Ҫ��map/unordered_map
void ins(ll c)//����һ���ַ�  
{ll p=last,np=++tot;last=np;l[np]=l[p]+1;
    for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
    if(!p)fa[np]=1;
    else
	{
        ll q=ch[p][c];
        if(l[p]+1==l[q])fa[np]=q;
        else
		{
            ll nq=++tot;l[nq]=l[p]+1;
            ch[nq]=ch[q];//��Ӧ��memcpyҲҪ�� 
            fa[nq]=fa[q];fa[q]=fa[np]=nq;
            for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
        }
    }
    ans+=l[np]-l[fa[np]];//���������ڵ�Ĺ��� 
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	last=tot=1;//last��parent������һ���ڵ㣬tot��parent��/sam�Ͻڵ���ܸ��� 
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		ins(s[i]);
		printf("%lld\n",ans);
	} 
	return 0;
}
