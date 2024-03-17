#include <bits/stdc++.h>

using namespace std;

const string ORDER = "A23456789DQJK";

int main() {
    uint N, K;

    cin >> N >> K;
    vector<vector<int>> hands(N, vector<int>(4 + 1, -1));
    string s;
    for (uint i = 0; i < N; ++i) {
        cin >> s;
        for (uint j = 0; j < s.size(); ++j) {
            hands[i][j] = (int)ORDER.find(s[j]);
        }
    }
    uint joker = K - 1;
    bool can_pass = false;
    for (uint i = 0; i < N; ++i) {
        set<int> cards;
        copy_if(hands[i].begin(), hands[i].end(), inserter(cards, cards.end()),
                [](int i) { return i != -1; });

        if (joker != i && cards.size() == 1) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    for (uint i = K - 1;; ++i) {
        const uint mod = i % N;

        set<int> cards;
        copy_if(hands[mod].begin(), hands[mod].end(), inserter(cards, cards.end()),
                [](int i) { return i != -1; });

        if (joker == mod) {
            if (can_pass) {
                joker = (mod + 1) % N;
                can_pass = false;
                if (cards.size() == 1) {
                    cout << mod + 1 << '\n';
                    break;
                }
                continue;
            } else {
                can_pass = true;
            }
        }

        vector<pair<int, int>> counts;
        counts.reserve(cards.size());
        for (const auto &c : cards) {
            counts.emplace_back(c, count(hands[mod].begin(), hands[mod].end(), c));
        }
        int mini = min_element(counts.begin(), counts.end(),
                               [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
                                   return lhs.second < rhs.second ||
                                          (lhs.second == rhs.second && lhs.first < rhs.first);
                               })
                       ->first;
        auto it = find(hands[mod].begin(), hands[mod].end(), mini);
        int idx = (int)distance(hands[mod].begin(), it);

        uint new_mod = (mod + 1) % N;
        auto it2 = find(hands[new_mod].begin(), hands[new_mod].end(), -1);
        int idx2 = (int)distance(hands[new_mod].begin(), it2);

        hands[new_mod][idx2] = mini;
        hands[mod][idx] = -1;

        set<int> new_cards;
        copy_if(hands[mod].begin(), hands[mod].end(), inserter(new_cards, new_cards.end()),
                [](int i) { return i != -1; });

        if (joker != mod && new_cards.size() == 1) {
            cout << mod + 1 << '\n';
            break;
        }
    }
    return 0;
}
