//���Ⱥϲ�����˵���Ǿ�����һ����������ȡ������ʹ�ø����㵽���ڵ��·��������
/*   0	   			
  0  0 �϶���һ�������� 
 0    0 */		
#define mn 100//char���߱�ĸ�ʽ�Կɣ���Ԫ����ʲô��ʽ
ll prt[mn];
ll d[mn];//d[i]��ʾÿ�����鼯�������� 
ll st(ll i)//�����i��Ԫ����Ҫ��ʼ��
{
	prt[i]=i;
	d[i]=0;
}
void Union(ll i,ll j)//�ϲ�i,j�������鼯 
{
    i=gf(i);
    j=gf(j);
    if(i==j)return ;
    if(d[i]>d[j])prt[j]=i;
    else
    {
        if(d[i]==d[j])d[j]++;  
        prt[i]=j;
    }
}
