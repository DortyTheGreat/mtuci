#include <iostream>

using namespace std;

#define uint64_t unsigned long long
#define uint32_t unsigned

#define FORCE_INLINE __attribute__((always_inline)) inline

/// Возвращает большую часть от 128: 64x64
FORCE_INLINE uint64_t hmul64(const uint64_t& a,const uint64_t& b){
    uint64_t ret, low;
    asm ("mulq %3" : "=a"(low), "=d"(ret) : "a"(a), "g"(b) : "cc");
    return ret;
}

class fast_div64{
protected:
    uint64_t my_magic = 1;
    uint64_t shift;

public:
    fast_div64(){}
    fast_div64(const uint64_t& val){
        shift = 127;

        __uint128_t temp = (__uint128_t(1) << 127) / val;
        shift = __builtin_clzll(temp  >> 64); /// zeros
        my_magic = (temp >> (64-shift));
        --shift;

        if (!((++my_magic) & 1)){my_magic >>= 1; --shift;}
        ///cout << my_magic << " " << (int)shift << endl;
    }


    __attribute__((always_inline)) friend uint64_t operator/(const uint64_t& val, const fast_div64& fd){



        return (hmul64(val,fd.my_magic) >> fd.shift ) ;
    }
};

class fast_mod64 : fast_div64{
private:
    uint64_t div;
public:
    fast_mod64(){}
    fast_mod64(uint64_t val) : fast_div64(val), div(val){}
    FORCE_INLINE friend uint64_t operator%(const uint64_t& val, const fast_mod64& fm){
        return val - val/fm * fm.div;
    }
};

#define int long long
/**

10! = 1 * 2 * 3 * ... * 10

= 1 * 3 * 5 * 7 * 9
* 2^5 * (1 * 2 * 3 * 4 * 5)


[ANOTHER CONCEPT]

= 1 * 5 * 7

* 2^5 (1 * 2 * 3 * 4 * 5)
* 3^2 * (1 * 3 * [continue as 5, 7, etc])
* 5^1 * (1 * 5 * 7 * 11 * 13 * ...)


[SIMPLE CONCEPT]

= 1 * 3 * 5 * 7 * 9 *
* 2^5(1 * 2 * 3 * 4 *5)

=> d = 1 * 3 * 5 [1/4 of n computation]

ans = d * (7 * 9) *
2^5 * (d * 2^2 * (1 * 2) )


[2025 IDEA]

(x+2)*(x+3) - (x)*(x+1) = 4x + 6,
we might now group the numbers. For example 20! =
= (1*2) * (3*4) * (5*6) * ...

we might already know the term 3*4 = 12, so 5*6 = 12 + 4*(3) + 6 = 12 + 12 + 6 = 30,
given that m >> n (really bigger) it might imply that taking modulo of the term itself might be unnecessary



[wacky idea]

20! = (1 * 5 * 9 * 13 * ...) * (2 * 6 * 10 * ...) * (...) * (...)





[2*3 idea]



= 1 * 3 * 5 * 7 * 9 * 11 * 13 * 15 * 17 * 19
* 2^5(1 * 2 * 3 * 4 *5)

=> d = 1 * 3 * 5 [1/4 of n computation]

ans = d * (7 * 9) *
2^5 * (d * 2^2 * (1 * 2) )

*/

fast_mod64 fm;

template<typename unsign, typename power_type>
FORCE_INLINE unsign modul_pow(unsign num, power_type power){
    unsign cur = 1;
    for(;power;power >>= 1) {
        if (power & 1) cur = (cur*num) % fm;
        num = num * num % fm;
    }
    return cur;
}

int modular_factorial(int n){

    int ans = 1;

    if (n < 1000){
        for(int i = 2; i <= n; ++i){
            ans = (ans * i) % fm;
        }
        return ans;
    }

    int d = 1;
    int i = 1;

    for(; i <= n/2; i += 2){
        d = (d * i) % fm;
    }

    ans = d;

    for(; i <= n; i += 2){
        d = (d * i) % fm;
    }

    ans = ans * (modul_pow(2ull, n/2 + n/4)) % fm;
    ans = ans * (d) % fm;
    ans = ans * modular_factorial(n/4) % fm;


    return ans;
}

/**
this algo goes through 1/2 of the ints, then
*/
int simple_modular_factorial(int n){

    int ans = 1;

    if (n < 1000){
        for(int i = 2; i <= n; ++i){
            ans = (ans * i) % fm;
        }
        return ans;
    }

    for(int i = 1; i < n / 4; i += 2)
}

signed main()
{
    int n,m;
    cin >> n >> m;

    fm = fast_mod64(m);

    cout << modular_factorial(n);

    return 0;
}
