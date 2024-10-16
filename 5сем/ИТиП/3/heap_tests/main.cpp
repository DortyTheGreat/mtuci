#include <iostream>

using namespace std;
#include <chrono>
#include <random>
#include <set>
int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
/// [a;b]
int rnd(int a, int b) {
    return a + mt() % (b - a + 1);
}

#include <fstream>




#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>


#define FORCE_INLINE __attribute__((always_inline)) inline

uint64_t ret, low;
/// ђозвращает большую часть от 128: 64x64
FORCE_INLINE uint64_t hmul64(const uint64_t& a,const uint64_t& b){
    asm ("mulq %3" : "=a"(low), "=d"(ret) : "a"(a), "g"(b) : "cc");
    return ret;
}

class fast_div64{
protected:
    uint64_t my_magic = 1;
    uint_fast8_t shift;

public:
    fast_div64(){}
    fast_div64(const uint64_t& val){
        shift = (127);

        __uint128_t temp = (__uint128_t(1) << 127) / val;
        shift = __builtin_clzll(temp  >> 64); /// zeros
        my_magic = (temp >> (64-shift));
        --shift;

        if (!((++my_magic) & 1)){my_magic >>= 1; --shift;}
        ///cout << my_magic << " " << (int)shift << endl;
    }


    FORCE_INLINE friend uint64_t operator/(const uint64_t& val, const fast_div64& fd){



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


template<typename T, typename quick_mod>
class LCM{
public:
    T mult, old_rand, add;
    quick_mod fm;
    LCM(T _mult,T _old_rand,T _add,T _mod) : mult(_mult), old_rand(_old_rand), add(_add), fm(_mod){}
    FORCE_INLINE T get(){
        return old_rand = (mult * old_rand + add) % fm;
    }

};


// Computes (a + b) % m, assumes a < m and b < m.
template<typename T>
T addmod(T a, T b, T m) {
    if (b >= m - a) return a - m + b;
    return a + b;
}

template<typename T>
static T mult(T x, T y,T& HighProduct) {
    const size_t shift = sizeof(x) * 4;
    T a = x >> shift, b = (x << shift) >> shift;
    T c = y >> shift, d = (y << shift) >> shift;
    // (a*2^64 + b) * (c*2^64 + d) =
    // (a*c) * 2^128 + (a*d + b*c)*2^64 + (b*d)
    T ac = a * c;
    T ad = a * d;
    T bc = b * c;
    T bd = b * d;
    T carry = ((ad << shift) >> shift) + ((bc << shift) >> shift) + (bd >> shift);
    HighProduct = ac + (ad >> shift) + (bc >> shift) + (carry >> shift);
    return (ad << shift) + (bc << shift) + bd;
}

// Computes aR * bR mod N with R = 2**64.


uint64_t montmul(__uint128_t a, uint64_t b, __uint128_t mod, uint64_t inv){
    a *= b;
    uint64_t y = (a >> 64) - (__uint128_t(uint64_t(a) * inv) * mod >> 64);
    return int64_t(y) < 0 ? y + mod : y;

}


/// Computes (a - b) % m, assumes a < m and b < m.
template<typename T>
FORCE_INLINE T submod(const T& a,const T& b,const T& m) {
    if (b > a) return m - b + a;
    return a - b;
}

FORCE_INLINE uint64_t montmul64(const uint64_t& a,const uint64_t& b,const uint64_t& mod,const uint64_t& inv){
    //a *= b;
    uint64_t high = hmul64(a,b);

    return submod(high, hmul64((low * inv), mod), mod);
}


/// 1 * b
FORCE_INLINE uint64_t montmul_1_by_some_64(const uint64_t& b, const uint64_t& mod, const uint64_t& inv){
    //a *= b;

    /// low32 = b
    return mod -  hmul64((b * inv), mod);
}

/// base^exp, also requires 1 in mont (as x).
FORCE_INLINE uint64_t montpow64(uint64_t base, uint64_t exp, uint64_t x, const uint64_t& mod, const uint64_t& inv ){
    /// one = montmul_1_by_some_64(r2,n,inv)
    while (exp) {
        if (exp & 1) {
            x = montmul64(x,base,mod,inv);
        }
        base = montmul64(base,base,mod,inv);
        exp >>= 1;
    }

    return x;
}


/// Дуть быстрее __gcd, дл§ int
template<typename T>
inline T gcd(T a, T b)
{
    while(a %=b) if (!(b %= a)) return a;
    return b;
}

FORCE_INLINE auto ctz(const uint64_t& num){
    return __builtin_ctzll(num);
}

FORCE_INLINE auto ctz(const uint32_t& num){
    return __builtin_ctz(num);
}

template<typename T>
constexpr T gcd_any_odd(T x, T y) {
    if (x == 0) {
        return y;
    }

    x >>= ctz(x);
    while (y != 0) {
        y >>= ctz(y);
        if (x > y) {
            std::swap(x, y);
        }
        y -= x;
    }
    return x;
}


// Finds 2^-64 mod m and (-m)^-1 mod m for odd m (hacker's delight).
// equivalent to xbinGCD ?

/// since (a == 0) === !a




// Returns a factor of n, assumes n is odd.

uint64_t pollard_brent_montgomery(uint64_t n) {
    /*
    if (!(n & 1))
        return 2;
    */


    // Random number Linear Congruential Generator MMIX from D.E. Knuth
    static uint64_t rng = 0xdeafbeef;
    uint64_t a = rng * 6364136223846793005ull + 1442695040888963407ull;
    uint64_t b = a * 6364136223846793005ull + 1442695040888963407ull;
    rng = (a + b) ^ (a * b);

    // y and c are "montgomery space" numbers
    uint64_t y = 1 + a % (n - 1);
    uint64_t c = 1 + b % (n - 1);
    uint64_t m = 20;

    // nneginv is m' (mprime) in Warren

    uint64_t inv = n;
    for(int i = 0;i < 5; ++i) inv *= 2 - n * inv;




    uint64_t factor = 1, r, q, x, ys;
    q = 1; r = 4;

    while(factor == 1){
        x = y;
        for (size_t i = 0; i < r; ++i) {
            y = addmod(montmul(y, y, n, inv), c, n);
        }

        for (size_t k = 0; k < r && factor == 1; k += m) {
            ys = y;
            for (size_t i = 0; i < std::min(m, r - k); ++i) {
                y = addmod(montmul(y, y, n, inv), c, n);
                q = montmul(q, x < y ? y - x : x - y, n, inv);
            }

            factor = gcd_any_odd(q, n);
        }

        r *= 2;
    }

    if (factor == n) {
        do {
            ys = addmod(montmul(ys, ys, n, inv), c, n);
            factor = gcd_any_odd(x < ys ? ys - x : x - ys, n);
        } while (factor == 1);
    }
    if (factor == 1 || factor == n){
        return pollard_brent_montgomery(n);
    }

    return factor;
}


uint64_t pollard_floyd_montgomery(uint64_t n) {
    /*
    if (!(n & 1))
        return 2;
    */


    // Random number Linear Congruential Generator MMIX from D.E. Knuth
    static uint64_t rng = 0xdeafbeef;
    uint64_t a = rng * 6364136223846793005ull + 1442695040888963407ull;
    uint64_t b = a * 6364136223846793005ull + 1442695040888963407ull;
    rng = (a + b) ^ (a * b);

    // y and c are "montgomery space" numbers
    uint64_t y = 1 + a % (n - 1);
    uint64_t c = 1 + b % (n - 1);


    // nneginv is m' (mprime) in Warren

    uint64_t inv = n;
    for(int i = 0;i < 5; ++i) inv *= 2 - n * inv;




    uint64_t factor = 1, x = y;

    uint64_t q = 1;

    while(factor == 1){

        for(int i = 0; i < 11; ++i){
            x = addmod(montmul(x, x, n, inv), c, n);

            y = addmod(montmul(y, y, n, inv), c, n);
            y = addmod(montmul(y, y, n, inv), c, n);

            q = montmul(q, x < y ? y - x : x - y, n, inv);
        }
        factor = gcd_any_odd(q, n);
    }

    if (factor == n) {
        return pollard_brent_montgomery(n);
    }

    return factor;
}


#include <map>

using namespace std;

template<typename unsign>
FORCE_INLINE unsign sqr(const unsign& num){
    return num*num;
}

/// важно, чтобы тип unsign позвол§л вместить в себ§ произведение mod*mod. aka избавл§йтесь от переполнени§
template<typename unsign, typename power_type, typename modulus_obj>
FORCE_INLINE unsign modul_pow(unsign num, power_type power, const modulus_obj& mod){
    unsign cur = 1;
    for(;power;power >>= 1) {
        if (power & 1) cur = (cur*num) % mod;
        num = sqr(num) % mod;
    }
    return cur;
}

/// http://ceur-ws.org/Vol-1326/020-Forisek.pdf
bool is_SPRP(uint32_t n, const uint64_t& a) {

    fast_mod64 fm_n(n);
    uint_fast8_t s = ctz(--n);
    uint64_t cur = modul_pow(a, n>>s, fm_n);
    if (cur == 1) return true;
    for (uint_fast8_t r=0; r<s; ++r) {
        if (cur == n) return true;
        cur = sqr(cur) % fm_n;
    }
    return false;
}

#include <algorithm>
///  const __uint128_t& ui128, но у мен§ вс™ деструктивно
std::ostream& operator <<(std::ostream& os, __uint128_t ui128) {

    string buff;
    while(ui128){
        buff += (ui128%10+'0');
        ui128 /= 10;
    }



    reverse(buff.begin(),buff.end());

	return (os << buff);
}

bool miller_rabin64(const uint64_t& n, uint64_t a, uint64_t r2, uint64_t inv, uint64_t d, uint64_t one, uint64_t minus_one){

    if (n % a == 0) return n == a;
    a %= n;

    a = montmul64(a,r2,n,inv);

    /// Montgomery stuff done


    uint_fast8_t s = ctz(d);
    d >>= s;

    uint64_t x = montpow64(a, d, one, n, inv);

    if (x == one) {
        return 1;
    }

    while(s--){
        if (x == minus_one) return true;
        x = montmul64(x,x,n,inv);
    }
    return false;
}

/// this is probably correct, ig
bool isPrime_det_mr_mont(uint64_t n){

    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    if (n % 5 == 0) return n == 5;
    if (n % 7 == 0) return n == 7;

    if (n % 11 == 0) return n == 11;
    if (n % 13 == 0) return n == 13;
    if (n % 17 == 0) return n == 17;
    if (n % 19 == 0) return n == 19;

    if (n % 23 == 0) return n == 23;
    if (n % 29 == 0) return n == 29;
    if (n % 31 == 0) return n == 31;
    if (n % 37 == 0) return n == 37;

    if (n % 41 == 0) return n == 41;
    if (n % 43 == 0) return n == 43;
    if (n % 47 == 0) return n == 47;
    if (n % 53 == 0) return n == 53;


    uint64_t inv = n;
    for(int ii = 0;ii < 5; ++ii) inv *= 2 - n * inv;


    __uint128_t r = ((__uint128_t(1) << 127) % n) << 1;
    if (r > n) r-= n;
    uint64_t r2 = r;

    uint64_t one = montmul_1_by_some_64(r2,n,inv);
    uint64_t d = n-1;
    uint64_t minus_one = montmul64(d,r2,n,inv);

    ///if (v % 3 == 0 || v % 2 == 0) continue;


    return miller_rabin64(n, 2, r2, inv, d, one, minus_one) && miller_rabin64(n, 3, r2, inv, d, one, minus_one) && miller_rabin64(n, 5, r2, inv, d, one, minus_one) &&
        miller_rabin64(n, 7, r2, inv, d, one, minus_one) && miller_rabin64(n, 11, r2, inv, d, one, minus_one) && miller_rabin64(n, 13, r2, inv, d, one, minus_one) &&
         miller_rabin64(n, 17, r2, inv, d, one, minus_one) && miller_rabin64(n, 19, r2, inv, d, one, minus_one);
}



#define cf3(k) while (!(num % k)){arr[size++] = k; num /= k;}

std::vector<uint64_t> factor(__uint128_t num){
    ///cout <<"F: " << num << endl;
    vector<uint64_t> arr(sizeof(uint64_t) * 8 - 1);
    unsigned int size = 0;

    cf3(2) cf3(3) cf3(5) cf3(7) cf3(11)
    cf3(13) cf3(17) cf3(19) cf3(23) cf3(29)
    cf3(31) cf3(37) cf3(41) cf3(43) cf3(47)
    cf3(53) cf3(59) cf3(61) cf3(67) cf3(71)
    if (num == 1) goto last;
    if (num < 5329){
        arr[size++] = num;
        goto last;
    }
    arr[size] = num;

    for(size_t i = size;i < size + 1; ){
        ///cout << arr[i] << endl;
        ///cout << isPrime(arr[i]) << endl;
        if(arr[i] == 1){++i; continue;}
        if (isPrime_det_mr_mont(arr[i])) { ++i; continue; } /// got here n as a factor
        arr[++size] = pollard_floyd_montgomery( arr[i]);

        arr[i] /= arr[size];

    }
    ++size;
    last:
        arr.resize(size);
        sort(arr.begin(),arr.end());
        return arr;
}



std::istream& operator>>(std::istream& in, __uint128_t &ui128) {


    std::string stream_;
    in >> stream_;

    ui128 = 0;
    for(char c : stream_){
        ui128 *= 10;
        ui128 += c-'0';
    }

    return in;

}




template <typename T>
std::ostream& operator<<(std::ostream &in, const std::vector<T> &vect) {
    int n = vect.size();
    for(int i =0;i<n;i++){
        in << vect[i] << " " ;
    }
    return in;
}

#include <sstream>

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

int main()
{

    for(int test = 0; test < 70; ++test){
        set<int> heap;
        int sz = rnd(3, 10 + pow(1.3, test));

        int prob = rnd(10,90);

        ofstream ou("out" + NumberToString(test) + ".txt");
        int n = rnd(1,sz);
        ou << n << endl;
        for(int i =0;i<n;++i){

            if (heap.empty()){
                int num = rnd(3, 10 + pow(1.4, test));
                ou << "+ " << num << endl;
                heap.insert(num);
            }else{

                if (rnd(1,99) < prob){
                    /// ?
                    ou << "?" << endl;
                    heap.erase(heap.begin());
                }else{
                    /// +
                    int num = rnd(3, 10 + pow(1.4, test));
                    ou << "+ " << num << endl;
                    heap.insert(num);
                }

            }


        }

    }


    return 0;
}
