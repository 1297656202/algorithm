������������������n��Ԫ�أ�m�Թ�ϵ��ÿ�Թ�ϵҪ��xԪ�ر�yԪ�ش����Ŀ
���Ҫ��xԪ�ر�yԪ�ؾ������٣�����Ҫ���Ƿ���л��߾���Ԫ��ֵ������Ҫ�õ����Լ��ϵͳ 
priority_queue<ll,vector<ll>,greater<ll> >p;//С����
�ö�ά�����Ϊ0����Сֵ���Է������ֵ��������������
�����Ҫ���ֵ��������ֱ���ö��оͺ�
queue<ll>q; 
for(i=1;i<=n;i++)
	if(rd[i]==0)q.push(i);
while(!q.empty())
{ 
	x=q.top();
	q.pop();
	ans[++cnt]=x;
	for(i=h[x];i;i=a[i].next)
	{
		y=a[i].to;
		rd[y]--;
		if(rd[y]==0)q.push(y);
	}
}
if(cnt!=n)printf("NO SOLUTION");
else for(i=1;i<=n;i++)
printf("%lld ",ans[i]);
