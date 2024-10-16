#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;

    int t, u, s;
    cin >> t >> u >> s;

    int quota = 0;

    if (a == "org"){
        quota += 4;
        goto second;
    }

    if (s >= 30){
        quota += 3;
        goto second;
    }

    if (t >= 2){
        quota += 3;
        goto second;
    }

    quota += 2;


second:

    if (u >= 30){
        quota += 1;
    }

    if (u >= 60){
        quota += 1;
    }

    cout << quota;

    return 0;
}
