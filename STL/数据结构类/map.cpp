map是STL的一个关联容器，它提供一对一的hash。
map的内部实现是二叉平衡树(红黑树)，所以插入和删除之类的操作都是O(log(n))

第一个可以称为关键字(key)，每个关键字只能在map中出现一次；
第二个可能称为该关键字的值(value);
map容器提供了key-value的映射。其内部是以key为关键码的红黑树。
key和value可以是任何类型，其中key必须定义小于运算符
声明：
map<key_type,value_type>mp;
map<ll,bool>vis;
map<string,ll>h;
map<pair<ll,ll>,vector<ll> >test;

size()          返回map中元素的个数
empty()         如果map为空则返回true
clear()         删除所有元素

begin()         返回指向map头部的迭代器
end()          	返回指向map末尾的往后一个的迭代器
遍历方法：和set一样，也是双向访问迭代器，
重点：*it将得到一个二元组pair<key_type,value_type> 
map<ll,ll>mp;
map<ll,ll>::iterator it;
for(it=mp.begin();it!=mp.end();it++)
	cout<<i->first<<' '<<i->second<<endl;

insert()         插入元素pair<key_type,value_type>
make_pair(x,y)函数可以返回一个pair类型的元素 
erase()          删除一个元素，可以删除pair，也可以删除it迭代器 

find(x)          查找一个key为x的pair二元组，并且返回指向这个二元组的迭代器，
如果不存在，返回mp.end()。时间负杂度为O(log(n)) 

[]操作符
h[key]返回key映射到的value的引用，时间复杂度为O(log(n))
这是map函数最重要的东西，我们可以通过h[key]来得到key对应的value，
还可以对h[key]进行赋值操作，改变key对应的value 
值得注意的是，如果key并不存在，则执行h[key]后会创建一个二元组(key,zero),
并返回zero，这个zero为广义0，比如整数0，空字符串等
这样的话，我们可以直接h[str]++来统计string出现的次数
重点：如果查找以后不对h[key]赋值的话，时间一长，h会包含很多无用的零值二元组，
从而占用空间和时间，所以在用[]查询之前，可以用find检查其是否存在 

下面是一些不常见的操作： 
count()          	返回指定元素出现的次数
equal_range()       返回特殊条目的迭代器对
get_allocator()     返回map的配置器
key_comp()          返回比较元素key的函数
lower_bound()      	返回key值>=给定元素的第一个位置
upper_bound()     	返回key值>给定元素的第一个位置
max_size()          返回可以容纳的最大元素个数
rbegin()          	返回一个指向map尾部的逆向迭代器
rend()          	返回一个指向map头部的逆向迭代器
swap()          	交换两个map
value_comp()        返回比较元素value的函数
以上内容在算法竞赛上有讲解
