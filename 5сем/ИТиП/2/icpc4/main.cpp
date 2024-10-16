#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > vc;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        vc.push_back({x,y});
    }

    for(int i = 0; i < n; ++i){
        vc[i].first -= vc[n - 1].first;
        vc[i].second -= vc[n - 1].second;
    }

    long double ans = 0;

    for(int i = 0; i < n - 1; ++i){
        int dx = vc[i + 1].first - vc[i].first;
        int dy = vc[i + 1].second - vc[i].second;

        int dx2 = vc[i + 1].first;
        int dy2 = vc[i + 1].second;

        long double len1 = sqrt(dx*dx + dy*dy);
        long double len2 = sqrt(dx2*dx2 + dy2*dy2);

        if ( abs(dx*(-1)/len1 - dx2/len2) < 0.000001 || (i == (n-2)) ){
            if ( abs(dy*(-1)/len1 - dy2/len2) < 0.000001 || (i == (n-2)) ){
                ans += len1;
            }
        }


    }

    cout << fixed << setprecision(9) << ans;

    return 0;
}
