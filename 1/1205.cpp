#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

const int INF = numeric_limits<int>::max();

int dijkstra(graph &graph, int src, int dst) {
    uint n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dst) return dist[u];

        for (uint v = 0; v < n; ++v) {
            if (graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.emplace(dist[v], v);
                }
            }
        }
    }

    return -1;
}

int main() {
    int N, M, K, A;
    double P;
    while (true) {
        cin >> N >> M >> K >> P;
        if (cin.eof()) break;

        graph matrix(N);
        vector<int> count(N);
        vector<pair<int, int>> pairs(M);

        for (int i = 0; i < N; ++i) {
            matrix[i].resize(N, INF);
        }
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            pairs[i] = make_pair(a - 1, b - 1);
        }
        cin >> A;
        for (int i = 0; i < A; ++i) {
            int x;
            cin >> x;
            count[x - 1]++;
        }
        int src, dst;
        cin >> src >> dst;
        for (const auto &p : pairs) {
            matrix[p.first][p.second] = count[p.second];
            matrix[p.second][p.first] = count[p.first];
        }
        int shots = dijkstra(matrix, src - 1, dst - 1);
        if (shots == -1) {
            cout << fixed << showpoint << setprecision(3) << 0. << endl;
        } else {
            shots += count[src - 1];
            shots > K
                ? cout << fixed << showpoint << setprecision(3) << 0. << endl
                : cout << fixed << showpoint << setprecision(3) << pow(P, shots)
                       << endl;
        }
    }
    return 0;
}
