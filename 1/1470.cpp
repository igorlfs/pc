#include <bits/stdc++.h>

using namespace std;

int n, m, maxx;
vector<int> u, w;

bool fold(vector<int> v, const bool left = true) {
    const int sv = (int)v.size();
    if (sv < m) return false;
    for (int i = 0; i < sv; ++i) {
        vector<int> x(&v[0], &v[i]);
        vector<int> y(&v[i], &v[sv]);
        left ? reverse(y.begin(), y.end()) : reverse(x.begin(), x.end());
        int size = max(i, sv - i);
        if (size < m) continue;
        bool b = i > sv - i;
        int diff = b ? i - (sv - i) : sv - i - i;
        vector<int> z(size);
        if (b) {
            for (int j = 0; j < size; ++j) {
                z[j] = x[j];
            }
            if (left) {
                for (int j = 0; j < size - diff; ++j) {
                    z[j] += y[j];
                }
            } else {
                for (int j = 0; j < sv - i; ++j) {
                    z[j] += y[j];
                }
            }
        } else {
            for (int j = 0; j < size; ++j) {
                z[j] = y[j];
            }
            if (left) {
                for (int j = 0; j < size - diff; ++j) {
                    z[j] += x[j];
                }
            } else {
                for (int j = 0; j < i; ++j) {
                    z[j] += x[j];
                }
            }
        }
        int maxy = *max_element(z.begin(), z.end());
        if (maxy > maxx) continue;
        if (size == m) {
            if (z == u || z == w) {
                return true;
            }
        }
        if (size != sv) {
            if (fold(z)) {
                return true;
            };
            if (fold(z, false)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> v;
    while (true) {
        cin >> n;
        if (cin.eof()) break;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cin >> m;
        u.resize(m);
        w.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> u[i];
            w[m - i] = u[i];
        }
        maxx = *max_element(u.begin(), u.end());
        bool b = reduce(v.begin(), v.end()) == reduce(u.begin(), u.end());
        if (b) b = fold(v) || fold(v, false);
        b ? cout << 'S' : cout << 'N';
        cout << endl;
    }
    return 0;
}
