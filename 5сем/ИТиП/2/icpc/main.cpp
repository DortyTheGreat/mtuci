#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> memo;
/// arg < 1000
int f(int arg){

    if (memo.find(arg) != memo.end()){
        return memo[arg];
    }

    long long ans = 0;
    if (arg == 0) return memo[arg] = 0;
    if (arg == 1) return memo[arg] = 1;
    if (arg == 10) return memo[arg] = 1;
    if (arg == 100) return memo[arg] = 1;
    if (arg == 1000) return memo[arg] = 1;

    if (arg == 5) return memo[arg] = 1;
    if (arg == 50) return memo[arg] = 1;
    if (arg == 500) return memo[arg] = 1;

    if (arg == 4) return memo[arg] = 2;
    if (arg == 40) return memo[arg] = 2;
    if (arg == 400) return memo[arg] = 2;

    if (arg == 9) return memo[arg] = 2;
    if (arg == 90) return memo[arg] = 2;
    if (arg == 900) return memo[arg] = 2;

    int mini = 1000000;

    for(int i = 1; i < arg; ++i){

        mini = min(f(i) + f(arg - i), mini);
        //cout << i << " " << mini << endl;
    }


    ///cout << arg << " " << mini << endl;
    return memo[arg] = mini;

}

signed main()
{
    long long a;
    cin >> a;

    long long ans = 0;
    long long mini = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;


    ans = 0;
    ans += (a / 3000) * 3;
    ans += f(a % 3000);
    mini = min(mini, ans);

    if (a > 3000){
        ans = 0;
        ans += ((a-1000) / 3000) * 3 + 1;
        ans += f((a-1000) % 3000);
        mini = min(mini, ans);


        ans = 0;
        ans += ((a-2000) / 3000) * 3 + 2;
        ans += f((a-2000) % 3000);
        mini = min(mini, ans);
    }

    cout << mini;

    return 0;
}
