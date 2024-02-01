#include <bits/stdc++.h>

using namespace std;

constexpr int MULTIPLIER = 100;

int tab(const vector<int> &X, const int Y, const int Z, const int L,
        const int K) {
    if (Y % L == 0) {
        int t = 0;
        int num_places = Y / L;
        int places = 0;
        int j = -1;
        for (int i = K - 1; places < num_places; --i) {
            if (i < 0) return -1;
            for (; j < i; ++j) {
                int aux = j == -1 ? 0 : X[j];
                if (X[i] + aux == Z) {
                    places++;
                    t++;
                    if (aux != 0) t++;
                    if (j != -1) j++;
                    break;
                } else if (X[i] + aux > Z) break;
            }
        }
        if (places != num_places) return -1;
        return t;
    } else {
        return -1;
    }
}

int main() {
    while (true) {
        int M, N;
        cin >> M >> N;
        if (M == 0 && N == 0) break;
        M *= MULTIPLIER;
        N *= MULTIPLIER;
        int L, K;
        cin >> L >> K;
        vector<int> X(K);
        for (int i = 0; i < K; ++i) {
            cin >> X[i];
            X[i] *= MULTIPLIER;
        }
        sort(X.begin(), X.end());
        int m = tab(X, M, N, L, K);
        int n = tab(X, N, M, L, K);
        if (m != -1 && (m < n || n == -1)) {
            cout << m << endl;
        } else if (n != -1 && (n <= m || m == -1)) {
            cout << n << endl;
        } else {
            cout << "impossivel" << endl;
        }
    }
}
