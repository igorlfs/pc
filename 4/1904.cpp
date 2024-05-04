#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr int SIZE = 64;

using ll = long long;

ll count_primes_in_range(ll l, ll r) {
    vector<bool> is_prime(r - l + 1, true);
    ll lim = (ll)sqrt(r);
    for (ll i = 2; i <= lim; ++i)
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) is_prime[j - l] = false;
    if (l == 1) is_prime[0] = false;
    return count(is_prime.begin(), is_prime.end(), true);
}

int main() {
    ll a, b;
    cin >> a >> b;
    if (a == b) cout << "?" << endl;
    else {
        ll f = abs(a - b);
        ll c = a > b ? count_primes_in_range(b, a) : count_primes_in_range(a, b);
        string n = bitset<SIZE>(f + c - 1).to_string();
        string k = bitset<SIZE>(f).to_string();
        int i;
        // Lucas' Theorem
        for (i = SIZE - 1; i >= 0; --i)
            if (k[i] > n[i]) break;
        i < 0 ? cout << "Alice" : cout << "Bob";
        cout << endl;
    }
    return 0;
}
