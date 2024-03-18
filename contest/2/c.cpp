#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

constexpr int INF = 0x3f3f3f3f;

using namespace std;

vector<int> ord = {0, 1, 2};

int main() {
    int n;
    cin >> n;
    vector<char> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 'R') b[i] = 0;
        else if (a[i] == 'G') b[i] = 1;
        else b[i] = 2;
    }
    int c = INF;
    vector<int> d(n);
    sort(ord.begin(), ord.end());
    do {
        int s = 0;
        vector<int> v = b;
        for (int i = 0; i < n; ++i) {
            if (v[i] != ord[i % 3]) {
                v[i] = ord[i % 3];
                s++;
            }
        }
        if (s < c) {
            c = s;
            d = v;
        }
    } while (next_permutation(ord.begin(), ord.end()));

    cout << c << endl;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) a[i] = 'R';
        else if (d[i] == 1) a[i] = 'G';
        else a[i] = 'B';
        cout << a[i];
    }
    cout << endl;

    return 0;
}
