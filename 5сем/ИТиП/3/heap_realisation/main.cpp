#include <iostream>

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <set>

typedef   uint32_t    u32;

using namespace std;
unsigned int in_u32(void) { u32 c, x = 0; while (c = _getchar_nolock(), c < 48 || c > 57); while (47 < c && c < 58) { x = x * 10 + c - 48; c = _getchar_nolock(); } return x; }
int main(){
    int n;

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    set<int> st;

    while(n--){
        char s = _getchar_nolock();

        if (s == '?'){
            auto e = st.begin();
            _getchar_nolock();
            cout << *e << '\n';
            st.erase(e);
        }

        if (s == '+'){
            _getchar_nolock();
            int e = in_u32();
            st.insert(e);
        }
    }
}
