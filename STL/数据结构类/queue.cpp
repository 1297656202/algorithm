queue<string>words;
queue<string>copy_words{words}; // A duplicate of words
front():返回queue 中第一个元素的引用。如果queue是常量，就返回一个常引用;如果queue为空，返回值是未定义的
back():返回queue中最后一个元素的引用。如果queue是常量，就返回一个常引用;如果queue为空，返回值是未定义的
push(const T& obi):在queue的尾部添加一个元素的副本。这是通过调用底层容器的成员函数push_ back()来完成的
push(T&& obj):以移动的方式在queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数push_ back()来完成的
pop():删除queue 中的第一个元素
size():返回queue 中元素的个数。
empty():如果queue中没有元素的话，返回true。
emplace():用传给emplace()的参数调用Ⅰ的构造函数，在queue的尾部生成对象。
swap(queue<T> &other q):将当前queue 中的元素和参数queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板swap)来完成同样的操作。T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
