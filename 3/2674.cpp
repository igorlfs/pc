#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (is_prime(n)) {
            string s = to_string(n);
            if (s.find('0') == string::npos && s.find('1') == string::npos &&
                s.find('4') == string::npos && s.find('6') == string::npos &&
                s.find('8') == string::npos && s.find('9') == string::npos) {
                cout << "Super" << endl;
            } else {
                cout << "Primo" << endl;
            }
        } else {
            cout << "Nada" << endl;
        }
    }
    return 0;
}
