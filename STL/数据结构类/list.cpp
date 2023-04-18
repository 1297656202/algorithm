#include<list>
声明一个int型的list：list<int> a；

元素的遍历： 
for (list<int>::iterator it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
		
for (list<int>::reverse_iterator it=l.rbegin();it!=l.rend();it++)
		cout<<*it<<" ";
it只能进行it++（++it）或者it--（--it）操作，不能+x这种操作，因为其内部的元素的零散放置的，
不能像vector那样进行顺序访问，只能访问后一个（++）或者前一个（--） 

1、list的构造函数
list<int>a{1,2,3}
list<int>a(n)    //声明一个n个元素的列表，每个元素都是0
list<int>a(n, m)  //声明一个n个元素的列表，每个元素都是m
list<int>a(first, last)  //声明一个列表，其元素的初始值来源于由区间所指定的序列中的元素，first和last是迭代器

2、begin()和end()
通过调用list容器的成员函数begin()得到一个指向容器起始位置的iterator，
可以调用list容器的end()函数来得到list末端下一位置

3、push_back()和push_front()
使用list的成员函数push_back和push_front插入一个元素到list中。其中push_back()是从list的末端插入，
而push_front()是从list的头部插入。

4、empty()
判断list是否为空

5、resize()
调用resize(n)将list的长度改为只容纳n个元素，超出的元素将被删除。如果n比list原来的长度长，
那么默认超出的部分元素置为0。也可以用resize(n, m)的方式将超出的部分赋值为m。
例子：
list<int>b{1, 2, 3, 4};
b.resize(2);
list中输出元素：1,2
list<int>b{1, 2, 3, 4};
b.resize(6);
list中输出元素：1,2,3,4,0,0
list<int>b{1, 2, 3, 4};
b.resize(6,9);
list中输出元素：1,2,3,4,9,9

6、clear()
清空list中的所有元素

7、front()和back()
通过front()可以获得list容器中的头部元素，通过back()可以获得list容器的最后一个元素。
注意：当list元素为空时，这时候调用front()和back()不会报错。因此在编写程序时，
最好先调用empty()函数判断list是否为空，再调用front()和back()函数。

8、pop_back()和pop_front()
使用pop_back()可以删掉尾部第一个元素，pop_front()可以删掉头部第一个元素。注意：list必须不为空，
如果当list为空的时候调用pop_back()和pop_front()会使程序崩掉。

9、assign()
有两种使用情况：
（1）a.assign(n, val):将a中的所有元素替换成n个val元素
例如：
list<int>b{1,2,3,4,5};
b.assign(5,10);
b中的元素变为10, 10, 10, 10, 10
（2）a.assign(b.begin(), b.end())
list<int>a{6,7,8,9};
list<int>b{1,2,3,4,5};
b.assign(a.begin(),a.end());
b中的元素变为6,7,8,9

10、swap()
交换两个链表。a.swap(b)和swap(a, b)，都可以完成a链表和b链表的交换。
例子：
list<int>a{6,7,8,9};
list<int>b{1,2,3,4,5};
swap(a, b);  //或a.swap(b)
a中元素变为1,2,3,4,5
b中元素变为6,7,8,9

11、reverse()
可以实现list的逆置
例子：
list<int>b{1,2,3,4,5};
reverse(b.begin(),b.end());
b中元素变为5，4，3，2，1

12、merge()
a.merge(b) 调用结束后b变为空，a中元素包含原来a和b的元素。
例子：
list<int>a{6,7,8,9};
list<int>b{2, 1, 3, 6, 5};
a.merge(b,greater<int>());
a中元素变为：6,7,8,9,2,1,3,6,5
list<int>a{6,7,8,9};
list<int>b{2, 1, 3, 6, 5};
a.merge(b);
a中元素变为：2,1,3,6,5,6,7,8,9

13、insert()
在指定位置插入一个或多个元素
a.insert(a.begin(),100);  //在a的开始位置（即头部）插入100
a.insert(a.begin(),2, 100);   //在a的开始位置插入2个100
a.insert(a.begin(),b.begin(), b.end());//在a的开始位置插入b从开始到结束的所有位置的元素

14、erase()//
删除一个元素或一个区域的元素
a.erase(a.begin());  //将a的第一个元素删除
a.erase(a.begin(),a.end());  //将a的从begin()到end()之间的元素删除。

15、remove()函数
从list中删除元素
list<int>a{6,7,8,9,7,10};
a.remove(7);
删除了a中所有值为7的元素，此时a中元素为6,8,9,10
