//P3181 [HAOI2016]����ͬ�ַ�
//�����ַ���������������ַ����и�ȡ��һ���Ӵ�ʹ���������Ӵ���ͬ�ķ�������

//���Ϻ�������˵���������� |endpos|�ֿ����㣬���Կ�һ����ά���飬��siz[x][id]��ʾ�ڵ�x�ڴ�id��{endpos}��С��
//���Ϊ����siz[i][0]��siz[i][1]��(maxlen[i]-maxlen[fa[i]]) �� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1000005
using namespace std;//����һ�㿪���ַ������ȵ����� 
//ch[][]��Ӧ�����Զ����ϵıߣ��Զ����൱��һ��ѹ����trie����fa[]��Ӧ����parent����ÿ���ڵ�ĸ���
ll b[mn],c[mn],sz[mn][2],ch[mn][26],//ֻ��Сд��ĸ����26������ַ���Χ����Ҫ��map 
//sz[]Ϊ��ǰEndpos�ļ��ϴ�С����i��Ӧ�ַ������ϵĳ��ִ���
fa[mn],l[mn],last,tot,ru[mn],//l[]��ʾ�ڵ��Ӧ��endpos��Ӧ������ַ�������maxlen 
ans=0,n,m;
char s[mn];
queue<ll>q;
ll ins(ll k,ll id)//����һ���µĽڵ㣬ÿ��return��䷵�صľ������һ������Ľڵ� 
{ll i;
    if(ch[last][k])
	{
	    ll p=last,x=ch[p][k];
	    if(l[p]+1==l[x]){sz[x][id]=1;return x;}//�����������1
	    else
		{
	 	    ll y=++tot;l[y]=l[p]+1;
	    	for(i=0;i<26;i++)ch[y][i]=ch[x][i];
	    	while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
	    	fa[y]=fa[x];fa[x]=y;
	    	sz[y][id]=1;return y;//�����������2
		}
    }
    ll z=++tot,p=last;l[z]=l[last]+1;
    while(p&&!ch[p][k]){ch[p][k]=z;p=fa[p];}
    if(!p)fa[z]=1;
    else
	{
        ll x=ch[p][k];
        if(l[p]+1==l[x])fa[z]=x;
        else
		{
            ll y=++tot;l[y]=l[p]+1;
            for(i=0;i<26;++i)ch[y][i]=ch[x][i];
            while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
            fa[y]=fa[x];fa[z]=fa[x]=y;
        }
    }
    sz[z][id]=1;
    return z;
}
int main()
{
	ll x,y,z,i,j,k;
	tot=1;
	for(i=0;i<=1;i++)
	{
		scanf("%s",s+1);
		last=1;
		for(j=1;s[j];j++)last=ins(s[j]-'a',i);
	}
	for(i=2;i<=tot;i++)++ru[fa[i]];
    for(i=1;i<=tot;i++)if(!ru[i])q.push(i);
    while(!q.empty())
	{
        x=q.front();q.pop();
        sz[fa[x]][0]+=sz[x][0];
        sz[fa[x]][1]+=sz[x][1];
        if(!(--ru[fa[x]]))q.push(fa[x]);
    }
    for(i=2;i<=tot;i++)
        ans+=sz[i][0]*sz[i][1]*(l[i]-l[fa[i]]);
    printf("%lld\n",ans);
	return 0;
}
