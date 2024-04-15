#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    long n, q, y;
    cin >> n;
    vector<long> x(n);
    for (long i = 0; i < n; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    cin >> q;
    while ((q--) != 0) {
        cin >> y;
        long m = upper_bound(x.begin(), x.end(), y) - x.begin();
        if (m == 0) {
            if (y < x[0]) {
                cout << 0 << endl;
            } else {
                for (long i = 1; i < n; ++i) {
                    if (y < x[i]) {
                        cout << i << endl;
                        break;
                    }
                }
            }
        } else {
            for (long i = m - 1; i < n; ++i) {
                if (y < x[i]) {
                    cout << i << endl;
                    break;
                }
                if (i == n - 1) {
                    cout << n << endl;
                }
            }
        }
    }
    return 0;
}
