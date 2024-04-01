#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
#define mn 100005
using namespace std;
ll ans,n,m;
void qsort(int *a,int l,int r){
	if(l<r){//不加这个条件会死循环 
		ll i=l,j=r;
		ll key=a[i];
		while(i<j)
		{
			while(i<j&&a[j]>key)j--;
			if(i<j)a[i++]=a[j];
			while(i<j&&a[i]<key)i++;
			if(i<j)a[j--]=a[i];
		}
		a[i]=key;
		qsort(a,l,i-1);
		qsort(a,i+1,r);
	}
}
int main()
{
	int a[]={25,1,12,25,10,10,34,900,23,12,80,20,1,1,12,25};
		qsort(a,0,15);
		int i;
		for(i=0;i<15;i++){
			printf("%d ",a[i]);
		}
		return 0;
	return 0;
}