#include <stdlib.h>
#include "big_int.h"

// -----------------------------------------------------------------------------

static BigInt* get_big_int(void)
{
    BigInt* bi = malloc(sizeof(BigInt));
    bi->sign = plus;
    bi->val  = 0;
    return bi;
}

// 在此处可定义若干辅助函数，以供定义其它函数时使用

// -----------------------------------------------------------------------------

BigInt* big_int_from_ll(long long x)
{
    BigInt* bi = get_big_int();
    bi->sign = (x >= 0) ? plus : minus;
    bi->val  = unsigned_from_ll(bi->sign * x);
    return bi;
}

BigInt* big_int_copy(const BigInt* x)
{
    if (!x)
        return 0;

    BigInt* y = get_big_int();
    y->sign = x->sign;
    y->val  = unsigned_copy(x->val);
    return y;
}

void big_int_free(BigInt* bi)
{
    if (!bi)
        return;

    unsigned_free(bi->val);
    free(bi);
}

char* big_int_to_str(const BigInt* bi)
{
    if (!(bi && bi->val->size > 0))
        return 0;

    Int n = (bi->sign == minus) ? bi->val->size + 2
                                : bi->val->size + 1;

    char* ret = (char*)calloc(n, sizeof(char));
    char* p   = ret;
    if (bi->sign == minus)
        *p++ = '-';

    for (Link* link = bi->val->head; link; ++p, link = link->next)
        *p = link->n + '0';
    *p = '\0';
    return ret;
}

long long big_int_to_ll(const BigInt* bi)
{
    return bi->sign * unsigned_to_ll(bi->val);
}
int big_int_cmp(const BigInt* x, const BigInt* y)
{
    if(x->sign>y->sign)return 1;
    if(x->sign<y->sign)return -1;
    return  x->sign*unsigned_cmp(x->val,y->val);
}
BigInt* big_int_add(const BigInt* x, const BigInt* y)
{BigInt	*z;Int i;
	z=get_big_int();
    if(x->sign*y->sign>0){z->val=unsigned_add(x->val,y->val);z->sign=x->sign;return z;}
	i=unsigned_cmp(x->val,y->val);
	if(i==0){z->val=get_list();insert_front(z->val,0,0);z->sign=plus;return z;}
	if(i>0){z->val=unsigned_sub(x->val,y->val);z->sign=x->sign;return z;}
	if(i<0){z->val=unsigned_sub(y->val,x->val);z->sign=y->sign;return z;}
}
BigInt* big_int_sub(const BigInt* x, const BigInt* y)
{BigInt	*z;
	z=get_big_int();
    z=big_int_copy(y);
	z->sign=(Sign)(z->sign*-1);
    return big_int_add(x,z);
}
BigInt* big_int_mul(const BigInt* x, const BigInt* y)
{BigInt	*z;
	z=get_big_int();
    z->val=unsigned_mul(x->val,y->val);
    z->sign=(Sign)(x->sign*y->sign);
    return z;
}
BigInt* big_int_div(const BigInt* x, const BigInt* y, BigInt** rem)
{BigInt	*z;
	z=get_big_int();
	*rem=get_big_int();
    z->val=unsigned_div(x->val,y->val,&((*rem)->val));
    z->sign=(Sign)(x->sign*y->sign);
    if((*rem)->val->size==1&&(*rem)->val->head->n==0)(*rem)->sign=(Sign)1;
    else (*rem)->sign=(Sign)x->sign;
    return z;
}

// -----------------------------------------------------------------------------
