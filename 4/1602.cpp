#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    vector<int> n, m;
    map<int, int> q;
    int x;
    while (cin >> x) n.push_back(x);
    m = n;
    sort(n.begin(), n.end());
    int prev_primes = 0;
    int start = 3;
    for (int i : n) {
        int squares = floor(sqrt(i));
        int max_squares = squares;
        for (int j = 6; j <= max_squares; ++j) {
            map<int, int> d;
            int idx = j;
            while (idx % 2 == 0) {
                idx = idx / 2;
                d[2]++;
            }
            while (idx % 3 == 0) {
                idx = idx / 3;
                d[3]++;
            }
            for (int k = 5; k <= idx; k += 6) {
                while (idx % k == 0) {
                    idx = idx / k;
                    d[k]++;
                }
                while (idx % (k + 2) == 0) {
                    idx = idx / (k + 2);
                    d[k + 2]++;
                }
            }
            int prod = 1;
            for (const auto &k : d) {
                prod = prod * (k.second + k.second + 1);
            }
            if (!is_prime(prod)) squares--;
        }
        squares--;
        int primes = prev_primes;
        for (int j = start; j <= i; j++) {
            if (is_prime(j)) primes++;
        }
        start = i + 1;
        prev_primes = primes;
        q[i] = primes + squares + 1; // Add n=2
    }
    for (const auto &k : m) {
        cout << q[k] << '\n';
    }
    return 0;
}
