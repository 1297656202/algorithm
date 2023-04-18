sort 快速排序
对两个迭代器（或指针）指定的部分进行快速排序。
可以在第三个参数传入定义大小比较的函数，或者重载小于号
对下标在1~n的数组进行排序 
bool cmp(ll a,ll b){return a>b;}
sort(a+1,a+n+1,cmp);
对装结构体的vector排序，重载小于号
struct w{ll id,x,y;};
vector<w>a;
bool operator <(const w&a,const w&b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
sort(a.begin(),a.end());
