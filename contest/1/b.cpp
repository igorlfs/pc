#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    int best = INF;
    int best_i = INF;

    for (int i = min_a; i <= max_a; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] > i + 1) {
                count += a[j] - i - 1;
            } else if (a[j] < i - 1) {
                count += i - 1 - a[j];
            }
        }
        if (count < best) {
            best = count;
            best_i = i;
        }
    }

    cout << best_i << ' ' << best << '\n';

    return 0;
}
