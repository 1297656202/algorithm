c++ stl集合(Set)：
是一种包含已排序对象的关联容器。set/multiset会根据待定的排序准则，
自动将元素排序。两者不同在于前者不允许元素重复，而后者允许。
1 不能直接改变元素值，因为那样会打乱原本正确的顺序，要改变元素值必须先删除旧元素，则插入新元素
2 不提供直接存取元素的任何操作函数，只能通过迭代器进行间接存取，而且从迭代器角度来看，元素值是常数
3 元素比较动作只能用于型别相同的容器(即元素和排序准则必须相同)
声明： set<ll>s;
struct w{};
set<w>s;
multiset<double>s;
重点：存储在set/multiset中的元素必须定义小于这个运算符 

empty()--如果集合为空，返回true
size()--集合中元素的数目
clear()--清除所有元素

begin()--返回指向第一个元素的迭代器
end()--返回指向最后一个元素的下一个位置的迭代器，整个容器是一个前闭后开的形式 
所以，--s.end()才是指向集合中最后一个元素的迭代器
遍历元素示例：
set<int>::iterator it; //定义前向迭代器  
//中序遍历集合中的所有元素  
for(it=s.begin();it!=s.end();it++)  
{
	cout<<*it<<" ";
}

insert(x)--在集合中插入元素x，时间复杂度是O(log(n))
在set中，如果元素已经存在，则不会重复插入该元素 

find(x)--返回一个指向被查找到的元素x的迭代器，若不存在，则返回s.end()，复杂度为O(log(n)) 

lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
upper_bound()--返回大于某个值元素的迭代器，时间复杂度都是O(log(n)) 

erase()--删除集合中的元素
erase(it)可以删除it指向的元素，时间复杂度是O(log(n)) 
erase(x)可以删除所有等于x的元素，时间复杂度是O(log(n)+k)，k为等于x的元素个数 
如果只想在multiset中删除至多一个等于x的元素，可以：
if(it=s.find(x)!=s.end())s.erase(it); 

count(x)--返回集合中等于x的元素的个数， 时间复杂度是O(log(n)+k)，k为等于x的元素个数 

一下是一些不常用的： 
equal_range()--返回集合中与给定值相等的上下限的两个迭代器
get_allocator()--返回集合的分配器
key_comp()--返回一个用于元素间值比较的函数
max_size()--返回集合能容纳的元素的最大限值
rbegin()--返回指向集合中最后一个元素的反向迭代器
rend()--返回指向集合中第一个元素的反向迭代器
swap()--交换两个集合变量
value_comp()--返回一个用于比较元素间的值的函数
以上内容在算法竞赛上有讲解 
