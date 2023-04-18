下面这个是比较常用的，也就是传值 
vector<ll> f(vector<ll> t,ll x,ll y,ll k)
{
    vector<ll>res;
    ..........
    return res;
}

vector<int>* p=new vector<int>{ 1,2,3 };

C++中vector作为参数的三种传参方式（传值传引用传指针)
functionl(vector vec)传值
function2(vector &vec)传引用
function3(vector *vec)传指针
注意，三种方式分别有对应的const形式,不在此讨论。三种方式对应的调用形式分别为:
function1(vec)传入值
function2(vec)传入引用
function3(&vec)传入地址
三种方式的效果分别为:
会发生拷贝构造
不会发生拷贝构造
不会发生拷贝构造 

引用传递
void func1(vector<int> &q){}
int main(){
vector<int> q;
func1(q);
}
指针传递
void func1(vector<int> *q){}
int main(){
vector<int> q;
func1(&q);
}
