#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

using ll = long long unsigned;

ll func(ll n) {
    if (n <= 9) return n * (n + 1) / 2;
    ll q = n / 10;
    ll r = n % 10;
    ll ans = (45 * q) % MOD;
    ans = (ans + (10 * func(q - 1)) % MOD) % MOD;
    ans = (ans + (r * (r + 1) / 2) % MOD) % MOD;
    ll deque = 0;
    while (q != 0) {
        deque = (deque + q % 10) % MOD;
        q = q / 10;
    }
    ans = (ans + ((r + 1) * deque) % MOD) % MOD;
    return ans;
}

int main() {
    ll a, b;
    ll c, d;
    while (true) {
        cin >> a >> b;
        if (cin.eof()) break;
        c = func(a - 1);
        d = func(b);
        cout << d - c << endl;
    }
    return 0;
}
