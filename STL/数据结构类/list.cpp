#include<list>
����һ��int�͵�list��list<int> a��

Ԫ�صı����� 
for (list<int>::iterator it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
		
for (list<int>::reverse_iterator it=l.rbegin();it!=l.rend();it++)
		cout<<*it<<" ";
itֻ�ܽ���it++��++it������it--��--it������������+x���ֲ�������Ϊ���ڲ���Ԫ�ص���ɢ���õģ�
������vector��������˳����ʣ�ֻ�ܷ��ʺ�һ����++������ǰһ����--�� 

1��list�Ĺ��캯��
list<int>a{1,2,3}
list<int>a(n)    //����һ��n��Ԫ�ص��б�ÿ��Ԫ�ض���0
list<int>a(n, m)  //����һ��n��Ԫ�ص��б�ÿ��Ԫ�ض���m
list<int>a(first, last)  //����һ���б���Ԫ�صĳ�ʼֵ��Դ����������ָ���������е�Ԫ�أ�first��last�ǵ�����

2��begin()��end()
ͨ������list�����ĳ�Ա����begin()�õ�һ��ָ��������ʼλ�õ�iterator��
���Ե���list������end()�������õ�listĩ����һλ��

3��push_back()��push_front()
ʹ��list�ĳ�Ա����push_back��push_front����һ��Ԫ�ص�list�С�����push_back()�Ǵ�list��ĩ�˲��룬
��push_front()�Ǵ�list��ͷ�����롣

4��empty()
�ж�list�Ƿ�Ϊ��

5��resize()
����resize(n)��list�ĳ��ȸ�Ϊֻ����n��Ԫ�أ�������Ԫ�ؽ���ɾ�������n��listԭ���ĳ��ȳ���
��ôĬ�ϳ����Ĳ���Ԫ����Ϊ0��Ҳ������resize(n, m)�ķ�ʽ�������Ĳ��ָ�ֵΪm��
���ӣ�
list<int>b{1, 2, 3, 4};
b.resize(2);
list�����Ԫ�أ�1,2
list<int>b{1, 2, 3, 4};
b.resize(6);
list�����Ԫ�أ�1,2,3,4,0,0
list<int>b{1, 2, 3, 4};
b.resize(6,9);
list�����Ԫ�أ�1,2,3,4,9,9

6��clear()
���list�е�����Ԫ��

7��front()��back()
ͨ��front()���Ի��list�����е�ͷ��Ԫ�أ�ͨ��back()���Ի��list���������һ��Ԫ�ء�
ע�⣺��listԪ��Ϊ��ʱ����ʱ�����front()��back()���ᱨ������ڱ�д����ʱ��
����ȵ���empty()�����ж�list�Ƿ�Ϊ�գ��ٵ���front()��back()������

8��pop_back()��pop_front()
ʹ��pop_back()����ɾ��β����һ��Ԫ�أ�pop_front()����ɾ��ͷ����һ��Ԫ�ء�ע�⣺list���벻Ϊ�գ�
�����listΪ�յ�ʱ�����pop_back()��pop_front()��ʹ���������

9��assign()
������ʹ�������
��1��a.assign(n, val):��a�е�����Ԫ���滻��n��valԪ��
���磺
list<int>b{1,2,3,4,5};
b.assign(5,10);
b�е�Ԫ�ر�Ϊ10, 10, 10, 10, 10
��2��a.assign(b.begin(), b.end())
list<int>a{6,7,8,9};
list<int>b{1,2,3,4,5};
b.assign(a.begin(),a.end());
b�е�Ԫ�ر�Ϊ6,7,8,9

10��swap()
������������a.swap(b)��swap(a, b)�����������a�����b����Ľ�����
���ӣ�
list<int>a{6,7,8,9};
list<int>b{1,2,3,4,5};
swap(a, b);  //��a.swap(b)
a��Ԫ�ر�Ϊ1,2,3,4,5
b��Ԫ�ر�Ϊ6,7,8,9

11��reverse()
����ʵ��list������
���ӣ�
list<int>b{1,2,3,4,5};
reverse(b.begin(),b.end());
b��Ԫ�ر�Ϊ5��4��3��2��1

12��merge()
a.merge(b) ���ý�����b��Ϊ�գ�a��Ԫ�ذ���ԭ��a��b��Ԫ�ء�
���ӣ�
list<int>a{6,7,8,9};
list<int>b{2, 1, 3, 6, 5};
a.merge(b,greater<int>());
a��Ԫ�ر�Ϊ��6,7,8,9,2,1,3,6,5
list<int>a{6,7,8,9};
list<int>b{2, 1, 3, 6, 5};
a.merge(b);
a��Ԫ�ر�Ϊ��2,1,3,6,5,6,7,8,9

13��insert()
��ָ��λ�ò���һ������Ԫ��
a.insert(a.begin(),100);  //��a�Ŀ�ʼλ�ã���ͷ��������100
a.insert(a.begin(),2, 100);   //��a�Ŀ�ʼλ�ò���2��100
a.insert(a.begin(),b.begin(), b.end());//��a�Ŀ�ʼλ�ò���b�ӿ�ʼ������������λ�õ�Ԫ��

14��erase()//
ɾ��һ��Ԫ�ػ�һ�������Ԫ��
a.erase(a.begin());  //��a�ĵ�һ��Ԫ��ɾ��
a.erase(a.begin(),a.end());  //��a�Ĵ�begin()��end()֮���Ԫ��ɾ����

15��remove()����
��list��ɾ��Ԫ��
list<int>a{6,7,8,9,7,10};
a.remove(7);
ɾ����a������ֵΪ7��Ԫ�أ���ʱa��Ԫ��Ϊ6,8,9,10
