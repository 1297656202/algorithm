拓扑排序可以用来解决n个元素，m对关系，每对关系要求x元素比y元素大的题目
如果要求x元素比y元素具体大多少，并且要求是否可行或者具体元素值，则需要用到差分约束系统 
priority_queue<ll,vector<ll>,greater<ll> >p;//小根堆
用堆维护入度为0的最小值，以方便以字典序输出拓扑排序
如果不要求字典序，则可以直接用队列就好
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

当然还有一种dfs写法,不过我有点没印象() 

拓扑排序能遍历完的图为有向无环图,也就是拓扑图
所以也可以通过是否能拓扑排序完来检验有向图是否有环 
