#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ll = long long unsigned;

int main() {
    ll t, n;
    cin >> t;
    while ((t--) != 0) {
        cin >> n;
        ll count = n;
        while (n != 1) {
            n = floor(n / 2);
            count += n;
        }
        cout << count << endl;
    }
    return 0;
}
