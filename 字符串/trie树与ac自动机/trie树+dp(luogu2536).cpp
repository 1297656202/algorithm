ÿ��RNAƬ�ζ�����A��C��T��G��ɵ����С���ѧ����Ҳ�ܽ����Samuel�����ϵ�"����ģ��Ƭ��"��
һ��ģ��Ƭ������A��C��T��G�����м���ͨ��� * �� ? ����ʾ��
���� * ����˼�ǿ���ƥ����0�����������ַ����� ? ����˼��ƥ��������һ����ĸ��
���һ��RNAƬ���ܹ���"����ģ��Ƭ��"��ƥ�䣬��ô���RNAƬ�ξ���δ֪�Ĳ�����
���磬����"����ģ��Ƭ��"ΪA*G?C��RNAƬ�Σ�AGTC��AGTGTC����δ֪�Ĳ�������RNAƬ��AGTGC���ǲ�����
��������ΪС����д����ͳ����ЩRNAƬ�β��ǲ�����
˼·����Ϊ�Ǵ�ͷƥ�䵽β������ֻ��trie���Ϳ����ˣ�����Ҫ��ac�Զ���
���ǹ�RNAƬ�ι���trie����Ȼ����ģʽ��ȥbfs���ܹ�������������д���
(ww){x,y}Ϊ��trie���ϵ�x�ڵ㴦��ģʽ���ĵ�y���ַ�
��Ϊֻbfs�ᳬʱ������Ҫ��bitset��Ϊvis�����Ż��������bool�ᱬ�ڴ棩 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1005
using namespace std;
ll cnt=0,ans=0,n,m;
struct w{ll ch[4],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn*mn];
char ss[mn];
char s[mn];
struct ww{ll x,y;};
queue<ww>q;
ll get(char ch)//�������� 
{
	if(ch=='A')return 0;
	if(ch=='G')return 1;
	if(ch=='C')return 2;
	if(ch=='T')return 3;
	if(ch=='*')return 4;
	if(ch=='?')return 5;
}
void ins(char *s)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=get(s[i]);
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	a[x].num++;//����²��Ӵ� 
}
bitset<1005>vis[505*505];
int main()
{
	ll t=0,i,j,k,z,y,x;
	char ch;
	scanf("%s",ss);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	ll len=strlen(ss);
	q.push((ww){0,0});
	while(q.empty()==0)
	{
		ww u=q.front();
		q.pop();
		x=u.x;
		y=u.y;
		if(vis[x][y])continue;
		vis[x][y]=1;
		if(y==len)
		{
			ans+=a[x].num;
			a[x].num=0;
			continue;
		}
		k=get(ss[y]);
		if(k<=3)
		{
			if(a[x].ch[k]&&vis[a[x].ch[k]][y+1]==0)
			q.push((ww){a[x].ch[k],y+1});
		}
		else if(k==5)
		{
			for(i=0;i<=3;i++)
			if(a[x].ch[i]&&vis[a[x].ch[i]][y+1]==0)q.push((ww){a[x].ch[i],y+1});
		}
		else 
		{
			q.push((ww){x,y+1});
			for(i=0;i<=3;i++)
			if(a[x].ch[i])
			{
				if(vis[a[x].ch[i]][y]==0)q.push((ww){a[x].ch[i],y});
				if(vis[a[x].ch[i]][y+1]==0)q.push((ww){a[x].ch[i],y+1});
			}
		}
	}
	cout<<n-ans;
	return 0;
}
