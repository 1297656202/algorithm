�����Ҿ���Ļ��Ĵ��� 
/*void dfs1(int x,int fa)
{ll i,j;
    stk[++top]=x;
	ins[x]=top;
    for(i=h[x];i;i=a[i].next){
        y=a[i].to;
		if(y==fa)continue;
        if(ins[y])for(j=ins[y];j<=ins[x];j++)cir[++cir[0]]=stk[j];
        else dfs1(y,x);
    }
    top--;
}*/
ע�⣺����������Ŀ����ԶҪС���п����ǻ�����ɭ��
���⣺ 
����N����N���ߵ�������Ȩ��ͨͼ��ÿ������һ����ȨVi��Ҫ
��ѡȡ���ɸ��㣬����ͬһ���������ĵ㲻��ͬʱѡ������
��ѡȡ�ĵ�Ȩ�����Ϊ���٣�
1��һ�㶼�����ҳ�ͼ��Ψһ�Ļ����ѻ���Ϊ�������ĵĹ���
�����ڵ㡱���ѳ��˻�֮��Ĳ��ְ������ɿ��������ٿ����뻷һ�����
2���������������Ҳ�У�����Ҫע���Ƿ�ƥ�� 
���룺 

#include<bits/stdc++.h>
using namespace std;
struct jjd
{	int next,to;
}a[100005*2];
int v[100005],h[100005*2]={0},dfn[100005],low[100005],belong[100005],vst[100005];
int instack[100005],stk[100005],inhuan[100005],f[100005][2];
int n,cnt=0,bj,flag=0,st,ed;
void qxx(int x,int y)
{	cnt++;a[cnt].to=y;a[cnt].next=h[x];h[x]=cnt;
}
void dp(int x,int fa)
{	f[x][1]=v[x],f[x][0]=0;
	for(int i=h[x];i;i=a[i].next)
	{	int y=a[i].to;
		if(y==fa||x==st&&y==ed||x==ed&&y==st)continue;
		dp(y,x);
		f[x][0]+=max(f[y][0],f[y][1]);
		f[x][1]+=f[y][0];
	}
}
void dfs(int x,int fa)
{	vst[x]=1;
	for(int i=h[x];i;i=a[i].next)
	{	int y=a[i].to;
		if(y==fa)continue;
		if(vst[y]){st=x;ed=y;flag=1;return;}
		dfs(y,x);
		if(flag)return;
	}
	vst[x]=0;
}
int main()
{	int i,j;
	double k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&v[i]);
	for(int i=1,x,y;i<=n;i++)
	{	scanf("%d%d",&x,&y);
		x++;y++;
		qxx(x,y);qxx(y,x);
	}
	scanf("%lf",&k);
	dfs(1,0);
	dp(st,0);double t1=f[st][0];
	dp(ed,0);double t2=f[ed][0];
	printf("%.1lf",max(t1,t2)*k);
	return 0;
}
