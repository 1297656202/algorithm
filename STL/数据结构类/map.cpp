map��STL��һ���������������ṩһ��һ��hash��
map���ڲ�ʵ���Ƕ���ƽ����(�����)�����Բ����ɾ��֮��Ĳ�������O(log(n))

��һ�����Գ�Ϊ�ؼ���(key)��ÿ���ؼ���ֻ����map�г���һ�Σ�
�ڶ������ܳ�Ϊ�ùؼ��ֵ�ֵ(value);
map�����ṩ��key-value��ӳ�䡣���ڲ�����keyΪ�ؼ���ĺ������
key��value�������κ����ͣ�����key���붨��С�������
������
map<key_type,value_type>mp;
map<ll,bool>vis;
map<string,ll>h;
map<pair<ll,ll>,vector<ll> >test;

size()          ����map��Ԫ�صĸ���
empty()         ���mapΪ���򷵻�true
clear()         ɾ������Ԫ��

begin()         ����ָ��mapͷ���ĵ�����
end()          	����ָ��mapĩβ������һ���ĵ�����
������������setһ����Ҳ��˫����ʵ�������
�ص㣺*it���õ�һ����Ԫ��pair<key_type,value_type> 
map<ll,ll>mp;
map<ll,ll>::iterator it;
for(it=mp.begin();it!=mp.end();it++)
	cout<<i->first<<' '<<i->second<<endl;

insert()         ����Ԫ��pair<key_type,value_type>
make_pair(x,y)�������Է���һ��pair���͵�Ԫ�� 
erase()          ɾ��һ��Ԫ�أ�����ɾ��pair��Ҳ����ɾ��it������ 

find(x)          ����һ��keyΪx��pair��Ԫ�飬���ҷ���ָ�������Ԫ��ĵ�������
��������ڣ�����mp.end()��ʱ�为�Ӷ�ΪO(log(n)) 

[]������
h[key]����keyӳ�䵽��value�����ã�ʱ�临�Ӷ�ΪO(log(n))
����map��������Ҫ�Ķ��������ǿ���ͨ��h[key]���õ�key��Ӧ��value��
�����Զ�h[key]���и�ֵ�������ı�key��Ӧ��value 
ֵ��ע����ǣ����key�������ڣ���ִ��h[key]��ᴴ��һ����Ԫ��(key,zero),
������zero�����zeroΪ����0����������0�����ַ�����
�����Ļ������ǿ���ֱ��h[str]++��ͳ��string���ֵĴ���
�ص㣺��������Ժ󲻶�h[key]��ֵ�Ļ���ʱ��һ����h������ܶ����õ���ֵ��Ԫ�飬
�Ӷ�ռ�ÿռ��ʱ�䣬��������[]��ѯ֮ǰ��������find������Ƿ���� 

������һЩ�������Ĳ����� 
count()          	����ָ��Ԫ�س��ֵĴ���
equal_range()       ����������Ŀ�ĵ�������
get_allocator()     ����map��������
key_comp()          ���رȽ�Ԫ��key�ĺ���
lower_bound()      	����keyֵ>=����Ԫ�صĵ�һ��λ��
upper_bound()     	����keyֵ>����Ԫ�صĵ�һ��λ��
max_size()          ���ؿ������ɵ����Ԫ�ظ���
rbegin()          	����һ��ָ��mapβ�������������
rend()          	����һ��ָ��mapͷ�������������
swap()          	��������map
value_comp()        ���رȽ�Ԫ��value�ĺ���
�����������㷨�������н���
