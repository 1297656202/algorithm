#include <deque>
1.����
a) deque<int>s1;  
b) deque<string>s2; 
c) deque<node>s3; /*nodeΪ�ṹ�壬�����ж��塣*/
2.�������� 
//a) ���캯��
deque<int>?ideq
//b)���Ӻ���
 ideq.push_front(x):˫�˶���ͷ������һ��Ԫ��X
 ideq.push_back(x):˫�˶���β������һ��Ԫ��x
//c)ɾ������
ideq.pop_front():ɾ��˫�˶�������ǰһ��Ԫ��
ideq.pop_back():ɾ��˫�˶��������һ��Ԫ��
ideq.clear():���˫�˶�����Ԫ��
//d)�жϺ���
ideq.empty() :�����Ƿ�Ϊ�գ���true,����������Ԫ��
//e)��С����
ideq.size():����������Ԫ�صĸ���
