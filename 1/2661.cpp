#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n;
    m = n;
    set<ll> factors;
    if (n % 2 == 0) {
        factors.insert(2);
        while (n % 2 == 0) {
            n = n / 2;
        }
    }
    for (ll i = 3; i <= (ll)sqrt(m); i += 2) {
        if (n % i == 0) {
            factors.insert(i);
            while (n % i == 0) {
                n = n / i;
            }
        }
        if (n == 1) break;
    }
    if (n != 1) factors.insert((ll)n);
    cout << ll(pow(2, factors.size())) - factors.size() - 1 << endl;
    return 0;
}
