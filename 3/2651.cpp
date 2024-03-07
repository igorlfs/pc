#include <bits/stdc++.h>

using namespace std;

const string SEEK = "zelda";

int main() {
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    if (s.find(SEEK) == string::npos) {
        cout << "Link Tranquilo" << endl;
    } else {
        cout << "Link Bolado" << endl;
    }
    return 0;
}
