������Ҫ���ٸ����½��������������п��Ը���ȫ��������

dilworth�����������ٻ����� = ����������ȣ�Ҳ���ǵ����������з�����������½��������������г��� 
���⣺�������� 
�㷨�� ̰�ģ�ÿ������С����ӽ����Ǹ�ϵͳȥ���ǣ���������У��ͼ�һ��ϵͳ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
int dp[maxn];
int a[maxn],ma[maxn];
int main()
{
    int n;
    char c;
    int k=0;
    while(~scanf("%d%c",&n,&c))
    {
        ma[k++]=n;
        if(c=='\n'){break;}
    }
    a[1]=ma[k-1];
    int len=1;
    for(int i=k-2;i>=0;i--)
    {
        if(ma[i]>=a[len]){
            a[++len]=ma[i];
        }
        else {
            int pos=upper_bound(a+1,a+len+1,ma[i])-a;
            a[pos]=ma[i];
        }
    }
    dp[1]=ma[1];
    int let=1;
    for(int i=2;i<k;i++)
    {
        if(ma[i]<=dp[let]){
            int pos=lower_bound(dp+1,dp+let+1,ma[i])-dp;
            dp[pos]=ma[i];
        }
        else {
            dp[++let]=ma[i];
        }
    }
    printf("%d\n%d\n",len,let);
    return 0;
}
