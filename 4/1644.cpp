#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 and M == 0) break;

        vector<int> P(N);
        string s, t;

        for (int i = 0; i < N; ++i) cin >> P[i];

        getchar();
        getline(cin, s);

        vector<bool> v(N);
        vector<vector<int>> m;

        for (int i = 0; i < N; ++i) {
            if (v[i]) continue;

            vector<int> q;

            for (int j = i; not v[j]; j = P[j] - 1) {
                v[j] = true;
                q.push_back(j);
            }

            m.push_back(q);
        }

        for (auto &u : m) {
            int w = (int)u.size();
            int x = M % w;

            for (int i = 0; i < x; ++i) {
                t = s;
                for (int j = 0; j < w; ++j) {
                    s[P[u[j]] - 1] = t[u[j]];
                }
            }
        }

        cout << s << endl;
    }
    return 0;
}
