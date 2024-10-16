#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;

int main()
{
    long double u, m;
    cin >> u >> m;

    vector<pair<long double, long double> > vc;

    for(int i =0; i < 15; ++i){
        long double t, c;
        cin >> t >> c;
        vc.push_back({t,c});
    }

    for(int season = 1; season <= 4; ++season){
        long double spend = 0;
        for(int i =0; i < 15; ++i){
            if (season > vc[i].first){
                spend += m;
                continue;
            }
            spend += vc[i].second / vc[i].first;
        }
        long double extra = u - spend;
        if (extra < 0){
            spend += -extra;
        }
        cout << fixed << setprecision(7) << spend << endl;
    }




    return 0;
}
