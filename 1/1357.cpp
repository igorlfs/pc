#include <bits/stdc++.h>

using namespace std;

int main() {
    const map<string, int> brailleToNum = {
        {"*.....", 1}, {"*.*...", 2}, {"**....", 3}, {"**.*..", 4},
        {"*..*..", 5}, {"***...", 6}, {"****..", 7}, {"*.**..", 8},
        {".**...", 9}, {".***..", 0},
    };
    const vector<string> numToBraille = {".***..", "*.....", "*.*...", "**....",
                                         "**.*..", "*..*..", "***...", "****..",
                                         "*.**..", ".**..."};
    const uint size = numToBraille[0].length();
    int n;
    char c;
    while (true) {
        cin >> n >> c;
        if (cin.eof()) break;
        if (c == 'S') {
            string s;
            cin >> s;
            for (uint i = 0; i < size; i += 2) {
                for (uint j = 0; j < s.length(); ++j) {
                    cout << numToBraille[(int)s[j] - '0'].substr(i, 2);
                    if (j != s.length() - 1) {
                        cout << ' ';
                    }
                }
                cout << endl;
            }
        } else if (c == 'B') {
            getchar();
            vector<string> v(n);
            string s;
            for (int i = 0; i < 3; ++i) {
                getline(cin, s);
                stringstream sstream(s);
                int j = 0;
                while (getline(sstream, s, ' ')) {
                    v[j] += s;
                    j++;
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << brailleToNum.at(v[i]);
            }
            cout << endl;
        }
    }
    return 0;
}
