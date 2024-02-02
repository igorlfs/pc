#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    int m = 0;
    for (const char c : n) {
        m += (int)c - '0';
    }
    cout << m % 3 << endl;
    return 0;
}
