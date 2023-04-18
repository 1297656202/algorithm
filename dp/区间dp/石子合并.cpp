//P1880 [NOI1995] 石子合并：在一个圆形操场的四周摆放 N堆石子，现要将石子有次序地合并成一堆，
//规定每次只能选相邻的2堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
//试设计出一个算法,计算出将 N堆石子合并成1堆的最小得分和最大得分。
//注意这个题本身是一个环，所以要断环为链  

//当然，这个题有四边形不等式的优化，在另一部分有记录 
//而且，这个题还有个优化，叫GarsiaWachs算法，见于P5569 [SDOI2008] 石子合并 

#include<iostream>  
#include<cstdio>  
#include<cmath>  
using namespace std;   
int n,minl,maxl,f1[300][300],f2[300][300],num[300];  
int s[300];  
inline int d(int i,int j){return s[j]-s[i-1];}  
//转移方程：f[i][j] = max(f[i][k]+f[k+1][j]+d[i][j];
int main()  
{   
    scanf("%d",&n);  
    for(int i=1;i<=n+n;i++)  //因为是一个环，所以需要开到两倍再枚举分界线，最后肯定是最大的 
    {  
        scanf("%d",&num[i]);  
        num[i+n]=num[i];  
        s[i]=s[i-1]+num[i];  
    }  
    for(int p=1;p<n;p++)  
    {  
        for(int i=1,j=i+p;(j<n+n) && (i<n+n);i++,j=i+p)  
        {  
            f2[i][j]=999999999;  
            for(int k=i;k<j;k++)  
            {  
                f1[i][j] = max(f1[i][j], f1[i][k]+f1[k+1][j]+d(i,j));   
                f2[i][j] = min(f2[i][j], f2[i][k]+f2[k+1][j]+d(i,j));  
            }  
        }  
    }  
    minl=999999999;  
    for(int i=1;i<=n;i++)  
    {  
        maxl=max(maxl,f1[i][i+n-1]);  
        minl=min(minl,f2[i][i+n-1]);  
    }  
    printf("%d\n%d",minl,maxl);  
    return 0;  
}
