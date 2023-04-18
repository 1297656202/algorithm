#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "rational.h"

// -----------------------------------------------------------------------------

typedef long long ll;

ll big_rat_test(ll, ll, ll, ll, ll, ll, ll, ll, int, int, int, int);

// -----------------------------------------------------------------------------

int main(void)
{
    ll errors =
        big_rat_test(-30, 40, -200, -160, -130, -110, 900, 1100, 1, 1, 1, 1);

    printf("big rational test errors: %lld\n\n", errors);
    return 0;
}

// -----------------------------------------------------------------------------

int equal(double x, double y)
{
    return fabs(x - y) < 1E-8;
}

ll big_rat_test(
    ll x_from, ll x_to,
    ll y_from, ll y_to,
    ll n_from, ll n_to,
    ll m_from, ll m_to,
    int test_add, int test_sub,
    int test_mul, int test_div)
{
    ll errors = 0;
    for (ll x = x_from; x <= x_to; ++x)
        for (ll y = y_from; y <= y_to; ++y)
            for (ll n = n_from; n <= n_to; ++n)
                for (ll m = m_from; m <= m_to; ++m) {
                    BigRat* i = big_rat_from_ll(x, y);
                    BigRat* j = big_rat_from_ll(n, m);

                    BigRat* a = big_rat_add(i, j);
                    BigRat* b = big_rat_sub(i, j);
                    BigRat* c = big_rat_mul(i, j);
                    BigRat* d = big_rat_div(i, j);

                    char* si = big_rat_to_str(i);
                    char* sj = big_rat_to_str(j);
                    char* sa = big_rat_to_str(a);
                    char* sb = big_rat_to_str(b);
                    char* sc = big_rat_to_str(c);
                    char* sd = big_rat_to_str(d);

                    if (test_add && y != 0 && m != 0) {
                        ll num, denom;
                        big_rat_to_ll(a, &num, &denom);

                        double aa = x * 1.0 / y;
                        double bb = n * 1.0 / m;
                        double cc = num * 1.0 / denom;
                        if (!equal(aa + bb, cc)) {
                            printf("error %s + %s\n", si, sj);
                            ++errors;
                        }
                    }

                    if (test_sub && y != 0 && m != 0) {
                        ll num, denom;
                        big_rat_to_ll(b, &num, &denom);

                        double aa = x * 1.0 / y;
                        double bb = n * 1.0 / m;
                        double cc = num * 1.0 / denom;
                        if (!equal(aa - bb, cc)) {
                            printf("error %s - %s\n", si, sj);
                            ++errors;
                        }
                    }

                    if (test_mul && y != 0 && m != 0) {
                        ll num, denom;
                        big_rat_to_ll(c, &num, &denom);

                        double aa = x * 1.0 / y;
                        double bb = n * 1.0 / m;
                        double cc = num * 1.0 / denom;
                        if (!equal(aa * bb, cc)) {
                            printf("error %s * %s\n", si, sj);
                            ++errors;
                        }
                    }

                    if (test_div && y != 0 && m != 0 && n != 0) {
                        ll num, denom;
                        big_rat_to_ll(d, &num, &denom);

                        double aa = x * 1.0 / y;
                        double bb = n * 1.0 / m;
                        double cc = num * 1.0 / denom;
                        if (!equal(aa / bb, cc)) {
                            printf("error %s / %s\n", si, sj);
                            ++errors;
                        }
                    }

                    big_rat_free(i);
                    big_rat_free(j);
                    big_rat_free(a);
                    big_rat_free(b);
                    big_rat_free(c);
                    big_rat_free(d);

                    free(si);
                    free(sj);
                    free(sa);
                    free(sb);
                    free(sc);
                    free(sd);
                }
    return errors;
}

// -----------------------------------------------------------------------------
