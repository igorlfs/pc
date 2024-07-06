#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr int INF = 0x3f3f3f3f;

struct Dinic {
    struct Edge {
        int to, cap, rev, flow{};
        bool res;
        Edge(int to_, int cap_, int rev_, bool res_) : to(to_), cap(cap_), rev(rev_), res(res_) {}
    };

    vector<vector<Edge>> g;
    vector<int> lev, beg;
    int F{};
    Dinic(int n) : g(n) {}

    void add(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size() - 1, true);
    }

    bool bfs(int s, int t) {
        lev = vector<int>(g.size(), -1);
        lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q;
        q.push(s);
        while (q.size() != 0) {
            int u = q.front();
            q.pop();
            for (auto &i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }

    int dfs(int v, int s, int f = INF) {
        if (f == 0 or v == s) return f;
        for (int &i = beg[v]; i < (int)g[v].size(); i++) {
            auto &e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            int m = dfs(e.to, s, min(f, e.cap - e.flow));
            if (m == 0) continue;
            e.flow += m, g[e.to][e.rev].flow -= m;
            return m;
        }
        return 0;
    }

    int max_flow(int s, int t) {
        while (bfs(s, t))
            while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

int main() {
    int N, M, s, x;
    while (true) {
        cin >> N >> M;

        if (cin.eof()) break;

        s = N + M + 2;

        Dinic dinic = Dinic(s);
        vector<int> C(N), P(M), B(M);
        int aux = 0;

        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            dinic.add(i + M + 1, s - 1, C[i]);
        }

        for (int i = 0; i < M; ++i) cin >> P[i];

        for (int i = 0; i < M; ++i) {
            cin >> B[i];
            aux += B[i];
            dinic.add(0, i + 1, B[i]);

            for (int j = 0; j < P[i]; ++j) {
                cin >> x;
                dinic.add(i + 1, M + x, INF);
            }
        }

        int f = dinic.max_flow(0, s - 1);

        cout << aux - f << endl;
    }
    return 0;
}
