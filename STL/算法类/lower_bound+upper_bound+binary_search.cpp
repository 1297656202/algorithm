lower_bound/upper_bound 二分
lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
upper_bound()--返回大于某个值的第一个元素的迭代器
当然，两个迭代器（指针）之间的部分应该是提前排好序的
在数组（元素在1~n中）中查找>=x的最小整数的下标 
ll i=lower_bound(a+1,a+n+1,x)-a; 
在vector中查找小于等于x的最大整数（假设一定存在）
ll y=*--upper_bound(a.begin(),a.end(),x); 

binary_search() 二分
它会在前两个参数指定范围内搜索等同于第三个参数的元素。
如果找到第三个参数，会返回布尔值 true，否则返回 false。 
binary_search(a.begin(),a.end(),x)
