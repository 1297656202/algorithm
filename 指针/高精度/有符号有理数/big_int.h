#ifndef BIG_INT_H
#define BIG_INT_H

#include "unsigned.h"

// -----------------------------------------------------------------------------

typedef enum {
    plus  = 1, // 表示非负数
    minus = -1 // 表示负数
} Sign;

typedef struct {
    Sign      sign; // 表示大整数的符号（负数或非负数）
    Unsigned* val;  // 表示大整数的绝对值的大小
} BigInt;

// -----------------------------------------------------------------------------

BigInt* big_int_from_ll(long long);
BigInt* big_int_copy(const BigInt*);
void    big_int_free(BigInt*);

char*     big_int_to_str(const BigInt*);
long long big_int_to_ll(const BigInt*);
int       big_int_cmp(const BigInt*, const BigInt*);

BigInt* big_int_add(const BigInt*, const BigInt*);
BigInt* big_int_sub(const BigInt*, const BigInt*);
BigInt* big_int_mul(const BigInt*, const BigInt*);
BigInt* big_int_div(const BigInt*, const BigInt*, BigInt** rem);

// -----------------------------------------------------------------------------

#endif // ifndef BIG_INT_H
