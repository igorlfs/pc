#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using graph = vector<vector<int>>;

constexpr int INF = 0x3f3f3f3f;

inline int conv(string &s) {
    if (s == "XXL") return 1;
    if (s == "XL") return 2;
    if (s == "L") return 3;
    if (s == "M") return 4;
    if (s == "S") return 5;
    if (s == "XS") return 6;
    throw;
}

bool bfs(graph &rg, uint s, uint t, vector<uint> &p) {
    uint n = rg.size();
    vector<bool> vis(n);
    queue<uint> q;
    q.push(s);
    vis[s] = true;
    p[s] = -1;
    while (not q.empty()) {
        uint u = q.front();
        q.pop();
        for (uint v = 0; v < n; v++) {
            if (not vis[v] and rg[u][v] > 0) {
                if (v == t) {
                    p[v] = u;
                    return true;
                }
                q.push(v);
                p[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}

int edmond_karp(graph &g, uint s, uint t) {
    graph rg = g;
    vector<uint> p(g.size());
    int ans = 0;
    while (bfs(rg, s, t, p)) {
        int f = INF;
        for (uint v = t; v != s; v = p[v]) {
            uint u = p[v];
            f = min(f, rg[u][v]);
        }
        for (uint v = t; v != s; v = p[v]) {
            uint u = p[v];
            rg[u][v] -= f;
            rg[v][u] += f;
        }
        ans += f;
    }
    return ans;
}

int main() {
    int T, N, M;

    cin >> T;

    while ((T--) != 0) {
        cin >> N >> M;

        graph g(M + 8, vector<int>(M + 8));

        for (int i = 1; i <= 6; ++i) {
            g[0][i] = N / 6;
        }

        for (int i = 1; i <= M; ++i) {
            string s, t;

            cin >> s >> t;

            int p = conv(s);
            int q = conv(t);

            g[p][i + 6] = 1;
            g[i + 6][p] = 1;

            g[i + 6][q] = 1;
            g[q][i + 6] = 1;

            g[i + 6][M + 7] = 1;
            g[M + 7][7] = 1;
        }
        int ans = edmond_karp(g, 0, M + 7);
        ans == M ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
