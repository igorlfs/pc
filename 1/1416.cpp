#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int T, P;

constexpr int DEFAULT_EP = 20;

struct Team {
    int id{};
    int solved{};
    int penalty{};
    int fail_attempts{};
    int time_penalty{};
};

void set_penalty(Team &t, int ep = DEFAULT_EP) {
    int sum = ep * t.fail_attempts + t.time_penalty;
    t.penalty = sum;
}

int main() {
    while (true) {
        cin >> T >> P;
        getchar();
        vector<vector<pair<int, int>>> scores(T, vector<pair<int, int>>(P));
        vector<Team> teams(T, {0, 0, 0});
        if (T == 0) break;
        for (int i = 0; i < T; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string aux;
            int solved = P;
            vector<string> v(P);
            for (int j = 0; getline(ss, aux, ' '); j++) v[j] = aux;
            for (int j = 0; j < P; ++j) {
                char c;
                stringstream curr(v[j]);
                curr >> scores[i][j].first >> c;
                if (v[j].find('-') != string::npos) {
                    solved--;
                } else {
                    curr >> scores[i][j].second;
                    teams[i].fail_attempts += scores[i][j].first - 1;
                    teams[i].time_penalty += scores[i][j].second;
                }
            }
            teams[i].solved = solved;
            teams[i].id = i;
            set_penalty(teams[i]);
        }
        auto cmp_func = [](const Team &lhs, const Team &rhs) {
            return lhs.solved > rhs.solved ||
                   (lhs.solved == rhs.solved && lhs.penalty <= rhs.penalty);
        };
        stable_sort(teams.begin(), teams.end(), cmp_func);
        vector<pair<int, Team>> ord(T);
        int idx = 0;
        ord[idx] = make_pair(idx, teams[idx]);
        for (int i = 1; i < T; ++i) {
            if (teams[i].solved < teams[i - 1].solved ||
                (teams[i].solved == teams[i - 1].solved &&
                 teams[i].penalty > teams[i - 1].penalty)) {
                idx++;
            }
            ord[i] = make_pair(idx, teams[i]);
        }
        vector<vector<int>> pk(idx + 1);
        for (int i = 0; i < T; ++i) {
            pk[ord[i].first].push_back(teams[i].id);
        }
        int bot = -1, top = -1;
        bool leave = false;
        for (int i = 1; i < 3000; ++i) {
            vector<pair<int, Team>> new_ord(T);
            vector<Team> cl = teams;
            for (auto &p : cl) {
                set_penalty(p, i);
            }
            stable_sort(cl.begin(), cl.end(), cmp_func);
            int new_idx = 0;
            new_ord[new_idx] = make_pair(new_idx, cl[new_idx]);
            for (int j = 1; j < T; ++j) {
                if (cl[j].solved < cl[j - 1].solved ||
                    (cl[j].solved == cl[j - 1].solved && cl[j].penalty > cl[j - 1].penalty)) {
                    new_idx++;
                }
                new_ord[j] = make_pair(new_idx, cl[j]);
            }
            for (int j = 0; j < T; ++j) {
                if (new_ord[j].first != ord[j].first) {
                    if (top != -1) leave = true;
                    break;
                }
                vector<int> xl = pk[ord[j].first];
                if (find(xl.begin(), xl.end(), new_ord[j].second.id) == xl.end()) {
                    if (top != -1) leave = true;
                    break;
                }
                if (j == T - 1) {
                    if (bot == -1) {
                        bot = i;
                    }
                    top = i;
                }
            }
            if ((bot != -1 && leave)) break;
        }
        cout << bot << ' ';
        top == -1 || top == 2999 ? cout << '*' : cout << top; // HACK
        cout << endl;
    }
    return 0;
}
