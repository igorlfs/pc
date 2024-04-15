#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while ((t--) != 0) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        bool result = true;
        vector<long> counts(200);
        for (int i = 0; i < 200; ++i) {
            counts[i] = count(v.begin(), v.end(), i);
        }
        for (int i = 1; i < 200; ++i) {
            if (!(counts[i - 1] >= counts[i])) {
                result = false;
            }
        }

        result ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
