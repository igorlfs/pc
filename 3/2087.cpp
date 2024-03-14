#include <bits/stdc++.h>

using namespace std;

constexpr int ALPHABET_SIZE = 26;

struct Trie {
    array<Trie *, ALPHABET_SIZE> children{};
    bool is_end_of_word{false};
};

bool insert(Trie *root, string &s) {
    Trie *aux = root;

    for (char c : s) {
        int idx = c - 'a';
        if (aux->children[idx] == nullptr) aux->children[idx] = new Trie;
        if (aux->is_end_of_word) return false;

        aux = aux->children[idx];
    }

    if (aux->is_end_of_word) return false;
    aux->is_end_of_word = true;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        sort(v.begin(), v.end(),
             [](basic_string<char> &lhs, basic_string<char> &rhs) {
                 return lhs.length() < rhs.length();
             });

        Trie *root = new Trie;
        bool is_good = true;
        for (int i = 0; i < n; ++i) {
            if (!insert(root, v[i])) {
                is_good = false;
                break;
            }
        }

        is_good ? cout << "Conjunto Bom" : cout << "Conjunto Ruim";
        putchar('\n');
    }

    return 0;
}
