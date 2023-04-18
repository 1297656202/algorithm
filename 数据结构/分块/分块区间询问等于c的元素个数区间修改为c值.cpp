给出一个长为n的数列，以及n个操作，操作涉及区间询问等于一个数c的元素，并将这个区间的所有元素改为c。

区间修改没有什么难度，这题难在区间查询比较奇怪，因为权值种类比较多，似乎没有什么好的维护方法。
模拟一些数据可以发现，询问后一整段都会被修改，几次询问后数列可能只剩下几段不同的区间了。
我们思考这样一个暴力，还是分块，维护每个分块是否只有一种权值，区间操作的时候，对于同权值的一个块就O(1)统计答案，
否则暴力统计答案，并修改标记，不完整的块也暴力。

这样看似最差情况每次都会耗费O(n)的时间，但其实可以这样分析：
假设初始序列都是同一个值，那么查询是O(√n)，如果这时进行一个区间操作，它最多破坏首尾2个块的标记，
所以只能使后面的询问至多多2个块的暴力时间，所以均摊每次操作复杂度还是O(√n)。
换句话说，要想让一个操作耗费O(n)的时间，要先花费√n个操作对数列进行修改。
初始序列不同值，经过类似分析后，就可以放心的暴力啦。
