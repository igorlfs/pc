#include <bits/stdc++.h>

using namespace std;

constexpr double EPSILON = 1e-4;
const vector<double> NOTAS = {100, 50, 20, 10, 5, 2};
const vector<double> MOEDAS = {1, 0.5, 0.25, 0.10, 0.05, 0.01};

int main() {
    double n;
    cin >> n;
    cout << "NOTAS:" << endl;
    for (const double N : NOTAS) {
        int notas = 0;
        while (n - N >= 0) {
            n -= N;
            notas++;
        }
        cout << notas << " nota(s) de R$ " << fixed << showpoint
             << setprecision(2) << N << endl;
    }
    cout << "MOEDAS:" << endl;
    for (const double M : MOEDAS) {
        int moedas = 0;
        while (n - M >= -EPSILON) {
            n -= M;
            moedas++;
        }
        cout << moedas << " moeda(s) de R$ " << fixed << showpoint
             << setprecision(2) << M / MOEDAS[0] << endl;
    }
}
