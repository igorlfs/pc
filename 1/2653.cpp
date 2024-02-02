#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> joias;

    string str;
    while (cin >> str) {
        joias.insert(str);
    }

    cout << joias.size() << endl;
}
