#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p.begin(), p.end());
    int m = p[n - 1];
    int q = p[n - 2];
    for (int i = n - 2; i >= 0; --i) {
        if (m % p[i] != 0 || (m % p[i] == 0 && p[i] == p[i + 1])) {
            q = p[i];
            break;
        }
    }

    cout << m << ' ' << q << endl;

    return 0;
}
