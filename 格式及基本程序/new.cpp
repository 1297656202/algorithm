new��ʵ���Ǹ��߼��������һ���µĿռ䣬���Ǻ�һ���������ͬ���ǣ�
new���ٵĿռ��ڶ��ϣ���һ�������ı��������ջ�ϡ�
ͨ����˵�����ھֲ�������new��һ���µĿռ䣬
�öοռ��ھֲ��������ý�������Ȼ�ܹ�ʹ�ã��������������������ݲ�����
������Ҫע����ǣ�new��ʹ�ø�ʽ��new��������һ�οռ���׵�ַ��
����һ����Ҫ��ָ���������ε�ַ������Ĵ������£�

#include <iostream>
using namespace std;
int example1()
{
  //������new����ֱ�Ӹ�ֵ
  int *p = new int(3);
  //Ҳ���Ե�����ֵ
  //*p = 3;
 
  //�������ʹ��ָ�룬���Զ���һ����������new֮ǰ��"*"��ʾnew����������
  int q = *new int;
  q = 1;
  cout << q << endl;
 
  return *p;
}
int* example2()
{
  //��newһ������ʱ��ͬ����һ��ָ���ס������׵�ַ
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
  //��������һ���ṹ��ָ���ס�ṹ��������׵�ַ
  //���ڽṹ��ָ�룬������ΪĿǰ���ָ�ֵ�����ȽϷ���
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

