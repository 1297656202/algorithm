#include <deque>
1.定义
a) deque<int>s1;  
b) deque<string>s2; 
c) deque<node>s3; /*node为结构体，可自行定义。*/
2.常见操作 
//a) 构造函数
deque<int>?ideq
//b)增加函数
 ideq.push_front(x):双端队列头部增加一个元素X
 ideq.push_back(x):双端队列尾部增加一个元素x
//c)删除函数
ideq.pop_front():删除双端队列中最前一个元素
ideq.pop_back():删除双端队列中最后一个元素
ideq.clear():清空双端队列中元素
//d)判断函数
ideq.empty() :向量是否为空，若true,则向量中无元素
//e)大小函数
ideq.size():返回向量中元素的个数
