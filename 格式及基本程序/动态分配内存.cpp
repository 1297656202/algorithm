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
