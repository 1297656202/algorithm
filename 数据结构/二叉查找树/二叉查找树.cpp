#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll tot=0,root,ans,n,m;
struct w //���������
{
	ll key,num; //key�ý���ֵ��num��ֵ�ĸ���
	ll l,r; //��������
	ll fa;//���� 
	ll ln,rn; //�ý�����������Ľ����
}a[mn];
ll search(ll p,ll x)
{ 
	while(p)
	{ 
		if(x==a[p].key)break; //���ҳɹ�
		if(x<a[p].key)p=a[p].l;//������
		else p=a[p].r; //������
	}
	return p;
}
ll ins(ll &v,ll x)
{ 
	if(v==0) //�����½��
	{ 
		v=++tot;
		a[v].key=x;
		a[v].l=a[v].r=0;
		a[v].ln=0;a[v].rn=0;
		a[v].num=1;
		return v;
	}
	ll p;
	if(x<=a[v].key)//����������
	{ 
		a[v].ln++;
		p=ins(a[v].l,x);
	}
	else//����������
	{ 
		a[v].rn++;
		p=ins(a[v].r,x);
	}
	return p;
}
void bui()
{ll i,x;
	cin>>n;root=0;
	for(i=1;i<=n;i++){cin>>x;ins(root,x);}
}
void inorder(ll p)//������� 
{ 
	inorder(a[p].l); //�ݹ�������
	cout<<a[p].key<<endl;//�������ڵ�
	inorder(a[p].r); //�ݹ�������
}
void del(ll root,ll x)
{ll y,p=root,t;
	while(p) 
	{ 
		if(a[p].key==x)break;
		y=p;
		if(x<=a[p].key){a[p].ln--;p=a[p].l;}
		else {a[p].rn--;p=a[p].r;}
	}
	if(a[p].l==0&&a[p].r==0)
	{ 
		if(y==0)root=0;
		if(a[y].l==p)a[y].l=0;
		else a[y].r=0;
		return;
	}
	if(a[p].l)
	{ 
		t=a[p].l;a[p].ln--;
		y=p;
		while(a[t].r){y=t;t=a[t].r;a[t].rn--;}
		a[p].key=a[t].key;
		if(y==p)a[y].l=a[t].l;
		else a[y].r=a[t].l;
		return ;
	}
	if(a[p].r) 
	{ 
		t=a[p].r;a[p].rn--;
		y=p;
		while(a[t].l){y=t;t=a[t].l;a[t].ln--;}
		a[p].key=a[t].key;
		if(y==p)a[y].r=a[t].r;
		else a[y].l=a[t].r;
		return ;
	}
}
ll maxnum(ll p)
{
	while(a[p].r)p=a[p].r;
	return p;
}
ll minnum(ll p)
{
	while(a[p].l)p=a[p].l;
	return p;
}
ll qian(ll p)
{
	if(a[p].l)return maxnum(a[p].l);
	ll y=a[p].fa;
	while(y&&p==a[y].l)
	{
		p=y;
		y=a[y].fa;
	}
	return y;
}
ll hou(ll p)
{
	if(a[p].r)return minnum(a[p].r);
	ll y=a[p].fa;
	while(y&&p==a[y].r)
	{
		p=y;
		y=a[y].fa;
	}
	return y;
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	
    return 0;
}
