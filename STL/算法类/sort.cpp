sort ��������
����������������ָ�룩ָ���Ĳ��ֽ��п�������
�����ڵ������������붨���С�Ƚϵĺ�������������С�ں�
���±���1~n������������� 
bool cmp(ll a,ll b){return a>b;}
sort(a+1,a+n+1,cmp);
��װ�ṹ���vector��������С�ں�
struct w{ll id,x,y;};
vector<w>a;
bool operator <(const w&a,const w&b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
sort(a.begin(),a.end());
