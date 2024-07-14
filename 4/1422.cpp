#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr int MOD = 13371337;
constexpr int D = 4;

using big = long long unsigned;
using matrix = vector<vector<big>>;

void mult(matrix &a, matrix &b, matrix &c) {
    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j) {
            for (int k = 0; k < D; ++k) {
                c[i][j] += (a[i][k] % MOD * b[k][j] % MOD) % MOD;
            }
            c[i][j] = c[i][j] % MOD;
        }
    }
}

matrix exponentatiation_by_squaring(matrix &m, big e) {
    if (e == 0) return {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    matrix n = exponentatiation_by_squaring(m, e / 2);
    matrix c = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, d = c;
    mult(n, n, c);
    if (e % 2 == 1) {
        mult(c, m, d);
        return d;
    }
    return c;
}

int main() {
    int N;
    array<big, 4> a{};
    while (true) {
        cin >> N;
        if (N == 0) break;
        cin >> a[0] >> a[1] >> a[2] >> a[3];

        matrix m = {{{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
        m = exponentatiation_by_squaring(m, N - 3);

        big ans = 0;
        for (int k = 0; k < D; ++k) ans += (m[0][k] % MOD * a.at(D - 1 - k) % MOD) % MOD;
        ans = ans % MOD;

        cout << ans << endl;
    }
    return 0;
}
