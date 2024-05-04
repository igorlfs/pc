#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using big = long long unsigned;
using matrix = vector<vector<big>>;

constexpr big TOP = 1e6;

matrix exponentatiation_by_squaring(matrix &m, big e) {
    if (e == 0) return {{1, 0}, {0, 1}};
    matrix n = exponentatiation_by_squaring(m, e / 2);
    matrix c = {{0, 0}, {0, 0}}, d = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][j] += (n[i][k] % TOP * n[k][j] % TOP) % TOP;
            }
            c[i][j] = c[i][j] % TOP;
        }
    }
    if (e % 2 == 1) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    d[i][j] += (c[i][k] % TOP * m[k][j] % TOP) % TOP;
                }
                d[i][j] = d[i][j] % TOP;
            }
        }
        return d;
    }
    return c;
}

int main() {
    while (true) {
        big N, K, L;
        cin >> N >> K >> L;
        if (cin.eof()) break;
        N = N / 5;
        if (N == 0) {
            cout << setw(6) << setfill('0') << 1 << endl;
        } else if (N == 1) {
            cout << setw(6) << setfill('0') << K % TOP << endl;
        } else {
            matrix m = {{0, L % TOP}, {1, K % TOP}};
            matrix n = exponentatiation_by_squaring(m, N);
            big a = (n[0][0] % TOP + K % TOP * n[1][0] % TOP) % TOP;
            cout << setw(6) << setfill('0') << a << endl;
        }
    }
    return 0;
}
