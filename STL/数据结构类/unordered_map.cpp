unordered_map和map的区别 
unordered_map存储机制是哈希表，是通过某种算法将key转化为了一个hash值，然后直接通过hash值访问value 
这样的话unordered_map内部元素是无序的，遍历也会得到无序遍历 
map是红黑树，map中的元素是按照二叉搜索树存储，进行中序遍历会得到有序遍历。
哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而空间复杂度会高一点。
所以对于需要高效率查询的情况，使用unordered_map容器。
而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用map容器。

map支持的操作， unordered_map也基本支持，
直接将前面map的操作拿过来用就行了 

遍历方法：双向访问迭代器
重点：*it将得到一个二元组pair<key_type,value_type> 
unordered_map<ll,ll>mp;
unordered_map<ll,ll>::iterator it;
for (it=mp.begin();it!=mp.end();it++){
    cout<<i->first<<' '<<i->second<<endl;
这样遍历得到的元素是完全无序的 
