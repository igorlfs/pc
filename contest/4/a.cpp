#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while ((t--) != 0) {
        cin >> n;
        vector<int> r(10), b(10);
        string red, blue;
        cin >> red >> blue;
        for (const char c : red) {
            r[(int)c - '0']++;
        }
        for (const char c : blue) {
            b[(int)c - '0']++;
        }
        int sr = 0, sb = 0;
        for (int i = 0; i < n; ++i) {
            if (red[i] > blue[i]) sr++;
            else if (blue[i] > red[i]) sb++;
        }
        if (sr > sb) {
            cout << "RED" << endl;
        } else if (sb > sr) {
            cout << "BLUE" << endl;
        } else {
            cout << "EQUAL" << endl;
        }
    }
    return 0;
}
