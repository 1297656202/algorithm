//P6139 ��ģ�塿�����׺�Զ��������� SAM��
//����n����Сд��ĸ��ɵ��ַ��������ʲ�ͬ���Ӵ����������������մ���

//���ѡһ�ַ�ʽ�����Զ�������Ϊ����maxlen[i]-maxlen[fa[i]]��ԭ�����׺�Զ����Ķ�̬���㱾�ʲ�ͬ���Ӵ�������
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2000005
using namespace std;//����һ�㿪���ַ������ȵ����� 
//ch[][]��Ӧ�����Զ����ϵıߣ��Զ����൱��һ��ѹ����trie����fa[]��Ӧ����parent����ÿ���ڵ�ĸ���
ll b[mn],c[mn],sz[mn],ch[mn][26],//ֻ��Сд��ĸ����26������ַ���Χ����Ҫ��map 
//sz[]Ϊ��ǰEndpos�ļ��ϴ�С����i��Ӧ�ַ������ϵĳ��ִ���
fa[mn],l[mn],last,tot,//l[]��ʾ�ڵ��Ӧ��endpos��Ӧ������ַ�������maxlen 
ans=0,n,m;
char s[mn];
ll ins(ll k)//����һ���µĽڵ㣬ÿ��return��䷵�صľ������һ������Ľڵ� 
{ll i;
    if(ch[last][k])
	{
	    ll p=last,x=ch[p][k];
	    if(l[p]+1==l[x])return x;//�����������1
	    else
		{
	 	    ll y=++tot;l[y]=l[p]+1;
	    	for(i=0;i<26;i++)ch[y][i]=ch[x][i];
	    	while(p&&ch[p][k]==x){ch[p][k]=y;p=fa[p];}
	    	fa[y]=fa[x];fa[x]=y;
	    	return y;//�����������2
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
    return z;
}
int main()
{
	ll x,y,z,i,j,k;
	cin>>n;
	tot=1;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		last=1;
		for(j=1;s[j];j++)last=ins(s[j]-'a');
	}
	for(i=2;i<=tot;i++)
	ans+=l[i]-l[fa[i]];
	cout<<ans;
	return 0;
}
