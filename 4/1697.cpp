#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

using namespace std;

constexpr int MAX = 1e7;

vector<bool> soe(MAX + 1, true);

void sieve_of_eratosthenes(int n) {
    soe[0] = soe[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (soe[i]) {
            for (int j = i * i; j <= n; j += i) soe[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve_of_eratosthenes(MAX);
    int n, t;
    cin >> t;
    while ((t--) != 0) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int top = *max_element(v.begin(), v.end());
        set<int> s(v.begin(), v.end());
        int x = 0, m = 2;
        if (s.contains(1)) {
            for (; m <= top; ++m) {
                if (s.contains(m)) {
                    continue;
                }
                if (soe[m]) {
                    x = m - 1;
                    break;
                }
            }
            if (x == 0) {
                for (m = top + 1;; ++m) {
                    if (soe[m]) {
                        x = m - 1;
                        break;
                    }
                }
            }
        }
        cout << x << endl;
    }
    return 0;
}
