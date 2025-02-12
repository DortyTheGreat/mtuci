#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

signed main()
{


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        map<int, int> mp;
        vector<int> v;

        for(int i = 0; i < n; ++i){
            int val;
            cin >> val;
            mp[val]++;
            if (mp[val] == 2){
                mp[val] = 0;
                v.push_back(val);
            }
        }

        sort(v.begin(), v.end());
        if (v.size() < 4){
            cout << "NO" << endl;
            continue;
        }
        n = v.size();
        if ((v[n-1] - v[0]) * (v[n-2] - v[1]) > (v[n-1] - v[1]) * (v[n-2] - v[0]) ){
            cout << "YES" << endl;
            cout << v[n-1] << " " << v[n-2] << " "    << v[n-1] << " " << v[1] << " " <<  \
                    v[0]   << " " << v[n-2] << " "    << v[0] << " " <<   v[1] << endl;
        }else{
            cout << "YES" << endl;
            cout << v[n-1] << " " << v[n-2] << " "    << v[n-1] << " " << v[0] <<  " " <<   \
                    v[1]   << " " << v[n-2] << " "    << v[1] << " " <<   v[0] << endl;
        }



    }
    return 0;
}
