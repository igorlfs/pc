#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

using namespace std;

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

    int c = 0;
    for (int i = 1; i < n; ++i) {
        if (b[i] == b[i - 1]) {
            if (i < n - 1 && (b[i] + 1) % 3 == b[i + 1]) {
                b[i] = (b[i] + 2) % 3;
                c++;
            } else {
                b[i] = (b[i] + 1) % 3;
                c++;
            }
        }
    }

    cout << c << endl;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) a[i] = 'R';
        else if (b[i] == 1) a[i] = 'G';
        else a[i] = 'B';
        cout << a[i];
    }
    cout << endl;

    return 0;
}
