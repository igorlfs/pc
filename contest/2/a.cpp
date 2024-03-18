#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

using namespace std;

int main() {
    pair<int, int> p1;
    pair<int, int> p2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p1.fi >> p1.se >> p2.fi >> p2.se;
        int a = p1.fi;
        int b = p2.fi;
        if (a == b) {
            a = p1.se;
        }
        cout << a << ' ' << b << endl;
    }

    return 0;
}
