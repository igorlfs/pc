#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int S, B;
    while (true) {
        cin >> S >> B;
        if (S == 0 and B == 0) break;
        vector<int> X(S), Y(B);
        array<vector<int>, 2> M({vector<int>(S), vector<int>(S)});
        for (int i = 0; i < S; ++i) cin >> X[i];
        for (int i = 0; i < B; ++i) cin >> Y[i];

        int min;
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 2 * j; k < S - 1 - 2 * (B - 1 - j); k++) {
                    vector<int> &aux = M.at(j % 2);

                    aux[k] = Y[j] * (X[(i + k) % S] + X[(i + k + 1) % S]);

                    if (j > 0) aux[k] += M.at((j + 1) % 2)[k - 2];

                    if (k != j * 2) {
                        int p = aux[k];
                        int q = aux[k - 1];
                        aux[k] = p < q ? p : q;
                    }
                }
            }
            int r = M.at((B - 1) % 2)[S - 2];
            if (i == 0) min = r;
            else min = min < r ? min : r;
        }
        cout << -min << endl;
    }
    return 0;
}
