//��һ�ĵ�ֻ�ܽ����򵥵�ac�Զ������⣬����������ac�Զ���+dp���֣�����н������ 
N��ģʽ����һ������������N��ģʽ�����м����������������
���൱�ںܶ��kmp 
�������������ac�Զ��������
ac�Զ����ľ�������failָ�룬���ָ������ú�kmp��next�������
failָ��ָ��ĸ�����ڵ���ַ�����ͬ�ģ�����ָ��root����
���ұ�ָ��Ľڵ㵽root�ڵ���ַ����ʹ˽ڵ����ϵ�һ�����ַ�������ͬ�ģ�
����ζ�ţ���Ȼ����ζ�����ƥ�䵽�����ô��ͬ�����Դ�rootƥ�䵽failָ�봦���������kmp��next��������
��ϸ��ͼ
 
�������⻹�и�������˼�ı��Σ������������ĳ�����Ƿ���ĳ������ǰ׺���ߺ�׺��
���ʱ����Ȼ������ȻҪ����ģʽƥ�䣬�����п���ʹ�������м���ֵ�ĳ��������ģʽ����ͬ��������Ϊ��ǰ׺���ߺ�׺��
���ʱ�����ǿ��Խ�ģʽ����ǰ�棨���棩����'_'��
������������û�õķ��ţ�����������ַ��ĺ���һ�����ȷ�˵char('z'+1)֮��ģ��������Ϳ��Ա����������

���⣺����n����Сд��ĸ��ɵĵ��ʣ�Ȼ�����m��Сд��ǰ׺���׺������ÿ��ǰ׺���׺�����������n���������ж��ٸ�ͬʱ�������ǡ�
��������ÿ������ת��Ϊ������_����
����avtobusתΪavtobus_avtobus
��ǰ׺�ͺ�׺������»��߲��������AC�Զ���
����abac aתΪa_abac
��������ƥ������ͳ�Ƹ���
ע��������ظ����ַ������轫ͳ��д�������ڲ�
 
����Ϊac�Զ�������ͨ��
����n��ģʽ����һ���ı���t�����ж��ٸ���ͬ��ģʽ�����ı�������ֹ���
����ֻ����ֹ�
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll cnt=0,ans=0,n,m;
struct w{ll ch[26],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[1000005];
char s[1000005];
queue<ll>q;
void ins(char *s)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	a[x].num++;
}
void bui()
{ll i,x;
	for(i=0;i<26;i++)
	if(a[0].ch[i])
	{
		a[a[0].ch[i]].f=0;
		q.push(a[0].ch[i]);
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=0;i<26;i++)
		if(a[x].ch[i])
		{
			a[a[x].ch[i]].f=a[a[x].f].ch[i];
			q.push(a[x].ch[i]);
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)
{ll i,j,t,len=strlen(s),x=0;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		x=a[x].ch[j];
		for(t=x;t&&~a[t].num;a[t].num=-1,t=a[t].f)//�������ֻ����ֹ������ã����԰�numֵΪ-1������Ͳ��ñ����ˣ���Ϊ���Ѿ�ȷ�������ֹ� 
		ans+=a[t].num;
	}
}
int main()
{
	ll t,i,j,k,z,y,x;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	bui();
	scanf("%s",s);
	ac(s);
	cout<<ans;
	return 0;
}

����һ���ı�����n��ģʽ��������ֱ����ÿ��ģʽ�����ı����г��ֵĴ�����
���Ҫ��ÿ��ģʽ�����ֵĴ����Ļ����͵ñ���������
for(t=x;t&&~a[t].num;a[t].num=-1,t=a[t].f)//�������ֻ����ֹ������ã����԰�numֵΪ-1������Ͳ��ñ����ˣ���Ϊ���Ѿ�ȷ�������ֹ� 
	ans+=a[t].num;//����ԭ����д�� 
for(t=x;t;t=a[t].f)//�����൱�����ڱ�����fail����trie���ڵ��ٵ�ʱ�򻹿��������ã��ڵ���˾ͻᱬ 
	bj[t]++;
for(i=1;i<=n;i++)
ans=max(ans,bj[b[i]]);//b[i]Ϊÿ��ģʽ����trie���ϵ���ֹ�ڵ�
��������ͬ������һ���Ż�
Ȼ��Ļ����ܶ����� AC �Զ������ж�ģƥ��ʱ���ᱩ���� fail �ߣ������������Ӷ��Ǵ���ģ�
���Ա������� aaaaa����aaaaa �����Ĵ�������
��Ϊ��ʱÿ����failֻ��ʹ����ȼ�һ��ÿ�ζ����������trie�������Ӷ�Ϊo��n*m�� 
��ȷ�������ǽ��� fail ������¼�Զ����ϵ�ÿ��״̬��ƥ���˼��Σ�ֻ���ڵ�һ��ƥ��Ľڵ�++
���ײµ���ÿһ����fail�Ĺ��̣��Ƿǳ��������Ҷ�ӽڵ������ڵ����ģ���ô����·�ϵĽڵ��bj[x]����++
���������ȫ������dfsͳ��������bj�ܺ������ 
��fail�ڵ�Ϊprt��x���ߣ�����root��ʼ������dfsһ�Σ� 
������ÿ��ģʽ���� Trie �ϵ���ֹ�ڵ��� fail ���ϵ�������ƥ������Ϳ����ˡ�
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 2000005
using namespace std;
ll bj[mn],h[mn],cnt=0,ans=0,n,m,b[mn],tot=0;
struct w{ll ch[26],f,num;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn];
struct ww{ll next,to;}c[mn];
char s[mn];
queue<ll>q;
void add(ll x,ll y)
{
	c[++tot]=(ww){h[x],y};
	h[x]=tot;
}
void dfs(ll x)
{ll i,y;
	for(i=h[x];i;i=c[i].next)
	{
		y=c[i].to;
		dfs(y);
		bj[x]+=bj[y];
	}
}
void ins(char *s,ll z)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a'; 
		if(a[x].ch[j]==0)a[x].ch[j]=++cnt;
		x=a[x].ch[j];
	}
	b[z]=x;
}
void bui()
{ll i,x;
	for(i=0;i<26;i++)
	if(a[0].ch[i])
	{
		a[a[0].ch[i]].f=0;
		q.push(a[0].ch[i]);
	}
	while(q.empty()==0)
	{
		x=q.front();
		q.pop();
		for(i=0;i<26;i++)
		if(a[x].ch[i])
		{
			a[a[x].ch[i]].f=a[a[x].f].ch[i];
			q.push(a[x].ch[i]);
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(char *s)
{ll i,j,len=strlen(s),x=0;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		x=a[x].ch[j];
		bj[x]++;//���ǽ���ֻ���ڵ�һ���ڵ�++ 
	}
}
int main()
{
	ll t,i,j,k,z,y,x;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s,i);
	}
	bui();
	scanf("%s",s);
	ac(s);
	for(i=1;i<=cnt;i++)
	add(a[i].f,i);
	//���ײµ���ÿһ����fail�Ĺ��̣��Ƿǳ��������Ҷ�ӽڵ������ڵ����ģ���ô����·�ϵĽڵ��bj[x]����++
	//���������ȫ������dfsͳ��������bj�ܺ������ 
	dfs(0);
	for(i=1;i<=n;i++)
	printf("%lld\n",bj[b[i]]);
	return 0;
}
