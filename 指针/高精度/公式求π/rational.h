#ifndef RATIONAL_H
#define RATIONAL_H

#include "big_int.h"

// -----------------------------------------------------------------------------

typedef struct {
    BigInt* num;
    BigInt* denom;
} BigRat;

// -----------------------------------------------------------------------------

BigRat* big_rat_from_ll(long long, long long);
BigRat* big_rat_copy(const BigRat*);
void    big_rat_free(BigRat*);

char* big_rat_to_str(const BigRat*);
void  big_rat_to_ll(const BigRat*, long long* num, long long* denom);

BigRat* big_rat_add(const BigRat*, const BigRat*);
BigRat* big_rat_sub(const BigRat*, const BigRat*);
BigRat* big_rat_mul(const BigRat*, const BigRat*);
BigRat* big_rat_div(const BigRat*, const BigRat*);

// -----------------------------------------------------------------------------

#endif
