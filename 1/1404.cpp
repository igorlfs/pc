#include <bits/stdc++.h>

using namespace std;

enum State { EMPTY, OURS, THEIRS };

int X, M, N;

int func(const pair<int, int> &p, vector<vector<int>> &game) {
    int u = p.first;
    int v = p.second;
    int h = 0, j = 0, k = 0, l = 0;
    if (u + 2 < N && v + 2 < M && game[u + 1][v + 1] == THEIRS && game[u + 2][v + 2] == EMPTY) {
        vector<vector<int>> clone = game;
        clone[u][v] = EMPTY;
        clone[u + 1][v + 1] = EMPTY;
        clone[u + 2][v + 2] = OURS;
        pair<int, int> q = make_pair(u + 2, v + 2);
        h = 1 + func(q, clone);
        clone[u + 2][v + 2] = EMPTY;
        clone[u + 1][v + 1] = THEIRS;
        clone[u][v] = OURS;
    }
    if (u - 2 >= 0 && v - 2 >= 0 && game[u - 1][v - 1] == THEIRS && game[u - 2][v - 2] == EMPTY) {
        vector<vector<int>> clone = game;
        clone[u][v] = EMPTY;
        clone[u - 1][v - 1] = EMPTY;
        clone[u - 2][v - 2] = OURS;
        pair<int, int> q = make_pair(u - 2, v - 2);
        l = 1 + func(q, clone);
        clone[u - 2][v - 2] = EMPTY;
        clone[u - 1][v - 1] = THEIRS;
        clone[u][v] = OURS;
    }
    if (u - 2 >= 0 && v + 2 < M && game[u - 1][v + 1] == THEIRS && game[u - 2][v + 2] == EMPTY) {
        vector<vector<int>> clone = game;
        clone[u][v] = EMPTY;
        clone[u - 1][v + 1] = EMPTY;
        clone[u - 2][v + 2] = OURS;
        pair<int, int> q = make_pair(u - 2, v + 2);
        k = 1 + func(q, clone);
        clone[u - 2][v + 2] = EMPTY;
        clone[u - 1][v + 1] = THEIRS;
        clone[u][v] = OURS;
    }
    if (u + 2 < N && v - 2 >= 0 && game[u + 1][v - 1] == THEIRS && game[u + 2][v - 2] == EMPTY) {
        vector<vector<int>> clone = game;
        clone[u][v] = EMPTY;
        clone[u + 1][v - 1] = EMPTY;
        clone[u + 2][v - 2] = OURS;
        clone[u][v] = OURS;
        pair<int, int> q = make_pair(u + 2, v - 2);
        j = 1 + func(q, clone);
        clone[u + 2][v - 2] = EMPTY;
        clone[u + 1][v - 1] = THEIRS;
        clone[u][v] = OURS;
    }
    return max({h, j, k, l});
}

int main() {
    while (true) {
        int x;
        cin >> N >> M;
        X = ceil((double)(N * M) / 2);
        if (X == 0) break;
        vector<vector<int>> game(N, vector<int>(M));
        vector<pair<int, int>> ours;
        for (int i = 0; i < X; ++i) {
            cin >> x;
            if (x != 0) {
                int mod = i % M;
                int offset = (int)(mod >= (double)M / 2);
                int u, v;
                if (offset != 0) {
                    int aux = mod - (int)ceil((double)M / 2);
                    u = 2 * aux;
                } else {
                    u = 2 * mod;
                }
                u += offset;
                v = N - 1 - offset - 2 * (i / M);
                game[v][u] = x;
                if (x == OURS) ours.emplace_back(v, u);
            }
        }
        int best = 0;
        for (const auto &p : ours) {
            int n = func(p, game);
            if (n > best) best = n;
        }
        cout << best << '\n';
    }
    return 0;
}
