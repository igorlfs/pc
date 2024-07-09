#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ll = long long;

constexpr int MOD = 1300031;
const ll MAX = 2e6;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    ext_gcd(a, m, x, y);
    return (x % m + m) % m;
}

ll func(ll a, ll b, ll m) {
    return ((a % m) * mod_inv(b, m)) % m;
}

int main() {
    int T;
    cin >> T;

    vector<ll> f(MAX);
    f[0] = 1;
    for (ll i = 1; i < MAX; i++) {
        f[i] = (i * f[i - 1]) % MOD;
    }

    while ((T--) != 0) {
        int N, C;
        cin >> N >> C;
        cout << func(f[N + C - 1], (f[C] * f[N - 1]) % MOD, MOD) << endl;
    }

    return 0;
}
