new其实就是告诉计算机开辟一段新的空间，但是和一般的声明不同的是，
new开辟的空间在堆上，而一般声明的变量存放在栈上。
通常来说，当在局部函数中new出一段新的空间，
该段空间在局部函数调用结束后仍然能够使用，可以用来向主函数传递参数。
另外需要注意的是，new的使用格式，new出来的是一段空间的首地址。
所以一般需要用指针来存放这段地址。具体的代码如下：

#include <iostream>
using namespace std;
int example1()
{
  //可以在new后面直接赋值
  int *p = new int(3);
  //也可以单独赋值
  //*p = 3;
 
  //如果不想使用指针，可以定义一个变量，在new之前用"*"表示new出来的内容
  int q = *new int;
  q = 1;
  cout << q << endl;
 
  return *p;
}
int* example2()
{
  //当new一个数组时，同样用一个指针接住数组的首地址
  int *q = new int[3];
  for(int i=0; i<3; i++)
    q[i] = i;
 
  return q;
}
struct student
{
  string name;
  int score;
};
student* example3()
{
  //这里是用一个结构体指针接住结构体数组的首地址
  //对于结构体指针，个人认为目前这种赋值方法比较方便
  student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
 
  return stlist;
}
int main()
{
  int e1 = example1();
  cout <<"e1: "<< e1 << endl;
 
  int *e2 = example2();
  for(int i=0; i<3; i++)
    cout << e2[i] << " ";
  cout << endl;

  student *st1 = example3();
 
  for(int i=0; i<3; i++)
    cout << st1[i].name << " " << st1[i].score << endl;
  return 0;
}

