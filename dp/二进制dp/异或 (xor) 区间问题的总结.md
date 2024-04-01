> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [blog.csdn.net](https://blog.csdn.net/qq_43857314/article/details/104608379)

最近遇到的区间异或的问题比较多，总结一下。

![img](异或 (xor) 区间问题的总结.assets/clip_image002.jpg)

位运算都可以按位计算贡献

考虑异或的性质，于是我们枚举数据范围的每一个二进制位,然后枚举区间右端点，对于每一位j，计算左端点有多少个到当前位置的异或是1，

如果当前数的异或前缀和的第j位为1,则对答案的贡献是前面的异或前缀和的第j位为0的个数,很显然拿一个0和1的关于第j位异或前缀和的前缀和来记录即可

假设有x个,则ans+=(1<<j)*x;

**以下难度递进**

**第一类：**

**问题描述：**给你出一个序列，询问有多少个区间异或为 x。例子：1 2 3 异或为 0 的只有一段 1^2^3  所以输出 1

**题解:**

此类问题有统一解，我们需要处理异或前缀 :![](https://private.codecogs.com/gif.latex?f%28x%29%3Df%281%29xor%20f%282%29....xorf%28x%29)

由于异或的特殊性：a xor a = 0 所以 ![](https://private.codecogs.com/gif.latex?f%28R%29xorf%28L-1%29%3Df%28L%29xorf%28L&plus;1%29...xorf%28R%29)

所以列出式子：![](https://private.codecogs.com/gif.latex?f%28R%29xor%20X%3DX%5Crightarrow%20f%28R%29xor%20X%3Df%28L-1%29)

所以对于任意一个新的异或前缀，我们只需要找前面有多少个异或前缀与 ![](https://private.codecogs.com/gif.latex?f%28R%29xor%20X)相等就可以了

如果 a_i 较大，使用 map 存储异或前缀数量，复杂度 O(nlgn)

如果 a_i 较小，另开辅助标记即可，复杂度 O(n)

注意初始第 0 个异或前缀要标记为 0，剩下细节就不再多说

**第二类：**

**问题描述：**给出一段区间 [L,R]（连续区间），假设 区间长度为 len，那么一共有 len*(len-1)/2 个 pair，问所有 pair 的异或和为多少？

**样例描述：**[1,3] 1^2=3 1^3=2 2^3=1 所以答案为 6

**题解：**

这类问题统一解：

**1. 当 L,R 范围在 1e6 以内:**

可以用 for 循环去遍历区间 [L,R]，对[L,R] 内每一个数二进制拆分，那么如果当前这个数第 k 位是 1，那么他的贡献取决于第 k 位为 0 的数量，反之如果第 k 位为 0，那么贡献取决于第 k 位为 1 的数量，可以写一下伪代码：

```cpp
for(int k = 0 ;k<=30;k++){
    int zero = 0,one = 0;
    for(int i=L;i<=R;i++){
        int x = i>>k&1;
        if(x) ans+=(1<<k)*zero,one++;
        else ans+=(1<<k)*one,zero++;
    }
}
```

复杂度：O(30*R)

**2. 当 L,R 范围在 1~1e18**

显然上面 for 循环的思路行不通，那么此时考虑贡献，就可以考虑总体贡献。

假设当前 n 个数中 ，第 k 位有两个数为 1，那么第 k 位总体的贡献即为 (1<<k)*(n-2)*2  ///01 组合一共有 (n-2)*2 种。

所以可以推出当 n 个数中有 ，第 k 位有 x 个数为 1 的话，那么第 k 位总体贡献为 (1<<k)*(n-k)*k

所以我们只需要知道 [L,R] 范围内第 k 位有多少个 1，这么一来就成了典型的数位 dp 的题目。

如果数位 dp 不会的话也不要紧，观察二进制的分布，k 为 0，2 为周期，k 为 1 4 为周期：

00 01 10 11

所以只需要求出 f(x,k)，f(x,k)代表 [1,x] 中第 k 位有多少个 1(观察规律可以求出这个函数，不再多说)。

那么:![](https://private.codecogs.com/gif.latex?ans%20%3D%20%5Csum%20_%7Bi%3D0%7D%5E%7Bi%3D63%7D%7B%281%3C%3Ci%29*%28f%28R%2Ci%29-f%28L-1%2Ci%29%29%7D)

复杂度 O(log(n))

**第三类：**

**问题描述：**给出一段序列，求出所有长度的子区间异或的和。

**样例描述：**1 2 3  =  1 + 2 + 3 + 1^2 + 1^3 + 2^3 + 1^2^3

~有统一解。。~

**题解：**

1. 首先与还是与上面思路一致，考虑第 k 位的贡献，但是这时候需要对每一位进行异或前缀和记录，因为涉及到所有区间，根据第一类我们可以知道假设这一位是 1，那么我们需要考虑之前异或前缀为 0 的数量，反之这一位为 0，我们需要知道异或前缀为 1 的数量，答案累加就是第 k 位的贡献。

2. 追加补充一下：对比第一类，什么时候第 k 位有贡献？也就说以当前 i 结尾的区间内第 k 位异或为 1 的区间才对第 i 个数的第 k 位有贡献，所以根据第一类我们只需要知道前面有多少个 x^1 即可，因为 x 非 0 即 1，所以把 x^1 就可以了 (若有不懂，放一下伪代码：

```cpp
for(int k=0;k<=30;k++){
   int zero=0,one=0,x=0;///x记录异或前缀
   for(int i=1;i<=n;i++){
        int temp=num[i]>>k&1;
        x^=temp;
        if(x) ans+=zero*(1<<k),one++;
        else ans+=one*(1<<k),zero++;
    }
}
```

复杂度：O(30*N)

**扩展：**

1. 如果区间内数连续可以考虑前面异或有多少个 1 的规律，或者直接打表找规律  —— 2019ICPC 徐州 

**第四类：**

**题目描述：**来自上面题目的扩展，序列中长度为偶数且长度在区间 [L,R] 内的异或和

1. 首先 根据第一类确定一个区间 [L,R] 内的异或值为 ![](https://private.codecogs.com/gif.latex?f%28R%29%20xor%20f%28L-1%29) 

2. 考虑如果当 R 是奇数，那么此时 L-1 应该也开始奇数，此时 R-L+1 是偶数

    同样的如果当 R 是偶数，那么 L-1 应该也是偶数。

3. 所以我们比之前考虑维护一个奇数异或前缀的前缀和，与偶数异或前缀的前缀和。

   如果第 i 位是奇数位 ，那么应该之前奇数位置上的异或前缀为 0 或 1 的个数 (类比第 3 类)。偶数也是同样。

   现在还要再增加一个限制，增加一个区间长度，那么我只需要考虑 (i-1,i-1-len) 之间的有多少个异或为 1 或者异或为 0 即可。

   然后 用维护的长度为 R 的结果 减去 维护的长度为 L-1 的结果 就是答案乐。

   由于这题比较复杂，放一下代码和注释：

```cpp
/*** keep hungry and calm CoolGuang!***/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;
const double PI=acos(-1);
typedef long long ll;
typedef pair<ll,ll> pp;
const ll INF=1e18;
const ll maxn=2e5+18;
const int mod=1e9+7;
const double eps=1e-6;
inline bool read(ll &num)
{char in;bool IsN=false;in=getchar();if(in==EOF) return false;while(in!='-'&&(in<'0'||in>'9')) in=getchar();if(in=='-'){ IsN=true;num=0;}else num=in-'0';while(in=getchar(),in>='0'&&in<='9'){num*=10,num+=in-'0';}if(IsN) num=-num;return true;}
ll n,m,p;
ll L,R;
ll num[maxn];
ll dpe[maxn][32][2],dpo[maxn][32][2];///奇数异或前缀的前缀和偶数异或前缀的前缀和
ll cal(int f,int i,int k,ll temp,ll len){///处理长度小于等于len的区间异或第k位的贡献
    if(f){
        if(i-len-1>=0) return ((dpo[i-1][k][temp^1]-dpo[i-len-1][k][temp^1]%mod+mod)*(1<<k))%mod;
        else return (dpo[i-1][k][temp^1]*(1<<k))%mod;
    }
    else{
        if(i-len-1>=0) return ((dpe[i-1][k][temp^1]-dpe[i-len-1][k][temp^1]%mod+mod)*(1<<k))%mod;
        else return (dpe[i-1][k][temp^1]*(1<<k))%mod;
    }
}
int main()
{
    read(n);
    read(L);read(R);
    for(int i=1;i<=n;i++) read(num[i]);
    ll ans=0;
 
    for(int k=0;k<=30;k++) dpe[0][k][0]=1;
    /// 1.问题的子问题 所有区间异或和 solved 第三类
    /// 2.解决长度在[1,R]内的偶数
    /// 3.长度为偶数考虑 ：
    ///    当前i为奇数时与之前的奇数位置的异或有关系
    ///    当前i为偶数时与之前的偶数位置的异或有关系
    /// 4.所以 两个前缀和 奇数 与 偶数
    for(int k=0;k<=30;k++){
        ll temp=0;
        for(int i=1;i<=n;i++){
            int x=(num[i]>>k&1)?1:0;
            temp^=x;
            if(i%2){///当前i为奇数
                dpe[i][k][0]=dpe[i-1][k][0];///偶数不变
                dpe[i][k][1]=dpe[i-1][k][1];/// 同上
                ans=(ans+cal(1,i,k,temp,R))%mod;
                ans=(ans-cal(1,i,k,temp,L-1)%mod+mod)%mod;
                dpo[i][k][temp]=dpo[i-1][k][temp]+1;
                dpo[i][k][temp^1]=dpo[i-1][k][temp^1];
            }
            else{
                dpo[i][k][0]=dpo[i-1][k][0];///奇数数不变
                dpo[i][k][1]=dpo[i-1][k][1];/// 同上
                ans=(ans+cal(0,i,k,temp,R))%mod;
                ans=(ans-cal(0,i,k,temp,L-1)%mod+mod)%mod;
                dpe[i][k][temp]=dpe[i-1][k][temp]+1;
                dpe[i][k][temp^1]=dpe[i-1][k][temp^1];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
```

update:2020.3.9 

**第四类 (不满足难度递增):**

给出一段序列 A，求有多少对互不重合的区间，使得两区间异或为 0。(n<=1000)

首先倒求一遍后缀区间的所有异或可能，记录后缀所有的异或区间值的个数。

然后，正着枚举，每次枚举到 i，就将 i 位置对后缀的贡献删除，然后将 i 位置向前枚举，也就是以 i 结尾的区间的贡献，可以推出以 i 为结尾的区间数 ，绝对不与后缀区间重合，所以直接计数相加即可。

```cpp
read(n);
    for(int i=1;i<=n;i++) read(num[i]);
    ll sum=0;
    for(int i=n;i>=1;i--){
        sum^=num[i];
        xo[i]=sum;
        for(int k=i+1;k<=n+1;k++)
            vis[xo[i]^xo[k]]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        pre[i]=num[i]^pre[i-1];
        for(int k=i+1;k<=n+1;k++)
            vis[xo[i]^xo[k]]--;
        for(int k=0;k<=i-1;k++)
            ans+=vis[pre[k]^pre[i]];
    }
    printf("%lld\n",ans);
```

总结：

1. 异或问题多是把总问题考虑到某一位上的关系，总贡献分解为每一位的贡献，最后求和。

2. 异或问题，也包含位运算问题，规律性很强，如果强行推不出，可以打表找一下规律。