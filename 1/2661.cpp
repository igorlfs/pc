#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    long n, m;
    cin >> n;
    m = n;
    set<int> factors;
    if (n % 2 == 0) {
        factors.insert(2);
        while (n % 2 == 0) {
            n = n / 2;
        }
    }
    for (int i = 3; i <= sqrt(m); i += 2) {
        if (n % i == 0) {
            factors.insert(i);
            while (n % i == 0) {
                n = n / i;
            }
        }
        if (n == 1) break;
    }
    if (n != 1) factors.insert((int)n);
    cout << int(pow(2, factors.size())) - factors.size() - 1 << endl;
    return 0;
}
