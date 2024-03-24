#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using big = long long;

pair<big, big> get_prime_factors(big n) {
    for (big i = 3;; i += 2) {
        if (n % i == 0) return {i, n / i};
    }
}

big power_modulo(big c, big d, big n) {
    big m = 1;
    big b = c % n;

    while (d > 0) {
        if (d % 2 == 1) m = (m * b) % n;
        b = (b * b) % n;
        d = d / 2;
    }

    return m;
}

big mod_inverse(big e, big tot) {
    big a = e % tot;
    big m = tot;
    big y = 0, x = 1;

    if (tot == 1) return 0;

    while (a > 1) {
        big q = a / tot;
        big t = tot;

        tot = a % tot, a = t;
        t = y;

        y = x - q * y;
        x = t;

        while (y < 0) y += m;
    }

    if (x < 0) x += m;

    return x;
}

int main() {
    big n, e, c;
    cin >> n >> e >> c;

    auto [p, q] = get_prime_factors(n);

    big tot = (p - 1) * (q - 1);
    big d = mod_inverse(e, tot);

    cout << power_modulo(c, d, n) << endl;

    return 0;
}
