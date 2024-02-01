#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

void dfs(graph &adj_matrix, vector<bool> &visited, int idx) {
    visited[idx] = true;
    for (const int neighbor : adj_matrix[idx]) {
        if (!visited[neighbor]) {
            dfs(adj_matrix, visited, neighbor);
        }
    }
}

int main() {
    int num_cases;
    cin >> num_cases;
    for (int i = 0; i < num_cases; ++i) {
        int component_count = 0;
        int num_vertices, num_edges;
        cin >> num_vertices >> num_edges;
        graph adj_matrix(num_vertices);
        for (int j = 0; j < num_edges; ++j) {
            char u, v;
            cin >> u >> v;
            adj_matrix[(int)u - 'a'].push_back((int)v - 'a');
            adj_matrix[(int)v - 'a'].push_back((int)u - 'a');
        }
        cout << "Case #" << i + 1 << ":" << endl;
        vector<bool> visited(num_vertices, false);
        for (int j = 0; j < num_vertices; ++j) {
            bool changed = false;
            vector<bool> prev_visited = visited;
            if (!visited[j]) {
                dfs(adj_matrix, visited, j);
            }
            for (int k = 0; k < num_vertices; ++k) {
                if (!prev_visited[k] && visited[k]) {
                    cout << char(k + 'a') << ',';
                    changed = true;
                }
            }
            if (changed) {
                cout << endl;
                component_count++;
            }
        }
        cout << component_count << " connected components" << endl << endl;
    }
}
