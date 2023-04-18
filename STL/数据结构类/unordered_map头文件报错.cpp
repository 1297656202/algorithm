如果unordered_map头文件报错，在本地运行的时候加上这个就可以了，对unordered_set一样有用 
在上交代码的时候再把这两行删除即可 
#include<tr1/unordered_map>
using namespace std::tr1;

第二种方法是对编译选项进行修改，
在工具 》编译选项 》编译时加入以下命令 添加 -std=c++11
