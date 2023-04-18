next_permutation 下一个排列
把两个迭代器（或指针）指定的部分看作一个排列，求出这些元素构成的全排列中，字典序排在下一个的排列，
并直接在序列上更新。另外，若不存在排名更靠后的排列，则返回0，否则返回1 
同理，也有prev_permutaion函数
下面程序按照字典序输出1~n的n!种全排列：
for(i=1;i<=n;i++)a[i]=i;
do{
	for(i=1;i<n;i++)cout<<a[i]<<' ';
	cout<<a[n]<<endl;
}while(next_permutation(a+1,a+n+1));
