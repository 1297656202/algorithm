//按秩合并简单来说就是尽量把一个树的中心取出来，使得各个点到根节点的路径尽量短
/*   0	   			
  0  0 肯定比一条链更好 
 0    0 */		
#define mn 100//char或者别的格式皆可，看元素是什么格式
ll prt[mn];
ll d[mn];//d[i]表示每个并查集的最大深度 
ll st(ll i)//代表第i个元素需要初始化
{
	prt[i]=i;
	d[i]=0;
}
void Union(ll i,ll j)//合并i,j两个并查集 
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
