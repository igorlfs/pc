#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    uint ss = s.length();
    uint tt = t.length();
    int num = 0;
    for (uint i = 0; i <= ss - tt; ++i) {
        for (uint j = 0; j < tt; ++j) {
            if (t[j] == s[i + j]) break;
            if (j == tt - 1) num++;
        }
    }
    cout << num << endl;
    return 0;
}
