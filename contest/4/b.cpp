#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int t, n, m, k;
    cin >> t;
    while ((t--) != 0) {
        cin >> n >> m >> k;
        if (n * m - 1 == k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
