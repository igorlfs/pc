#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MAX = 1e9;

int N, C, T;

bool func(ll t, vector<int> &p) {
    ll qtd = t * T;
    ll s = 0;
    for (int i = 0; i < C; ++i) {
        ll acc = 0;
        for (ll j = s; j < N; ++j) {
            if (acc + p[j] <= qtd) {
                acc += p[j];
            } else {
                s = j;
                break;
            }
            if (j == N - 1) s = N;
        }
    }
    return s == N;
}

int main() {
    cin >> N >> C >> T;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i];

    int l = 0, r = MAX, m;
    while (l < r) {
        m = (l + r) / 2;
        func(m, p) ? r = m : l = m + 1;
    }
    cout << l << '\n';

    return 0;
}
