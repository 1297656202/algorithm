bitset��ž���������bool����һ���Ķ���
��������ÿ��λ��ֻռ1bit���ر��ر�С������boolҪռһ��Byte 
bitset��ԭ�����ǽ��ܶ���ѹ��һ�����Ӷ���ʡ�ռ��ʱ�䣨�������漣��
һ����˵bitset��������㷨���Ӷ� /32��������ʲôҪ���������

ʹ��bitset������#include<bitset>
bitset�����ڶ���ʱ����Ҫָ����ռ�Ŀռ䣬����
bitset<233>bit;

bitset���Ϳ�����string��������ʼ��������ת���ɶ�Ӧ�Ķ�����
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
bitset֧������λ����
����һ������bit��bitset��
bit.size()       ���ش�С��λ����
bit.count()     ����1�ĸ���
bit.any()       �����Ƿ���1
bit.none()      �����Ƿ�û��1
bit.set()       ȫ�����1
bit.set(p)      ����p + 1λ���1��bitset�Ǵӵ�0λ��ʼ�ģ��� 
bit.set(p, x)   ����p + 1λ���x
bit.reset()     ȫ�����0
bit.reset(p)    ����p + 1λ���0
bit.flip()      ȫ��ȡ��
bit.flip(p)     ����p + 1λȡ��
bit.to_ulong()  ������ת��Ϊunsigned long�Ľ�������������Χ�򱨴�
bit.to_ullong() ������ת��Ϊunsigned long long�Ľ�������������Χ�򱨴�
bit.to_string() ������ת��Ϊstring�Ľ��

�ܽ᣺���������ʵͦʵ�õ�
�����Ż�ʱ�䣺һ�������Ż���ż���йص����⣬����ά����ͨ��֮��ģ�
����ʱ����Ŀ�Ĺ�ͬ�ص��������㷨��������ֵֻ��0��1��dp���ܶ�ʱ��ֻ��Ҫ�жϿ����Լ��ɣ�
Ȼ��Ϳ�����bitset���㷨���Ӷ�/32
 
�����Ż��ռ䣺Ȼ�����Ҫ�ľ������һ��ֻ��Ҫbool������Ŀռ䳬�ˣ���ҪΪbj���飩��������bitset�����ٿռ�ռ�ã�
��Ϊboolռһ��byte����bitsetһ��λֻռһ��bit
