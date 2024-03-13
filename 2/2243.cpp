#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m = 0;
    cin >> n;
    vector<int> v(n), l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 1; i < n; ++i) l[i] = min(v[i], l[i - 1] + 1);
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) r[i] = min(v[i], r[i + 1] + 1);
    for (int i = 0; i < n; ++i) m = max(m, min(l[i], r[i]));
    cout << m << '\n';
    return 0;
}
