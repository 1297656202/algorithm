一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

其左子树中所有结点的键值小于该结点的键值；
其右子树中所有结点的键值大于等于该结点的键值；
其左右子树都是二叉搜索树。
所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。
如果是的话，在下一行输出该树后序遍历的结果

其原理很简单，就是一个分治的过程，当dfs(l,r)时，a[l]为这一点二叉树的根节点
则(l+1,r)这个区间，前面有一段所有的键值都小于a[l]的，就为其左子树，
相反后面有一段键值都大于等于a[l]的，就为其右子树，然后递归处理就好了

中序遍历，后序遍历转换为其他遍历的原理大致更上面相同 
 
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll a[mn],ans,n,m;
vector<ll>v;
ll bj=0;
void dfs(ll l,ll r)
{
	if(l>r)return ;
	ll i=l+1,j=r;
//    if(bj==0)
//	{
        while(i<=r&&a[l]>a[i])i++;
        while(j>l&&a[l]<=a[j])j--;
//    }
//	else//这一段是判断是否为镜像的前序遍历，一般要删掉 
//	{
//        while(i<=r&&a[l]<=a[i])i++;
//        while(j>l&&a[l]>a[j])j--;
//    }
    if(i-j!=1)return ;
    dfs(l+1,j);
    dfs(i,r);
    v.push_back(a[l]);//这是转变为后序遍历的做法，如果转为中序遍历，就将这一行放在两个dfs的中间 
}
int main()
{
	ll x,y,z,i,j,k;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,n);
//	if(v.size()!=n)//这一段是判断是否为镜像的前序遍历，一般要删掉 
//	{
//		bj=1;
//		v.clear();
//		dfs(1,n);
//	}
	if(v.size()==n)
	{
        printf("YES\n%lld",v[0]);
        for(i=1;i<n;i++)
            printf(" %lld",v[i]);
    }
	else printf("NO");
	return 0;
}
