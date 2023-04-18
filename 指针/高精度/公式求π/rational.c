#include <stdlib.h>
#include <string.h>
#include "rational.h"

// -----------------------------------------------------------------------------

static void unsigned_swap(Unsigned* x, Unsigned* y)
{
    Unsigned z = *x;
    *x = *y;
    *y = z;
}
static void big_int_swap(BigInt* x, BigInt* y)
{
    BigInt z = *x;
    *x = *y;
    *y = z;
}
static int unsigned_is_zero(const Unsigned* x)
{
    return x && x->size == 1 && x->head->n == 0;
}
static int big_int_is_zero(const BigInt* bi)
{
    return bi && unsigned_is_zero(bi->val);
}
static Unsigned* unsigned_gcd(const Unsigned* x, const Unsigned* y)
{Unsigned* r;
    if(unsigned_is_zero(y))return x;
	unsigned_div(x,y,&r);
	return unsigned_gcd(y,r);
}
static void big_int_cancel(BigInt* x, BigInt* y)
{Unsigned* z,*r;
    if(big_int_is_zero(y))return ;
    if(big_int_is_zero(x))
    {
    	y=big_int_from_ll(1ll);
    	return ;
	}
	z=unsigned_gcd(x->val,y->val);
	x->val=unsigned_div(x->val,z,&r);
	y->val=unsigned_div(y->val,z,&r);
	x->sign=(Sign)(x->sign*y->sign);
	y->sign=(Sign)1;
}
static BigRat* get_big_rat()
{
    BigRat* br = malloc(sizeof(BigRat));
    br->num = br->denom = 0;
    return br;
}
static int big_int_is_one(const BigInt* bi)
{
    return bi &&
           bi->sign == plus &&
           bi->val->size == 1 &&
           bi->val->head->n == 1;
}
BigRat* big_rat_from_ll(long long num, long long denom)
{
    BigInt* x = big_int_from_ll(num);
    BigInt* y = big_int_from_ll(denom);
    BigRat* ret = 0;

    if (!big_int_is_zero(y)) {
        ret = get_big_rat();
        big_int_cancel(x, y);
        ret->num   = x;
        ret->denom = y;
        x = y = 0;
    }
    big_int_free(x);
    big_int_free(y);
    return ret;
}
BigRat* big_rat_copy(const BigRat* x)
{
    if (!x)
        return 0;

    BigRat* y = get_big_rat();
    y->num   = big_int_copy(x->num);
    y->denom = big_int_copy(x->denom);
    return y;
}
void big_rat_free(BigRat* br)
{
    if (!br)
        return;

    big_int_free(br->num);
    big_int_free(br->denom);
    free(br);
}
char* big_rat_to_str(const BigRat* br)
{
    if (!br)
        return 0;

    if (big_int_is_one(br->denom))
        return big_int_to_str(br->num);

    char* x = big_int_to_str(br->num);
    char* y = big_int_to_str(br->denom);

    char* ret = 0;
    if (x && y && (ret = malloc(strlen(x) + strlen(y) + 4))) {
        strcpy(ret, "(");
        strcat(ret, x);
        strcat(ret, "/");
        strcat(ret, y);
        strcat(ret, ")");
    }

    free(x);
    free(y);
    return ret;
}
void big_rat_to_ll(const BigRat* br, long long* num, long long* denom)
{
    if (!br)
        return;

    if (num) { *num = big_int_to_ll(br->num); }
    if (denom) { *denom = big_int_to_ll(br->denom); }
}
BigRat* big_rat_add(const BigRat* x, const BigRat* y)
{BigRat* z;BigInt *a=x->num,*b=x->denom,*c=y->num,*d=y->denom;
    z=get_big_rat();
    z->num=big_int_add(big_int_mul(a,d),big_int_mul(b,c));
    z->denom=big_int_mul(b,d);
    big_int_cancel(z->num,z->denom);
    return z;
}
BigRat* big_rat_sub(const BigRat* x, const BigRat* y)
{BigInt* z;BigRat* tmp;
    z=big_int_from_ll(-1);
    tmp=big_rat_copy(y);
    tmp->num=big_int_mul(tmp->num,z);
    return big_rat_add(x,tmp);
}
BigRat* big_rat_mul(const BigRat* x, const BigRat* y)
{BigRat* z;
    z=get_big_rat();
    z->num=big_int_mul(x->num,y->num);
    z->denom=big_int_mul(x->denom,y->denom);
    big_int_cancel(z->num,z->denom);
    return z;
}
BigRat* big_rat_div(const BigRat* x, const BigRat* y)
{BigRat* z;
    z=big_rat_copy(y);
    big_int_swap(z->num,z->denom);
    return big_rat_mul(x,z);
}
