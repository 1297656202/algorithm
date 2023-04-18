求最少要多少个不下降（上升）子序列可以覆盖全部的数列

dilworth定理：链的最少划分数 = 反链的最长长度，也就是等于整个序列反过来的最长不下降（上升）子序列长度 
问题：导弹拦截 
算法： 贪心，每次用最小的最接近的那个系统去覆盖，如果都不行，就加一个系统 
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
