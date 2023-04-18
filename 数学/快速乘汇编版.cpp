inline long long long_long_mult_with_mod(long long x, long long y, long long mod) {
    long long res;
    __asm__(
        "movq   %1,   %%rax\n"
        "imulq  %2\n"
        "idivq  %3\n"
        "movq   %%rdx,   %0\n"
        : "=r"(res)
        : "r"(x), "r"(y), "r"(mod)
        : "%rax", "%rdx"
    );
    return res;
}
