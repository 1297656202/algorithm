//P1880 [NOI1995] ʯ�Ӻϲ�����һ��Բ�βٳ������ܰڷ� N��ʯ�ӣ���Ҫ��ʯ���д���غϲ���һ�ѣ�
//�涨ÿ��ֻ��ѡ���ڵ�2�Ѻϲ����µ�һ�ѣ������µ�һ�ѵ�ʯ��������Ϊ�ôκϲ��ĵ÷֡�
//����Ƴ�һ���㷨,������� N��ʯ�Ӻϲ���1�ѵ���С�÷ֺ����÷֡�
//ע������Ȿ����һ����������Ҫ�ϻ�Ϊ��  

//��Ȼ����������ı��β���ʽ���Ż�������һ�����м�¼ 
//���ң�����⻹�и��Ż�����GarsiaWachs�㷨������P5569 [SDOI2008] ʯ�Ӻϲ� 

#include<iostream>  
#include<cstdio>  
#include<cmath>  
using namespace std;   
int n,minl,maxl,f1[300][300],f2[300][300],num[300];  
int s[300];  
inline int d(int i,int j){return s[j]-s[i-1];}  
//ת�Ʒ��̣�f[i][j] = max(f[i][k]+f[k+1][j]+d[i][j];
int main()  
{   
    scanf("%d",&n);  
    for(int i=1;i<=n+n;i++)  //��Ϊ��һ������������Ҫ����������ö�ٷֽ��ߣ����϶������� 
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
