1.for(auto iter:vec)不改变迭代对象的值，for(auto &iter:vec)可以改变迭代对象的值。
两者都可以获取到迭代容器中的值，但是使用auto iter时不会对容器对象造成改变，

而使用auto &iter,对于iter的任何修改将直接修改容器内对应的值。

void printVec(vector<int>& vec) {//这里也是,加了&就可以对vector元素进行修改,反之就是值传递,不能进行修改 
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}
int main() {
	vector<int>vec = {4,3,2,1,0 };
	cout<<"***************第一种*************"<<endl;
    //这个时候每个取出来的iter只是原来vec元素的副本，不会改变vec中任何元素
	for (auto iter : vec) {
		iter = iter + 100;
	}
	printVec(vec);
 
	cout<<"***************第二种*************"<<endl;
    //这个时候取出来的是 &iter，代表原来vec中元素的引用，如果对iter进行任何改变都会作用在vec上
	for (auto& iter : vec) {
		iter = iter + 100;
	}
	printVec(vec);
}
输出的结果如下：
***************第一种*************
4
3
2
1
0
***************第二种*************
104
103
102
101
100
