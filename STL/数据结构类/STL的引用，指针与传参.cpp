��������ǱȽϳ��õģ�Ҳ���Ǵ�ֵ 
vector<ll> f(vector<ll> t,ll x,ll y,ll k)
{
    vector<ll>res;
    ..........
    return res;
}

vector<int>* p=new vector<int>{ 1,2,3 };

C++��vector��Ϊ���������ִ��η�ʽ����ֵ�����ô�ָ��)
functionl(vector vec)��ֵ
function2(vector &vec)������
function3(vector *vec)��ָ��
ע�⣬���ַ�ʽ�ֱ��ж�Ӧ��const��ʽ,���ڴ����ۡ����ַ�ʽ��Ӧ�ĵ�����ʽ�ֱ�Ϊ:
function1(vec)����ֵ
function2(vec)��������
function3(&vec)�����ַ
���ַ�ʽ��Ч���ֱ�Ϊ:
�ᷢ����������
���ᷢ����������
���ᷢ���������� 

���ô���
void func1(vector<int> &q){}
int main(){
vector<int> q;
func1(q);
}
ָ�봫��
void func1(vector<int> *q){}
int main(){
vector<int> q;
func1(&q);
}
