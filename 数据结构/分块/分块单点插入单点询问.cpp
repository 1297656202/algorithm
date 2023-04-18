给出一个长为n的数列，以及n个操作，操作涉及单点插入（某位置插入某数），单点询问（某位置的数是多少），数据随机

先说随机数据的情况
之前提到过，如果我们块内用数组以外的数据结构，能够支持其它不一样的操作，
如果整个数组都是vector的话，插入是O(n)的，非常影响效率 
我们运用分块，每块内可以放一个动态的数组vector，每次插入时先找到位置所在的块，再暴力插入，
把块内的其它元素直接向后移动一位，当然用链表也是可以的，就变成了O（1）插入，O（√n） 查询 
查询的时候类似，复杂度分析略。

但是这样做有个问题，如果数据不随机怎么办？
如果先在一个块有大量单点插入，这个块的大小会大大超过√n，那块内的暴力就没有复杂度保证了。
还需要引入一个操作：重新分块（重构）
每根号n次插入后，重新把数列平均分一下块，重构需要的复杂度为O(n)，重构的次数为√n，
所以重构的复杂度没有问题，而且保证了每个块的大小相对均衡。
当然，也可以当某个块过大时重构，或者只把这个块分成两半。
