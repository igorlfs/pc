#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using graph = vector<vector<int>>;

int N, M, K;

void dfs(graph &g, vector<bool> &visited, int idx) {
    visited[idx] = true;
    for (const int neighbor : g[idx]) {
        if (!visited[neighbor]) {
            dfs(g, visited, neighbor);
        }
    }
}

bool wrapper(graph &g, int idx) {
    vector<bool> visited(K + 4);
    dfs(g, visited, idx);
    return (visited[K + 2] || visited[K + 3]);
}

double func(pair<int, int> a, pair<int, int> b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main() {
    cin >> N >> M >> K;
    vector<pair<int, int>> coords(K);
    vector<int> r(K);
    vector<vector<int>> g(K + 4);
    for (int i = 0; i < K; ++i) cin >> coords[i].first >> coords[i].second >> r[i];
    for (int i = 0; i < K; ++i) {
        for (int j = i + 1; j < K; ++j) {
            if (func(coords[i], coords[j]) <= pow(r[i] + r[j], 2)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        if (coords[i].first - r[i] <= 0) {
            g[i].push_back(K);
            g[K].push_back(i);
        }
    }
    for (int i = 0; i < K; ++i) {
        if (coords[i].second + r[i] >= M) {
            g[i].push_back(K + 1);
            g[K + 1].push_back(i);
        }
    }
    for (int i = 0; i < K; ++i) {
        if (coords[i].first + r[i] >= N) {
            g[i].push_back(K + 2);
            g[K + 2].push_back(i);
        }
    }
    for (int i = 0; i < K; ++i) {
        if (coords[i].second - r[i] <= 0) {
            g[i].push_back(K + 3);
            g[K + 3].push_back(i);
        }
    }
    if (wrapper(g, K) || wrapper(g, K + 1)) {
        cout << 'N' << endl;
    } else {
        cout << 'S' << endl;
    }
    return 0;
}
