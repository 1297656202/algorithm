//���P3804����һ��ֻ����Сд��ĸ���ַ���S��
//�������S�����г��ִ�����Ϊ1���Ӵ��ĳ��ִ������ϸ��Ӵ����ȵ����ֵ��

//sz[i]����ڵ��Endpos���ϴ�С��Ҳ����˵��i�ŵ��ַ����������������еĳ��ִ�������parent�����ۼӼ��� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 4000005
using namespace std;//����һ�㿪���ַ������ȵ����� 
//ch[][]��Ӧ�����Զ����ϵıߣ��Զ����൱��һ��ѹ����trie����fa[]��Ӧ����parent����ÿ���ڵ�ĸ���
ll b[mn],c[mn],sz[mn],ch[mn][26],//ֻ��Сд��ĸ����26������ַ���Χ����Ҫ��map 
//sz[]Ϊ��ǰEndpos�ļ��ϴ�С����i��Ӧ�ַ������ϵĳ��ִ���
fa[mn],l[mn],last,tot,//l[]��ʾ�ڵ��Ӧ��endpos��Ӧ������ַ�������maxlen 
ans=0,n,m;
char s[mn];
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
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            fa[nq]=fa[q];fa[q]=fa[np]=nq;
            for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
        }
    }
    sz[np]=1;//�²���Ľڵ����np�����Զ�np���г�ʼ�� 
}
//����������dfs��д�� 
struct w{ll next,to;}a[mn*2];ll h[mn],cnt=0;
void add(ll x,ll y)
{
	a[++cnt]=(w){h[x],y};
	h[x]=cnt;
}
ll dfs(ll x)
{ll i,y;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		dfs(y);
		sz[x]+=sz[y];
	}
	if(sz[x]!=1)ans=max(ans,sz[x]*l[x]);
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	scanf("%s",s+1);
	ll len=strlen(s+1);
	last=tot=1;//last��parent������һ���ڵ㣬tot��parent��/sam�Ͻڵ���ܸ��� 
	for(i=1;i<=len;i++)ins(s[i]-'a');
	for(i=2;i<=tot;i++)add(fa[i],i);
    dfs(1);
    printf("%lld\n",ans);
	return 0;
}

���������ǻ��������������ǰ�����Ĳ�����һ���� 
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	scanf("%s",s+1);
	ll len=strlen(s+1);
	last=tot=1;//last��parent������һ���ڵ㣬tot��parent��/sam�Ͻڵ���ܸ��� 
	for(i=1;i<=len;i++)ins(s[i]-'a');
	//��һ�����ڻ�������Ҳ���Բ�������� 
	for(i=1;i<=tot;i++)c[l[i]]++;
    for(i=1;i<=tot;i++)c[i]+=c[i-1];
    for(i=1;i<=tot;i++)b[c[l[i]]--]=i;
   	//�Ӵ�Сö�٣�ʵ������ģ��parent����DFS
    for(i=tot;i>=1;i--)
	{
        x=b[i];
        sz[fa[x]]+=sz[x];
        if(sz[x]>1)ans=max(ans,sz[x]*l[x]);
    }
    printf("%lld\n",ans);
	return 0;
}
