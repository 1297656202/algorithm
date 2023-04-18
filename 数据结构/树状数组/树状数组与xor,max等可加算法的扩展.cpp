然后，树状数组对于很多满足可累积性质的算法都适用，只是需要魔改一下就行，比如说求max和xor值
 
有一个初始为空的序列。维护三种命令：
p1.ADD x：把x加到数列最后；
p2.REMOVE x：在数列中找到等于x的数，删除
p3.XOR between x1 and x2：对于数列中所有值在[x1,x2]中的数异或并
输出结果；
n 加入的数都不超过20000，询问次数<=60000 

对于Remove操作，我们其实可以将其视为Add操作。因为a xor a=0；a xor 0=a，所以Remove(X)相当于add(X)
然后，就把树状数组的代码直接套上去，只是把+改成xor就行

下面是魔改max的算法 
void add(ll x,ll z)
{ll i;
	for(i=x;i<=k;i+=low(i))
            c[i]=max(z,c[i]); 
}
ll ask(ll x)
{ll i,ans=0;
	for(i=x;i>0;i-=low(i))
	         ans=max(c[i],ans);
	return ans;
}
