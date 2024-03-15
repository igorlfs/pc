#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<pair<int, int>>>;

constexpr int INF = 0x3f3f3f3f;

vector<int> dijkstra(graph &g, int src) {
    uint n = g.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto &neighbor : g[u]) {
            if (dist[u] + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = dist[u] + neighbor.second;
                pq.emplace(dist[neighbor.first], neighbor.first);
            }
        }
    }

    return dist;
}

void dfs(graph &g, vector<bool> &v, uint i, deque<pair<int, int>> &pw,
         vector<pair<vector<int>, int>> &c) {
    v[i] = true;
    for (const auto &n : g[i]) {
        if (!v[n.first]) {
            pw.emplace_back(n.first, n.second + pw.back().second);
            dfs(g, v, n.first, pw, c);
            pw.pop_back();
        } else if (pw.size() >= 2) {
            pair<int, int> l = pw[pw.size() - 2];
            for (const auto &m : pw) {
                if (m.first == n.first && m.first != l.first) {
                    vector<int> p;
                    for (auto &j : ranges::reverse_view(pw)) {
                        if (j.first != n.first) p.push_back(j.first);
                        else {
                            p.push_back(j.first);
                            break;
                        }
                    }
                    c.emplace_back(p, pw.back().second + n.second - m.second);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, T, Q, X, M, A, B, C;
    while (true) {
        cin >> S >> T;
        if (cin.eof()) break;
        graph g(S, vector<pair<int, int>>());
        for (int i = 0; i < T; ++i) {
            cin >> A >> B >> C;
            g[A - 1].emplace_back(B - 1, C);
            g[B - 1].emplace_back(A - 1, C);
        }
        vector<bool> v(S);
        deque<pair<int, int>> pw = {{0, 0}};
        vector<pair<vector<int>, int>> c;
        dfs(g, v, 0, pw, c);
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            cin >> X >> M;
            if (none_of(c.begin(), c.end(), [&M](const auto &x) { return x.second >= M; })) {
                cout << -1 << '\n';
            } else {
                int min_dist = INF;
                vector<int> dist = dijkstra(g, X - 1);
                for (const auto &x : c) {
                    int curr = x.second;
                    if (curr < M) continue;
                    int min_curr = INF;
                    for (const auto &y : x.first) {
                        if (dist[y] < min_curr) min_curr = dist[y];
                    }
                    curr += 2 * min_curr;
                    if (curr < min_dist) min_dist = curr;
                }
                cout << min_dist << '\n';
            }
        }
    }

    return 0;
}
