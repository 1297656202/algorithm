void* malloc(unsigned int size);
void* calloc(unsigned int num,unsigned int size);
ll *p1;
scanf("%lld",&n);
p1=(ll*)malloc(n*sizeof(ll));
p1=(ll*)calloc(n,sizeof(ll));
for(i=0;i<n;i++)
	cout<<p1[i]<<endl;

void* free(void* p) 
free(p1);

二维的:
动态分配一个n行，m列的二维数组。
先动态分配一维数组
p = (int **)malloc(sizeof(int *) * n);
再分配二维
for (i = 0; i < n; i++) {
	p[i] = (int *)malloc(sizeof(int) * m);
}

或者:
int row=3;
int col=5;
int** array=new int* [row];
for(int i=0;i<row;i++)
{
    array[i]=new int[col];
} 
 
