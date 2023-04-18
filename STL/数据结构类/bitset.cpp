bitset大概就是类似于bool数组一样的东西
但是它的每个位置只占1bit（特别特别小），而bool要占一个Byte 
bitset的原理大概是将很多数压成一个，从而节省空间和时间（暴力出奇迹）
一般来说bitset会让你的算法复杂度 /32（具体是什么要看计算机）

使用bitset类型需#include<bitset>
bitset类型在定义时就需要指定所占的空间，例如
bitset<233>bit;

bitset类型可以用string和整数初始化（整数转化成对应的二进制
#include<iostream>
#include<bitset>
#include<cstring>
using namespace std;
int main()
{
    bitset<23>bit (string("11101001"));
    cout<<bit<<endl;
    bit=233;
    cout<<bit<<endl;
    return 0;
}
bitset支持所有位运算
对于一个叫做bit的bitset：
bit.size()       返回大小（位数）
bit.count()     返回1的个数
bit.any()       返回是否有1
bit.none()      返回是否没有1
bit.set()       全都变成1
bit.set(p)      将第p + 1位变成1（bitset是从第0位开始的！） 
bit.set(p, x)   将第p + 1位变成x
bit.reset()     全都变成0
bit.reset(p)    将第p + 1位变成0
bit.flip()      全都取反
bit.flip(p)     将第p + 1位取反
bit.to_ulong()  返回它转换为unsigned long的结果，如果超出范围则报错
bit.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
bit.to_string() 返回它转换为string的结果

总结：这玩意儿其实挺实用的
对于优化时间：一般用来优化奇偶性有关的问题，或者维护联通性之类的，
这种时间题目的共同特点是朴素算法往往是数值只有0和1的dp，很多时候只需要判断可行性即可，
然后就可以用bitset将算法复杂度/32
 
对于优化空间：然后很重要的就是如果一个只需要bool的数组的空间超了（主要为bj数组），可以用bitset来减少空间占用，
因为bool占一个byte，而bitset一个位只占一个bit
