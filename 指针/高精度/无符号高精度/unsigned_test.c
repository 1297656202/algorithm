#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "unsigned.h"

// -----------------------------------------------------------------------------

typedef long long ll;

// -----------------------------------------------------------------------------

ll unsigned_test(
    ll  i_from,
    ll  i_to,
    ll  j_from,
    ll  j_to,
    int test_cmp,
    int test_add,
    int test_sub,
    int test_mul,
    int test_div)
{
    ll errors = 0;
    for (ll i = i_from; i <= i_to; ++i) {
        for (ll j = j_from; j <= j_to; ++j) {
            Unsigned* a = unsigned_from_ll(i);
            Unsigned* b = unsigned_from_ll(j);
            Unsigned* s = 0;
            Unsigned* d = 0;
            Unsigned* p = 0;
            Unsigned* q = 0;
            Unsigned* r = 0;

            if (test_cmp) {
                int cmp = unsigned_cmp(a, b);
                if (!((cmp > 0 && i > j) ||
                      (cmp == 0 && i == j) ||
                      (cmp < 0 && i < j)))
                {
                    printf("error comparing %lld and %lld\n", i, j);
                    ++errors;
                }
            }

            if (test_add) {
                s = unsigned_add(a, b);
                if (unsigned_to_ll(s) != i + j) {
                    printf("error adding %lld and %lld\n", i, j);
                    ++errors;
                }
            }

            if (test_sub && i >= j) {
                d = unsigned_sub(a, b);
                if (unsigned_to_ll(d) != i - j) {
                    printf("error %lld minus %lld\n", i, j);
                    ++errors;
                }
            }

            if (test_mul) {
                p = unsigned_mul(a, b);
                if (unsigned_to_ll(p) != i * j) {
                    printf("error multiplying %lld by %lld\n", i, j);
                    ++errors;
                }
            }

            if (test_div && j) {
                q = unsigned_div(a, b, &r);
                if (unsigned_to_ll(q) != i / j ||
                    unsigned_to_ll(r) != i % j)
                {
                    printf("error dividing %lld by %lld\n", i, j);
                    ++errors;
                }
            }

            unsigned_free(a);
            unsigned_free(b);
            unsigned_free(s);
            unsigned_free(d);
            unsigned_free(p);
            unsigned_free(q);
            unsigned_free(r);
        }
    }
    return errors;
}

Unsigned* unsigned_from_str(const char* s)
{
    static const Int ignore = 42;

    Unsigned* ret = get_list();
    for (; isdigit(*s); ++s)
        insert_back(ret, *s - '0', ignore);
    return ret;
}

bool unsigned_mul_test(
    const char* a,
    const char* b,
    const char* c)
{
    Unsigned* x = unsigned_from_str(a);
    Unsigned* y = unsigned_from_str(b);
    Unsigned* z = unsigned_mul(x, y);

    bool ret = true;
    for (Link* link = z->head;
         link && isdigit(*c);
         link = link->next, ++c)
    {
        if (link->n != *c - '0') {
            ret = false;
            break;
        }
    }

    unsigned_free(x);
    unsigned_free(y);
    unsigned_free(z);
    return ret;
}

// -----------------------------------------------------------------------------

int main(void)
{
    ll errors = 0;

    errors += unsigned_test(0, 200, 1000, 2000, 1, 1, 1, 1, 1);
    errors += unsigned_test(1000, 2000, 0, 200, 1, 1, 1, 1, 1);
    errors += unsigned_test(9000, 11000, 8000, 10000, 1, 0, 0, 0, 0);

    printf("unsigned test errors: %lld\n\n", errors);

    const char* a = "11223344556677";
    const char* b = "998877660055";
    const char* c = "11210748148764543086437235";

    printf("unsigned mul test %s for\n%s * %s = %s\n",
           (unsigned_mul_test(a, b, c)) ? "passed" : "failed",
           a, b, c);

    return 0;
}

// -----------------------------------------------------------------------------
