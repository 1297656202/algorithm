���������ĳ���l��n��ģʽ����n��ģʽ����Ҫ��������������������ж����ֿ��� 
���ҵ�����С��42ʱ��������п��ܽ�

�ܽ᣺ 
���Ǿ���ͨ��trie���ϵ�x�ڵ��fail�ڵ㵽root����x�ڵ�����һ�����������������dp�����Ż� 
��Ϊ�������ʵ����̫���ˣ�����ζ��fail�ڵ��ϵ�ĳЩ����x�ڵ���Ҳ�����
����ֻ����ֶ���ģʽ����ac�Զ���ͨ�����Ѿ�������fail�ڵ���Ϊ-1����ΪֵΪ-1�����Ƕ�ȷ���Ѿ����ֹ���
�����ٴα�����-1��������� 
������ÿ��ģʽ�����ֶ��ٴ�ac�Զ�����ͨ��fail�߽�������Ϊһ���ڵ㱻ƥ����ζ����������fail�ڵ�����ƥ��һ�Σ�
���������϶�+1�������������ͳ������sz�ķ������Ż�����ȥ�������� 
��������������
ͨ��trie����һ���ڵ�x��fail��root����x����һ���֣���fail�ܰ�����ģʽ����xҲһ������
���������������״ѹdp�Ӷ���֪ƥ�䵽����ڵ������ģʽ��ͬʱҲƥ�䵽����Щģʽ��
������ȥ�������� 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 1055
using namespace std;
ll cnt=0,ans=0,n,m,f[26][105][mn],h[26*105*mn*2],tot=0;
struct w{ll ch[26],f,num;char z;
void st(){memset(ch,0,sizeof(ch));f=0;num=0;}
}a[mn];
char s[mn];
queue<ll>q;
ll sign=0;
string ss[50];
struct ww{ll next,to;char z;}c[26*105*mn*10];
ll cal(ll i,ll j,ll k)
{
	return i*(cnt+1)*(1<<n)+j*(1<<n)+k;
}
void add(ll x,ll y,char z)
{
	c[++tot]=(ww){h[x],y,z};
	h[x]=tot;
}
void dfs(ll x,string s,ll k)
{ll i,y;
	if(k==1)
	{
		ss[++sign]=s;
		return ;
	}
	for(i=h[x];i;i=c[i].next)
	{
		y=c[i].to;
		dfs(y,c[i].z+s,k-1);
	}
}
void ins(char *s,ll z)
{ll len=strlen(s),x=0,i,j;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		if(a[x].ch[j]==0)
		{
			a[x].ch[j]=++cnt;
			a[cnt].z=s[i];//��¼ÿ���ڵ����ĸ 
		}
		x=a[x].ch[j];
	}
	a[x].num=(1<<(z-1));
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
			//����Ϊ�ص㣬��Ϊtrie����һ���ڵ�x��fail��root����x����һ���֣���fail�ܰ�����ģʽ����xҲһ������ 
			a[a[x].ch[i]].num|=a[a[a[x].f].ch[i]].num;
		}
		else a[x].ch[i]=a[a[x].f].ch[i];
	}
}
void ac(ll len)//���������ac�Զ�����dp��ľ������� 
{ll i,j,l,k,x;
	f[0][0][0]=1;
	for(i=0;i<len;i++)//f[i][j][k]��ʾ��������ƥ���i���ַ�ʱ
		for(j=0;j<=cnt;j++)//������trie���ϵĵ�j���ڵ�
			for(k=0;k<=(1<<n)-1;k++)//k��״ѹ����ʾ�Ѿ�������Щģʽ�� 
				for(l=0;l<26;l++)//lΪj�ڵ�����ڵ�ı��� 
				{
					x=a[j].ch[l];//xΪj����Ľڵ� 
					f[i+1][x][k|a[x].num]+=f[i][j][k];//��f[i][j][k]������f[i+1][x][k|a[x].num] 
					//��������Χ��42���ڣ����ǿ��Զ�ÿһ��dp�й��׵Ľڵ����ߣ���󵹹��������ó����н�  
					if(f[i][j][k]>0&&f[i][j][k]<=42)add(cal(i+1,x,k|a[x].num),cal(i,j,k),a[j].z);
				}
	ans=0;
	for(i=0;i<=cnt;i++)//��Ϊ����ǰ��һ�����º���һ�������Դ���f[len][i(���нڵ�)][��״̬] 
	ans+=f[len][i][(1<<n)-1];
}
int main()
{
	ll t=0,i,j,k,z,y,x;
	char ch;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s,i);
	}
	bui();
	ac(m);
	cout<<ans<<endl;
	if(ans<=42)
	{
		string s="";
		for(i=0;i<=cnt;i++)
		dfs(cal(m,i,(1<<n)-1),a[i].z+s,m);
		sort(ss+1,ss+sign+1);
		for(i=1;i<=sign;i++)
		cout<<ss[i]<<endl;
	}
	return 0;
}
