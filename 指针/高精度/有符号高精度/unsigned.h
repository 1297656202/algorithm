#ifndef UNSIGNED_H
#define UNSIGNED_H

#include "list.h"

// -----------------------------------------------------------------------------

typedef List Unsigned;

// -----------------------------------------------------------------------------

Unsigned* unsigned_from_ll(long long);
Unsigned* unsigned_copy(const Unsigned*);
void      unsigned_free(Unsigned*);

long long unsigned_to_ll(const Unsigned*);
int       unsigned_cmp(const Unsigned*, const Unsigned*);

Unsigned* unsigned_add(const Unsigned*, const Unsigned*);
Unsigned* unsigned_sub(const Unsigned*, const Unsigned*);
Unsigned* unsigned_mul(const Unsigned*, const Unsigned*);
Unsigned* unsigned_div(const Unsigned*, const Unsigned*, Unsigned** rem);

// -----------------------------------------------------------------------------

#endif
