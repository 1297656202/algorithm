#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rational.h"

// -----------------------------------------------------------------------------
const char pi_string[] =
    "3."
    "14159265358979323846264338327950288419716939937510"
    "58209749445923078164062862089986280348253421170679"
    "82148086513282306647093844609550582231725359408128"
    "48111745028410270193852110555964462294895493038196"
    "44288109756659334461284756482337867831652712019091"
    "45648566923460348610454326648213393607260249141273"
    "72458700660631558817488152092096282925409171536436"
    "78925903600113305305488204665213841469519415116094"
    "33057270365759591953092186117381932611793105118548"
    "07446237996274956735188575272489122793818301194912"
    "98336733624406566430860213949463952247371907021798"
    "60943702770539217176293176752384674818467669405132"
    "00056812714526356082778577134275778960917363717872"
    "14684409012249534301465495853710507922796892589235"
    "42019956112129021960864034418159813629774771309960"
    "51870721134999999837297804995105973173281609631859"
    "50244594553469083026425223082533446850352619311881"
    "71010003137838752886587533208381420617177669147303"
    "59825349042875546873115956286388235378759375195778"
    "18577805321712268066130019278766111959092164201989";
BigRat* arctan(const BigRat* x, int n)
{Int i,k=-1,j;BigRat *y,*z;
	z=big_rat_from_ll(0,1);
    for(i=1;i<=n;i++)
    {
    	k*=-1;
    	y=big_rat_from_ll(k,2*i-1);
    	for(j=1;j<=2*i-1;j++)
    	y=big_rat_mul(y,x);
    	z=big_rat_add(z,y);
    	big_rat_free(y);
	}
	return z;
}
BigInt* power10(int n)
{
    static const Int ignore = 42;

    BigInt* ret = big_int_from_ll(1);
    for (int i = 0; i < n; ++i)
        insert_back(ret->val, 0, ignore);
    return ret;
}
BigRat* get_pi(int items)
{BigRat *x,*y,*z,*k;
    x=big_rat_from_ll(16,1);
    y=big_rat_from_ll(1,5);
    y=arctan(y,items);
    z=big_rat_from_ll(4,1);
    k=big_rat_from_ll(1,239);
    k=arctan(k,items);
    return big_rat_sub(big_rat_mul(x,y),big_rat_mul(z,k));
}
char* to_str(const BigRat* pi, int items)
{BigInt *r,*p;static char ch[100];Link *l;Int i;BigRat* z;
	z=big_rat_copy(pi);
    z->num=big_int_mul(z->num,power10(2*items));
    p=big_int_div(z->num,z->denom,&r);
    ch[0]='3';ch[1]='.';
    l=p->val->head;l=l->next;
    for(i=2;i<=2*items;i++)
    {
		ch[i]=(char)(l->n+'0');
		l=l->next;
	}
	return ch;
}
int main(void)
{BigRat* p;char *pi;Link* l;Int tmp,tmp2,i;
    p=get_pi(40);
    tmp=p->num->val->size;
    tmp2=p->denom->val->size;
    printf("numerator      =   ");
	for(l=p->num->val->head;l;l=l->next)
	printf("%lld",l->n);
	printf("\n");
	printf("denominator    =   ");
	for(l=p->denom->val->head;l;l=l->next)
	printf("%lld",l->n);
	printf("\n");
	printf("¦Ð             =   ");
    pi=to_str(p,40);
    for(i=0;;i++)
    {
    	if(pi[i]!=pi_string[i])break;
    	printf("%c",pi[i]);
	}
	printf("\n\n\n");
    printf("numerator         :  %lld digits\n",tmp);
    printf("denominator       :  %lld digits\n",tmp2);
    printf("¦Ðdecimal places  :  %lld accurate",i-2);
}
