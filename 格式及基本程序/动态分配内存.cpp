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

��ά��:
��̬����һ��n�У�m�еĶ�ά���顣
�ȶ�̬����һά����
p = (int **)malloc(sizeof(int *) * n);
�ٷ����ά
for (i = 0; i < n; i++) {
	p[i] = (int *)malloc(sizeof(int) * m);
}

����:
int row=3;
int col=5;
int** array=new int* [row];
for(int i=0;i<row;i++)
{
    array[i]=new int[col];
} 
 
