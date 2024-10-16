#include <iostream>
#include <set>
#include <utility>
#include <cmath>
#include <map>
using namespace std;

#define int long long

long double eps = powl( (long double)(0.5) , (long double)(30));

long double bino(long double v, int power){

    long double ret = 1;

    for(int i = 0; i < power; ++i){
        ret *= (v - i);
        ///ret /= (i+1);
    }

    return ret;
}

long double seeder(long double v, int power){
    long double r = 1e10;
    long double l = power;


    while (r - l > eps){
        ///cout << r << " " << l << endl;
        long double m = (r + l) / 2;
        if (bino(m,power) < v){
            l = m;
        }else{
            r = m;
        }
    }

    return r;


}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);

    ///cout << bino(7,7) << endl;
    int t;
    cin >> t;


    map<long long , set< pair<long long, long long> > > memo;


    for(int seed = 6; seed < 20; ++seed){
        for(int base = seed + 1; base < 10 * 1000; ++base){

            long double f_val = round(bino(base,seed));

            if (f_val > 1e19) continue;

            long long value = round(bino(base,seed));
            long long choose = seed;

            memo[value].insert({base, choose});
        }
    }

    while(t--){
        set< pair<int, int> > potential;
        long long v;
        cin >> v;
        for(int seed = 5; seed != 1; --seed){
            long double f = seeder(v, seed);
            if ( abs(round(f) - f) < eps ){
                if (abs(f - seed) < eps * 10 ){
                    /// Не корректный бином
                    continue;
                }

                long long from = round(f);
                long long choose = seed;
                potential.insert({from, choose});
                ///potential.insert({from, from - choose});
            }
        }

        if (memo.find(v) != memo.end()){
            potential.insert(*(memo[v].begin()));
        }

        if (!potential.empty()){
            cout << (*(potential.begin())).first << " " << (*(potential.begin())).second << '\n';
        }else{
            cout << v << " " << 1 << '\n';
        }
    }



    return 0;
}
