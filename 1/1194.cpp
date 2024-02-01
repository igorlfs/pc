#include <bits/stdc++.h>

using namespace std;

void gen(const string &prefix, const string &infix) {
    char root = prefix[0];
    uint index_infix = infix.find(root);
    string left_infix = infix.substr(0, index_infix);
    string left_prefix = prefix.substr(1, index_infix);
    if (left_prefix.length() != 0) {
        gen(left_prefix, left_infix);
    }
    string right_infix = infix.substr(index_infix + 1);
    string right_prefix = prefix.substr(index_infix + 1);
    if (right_prefix.length() != 0) {
        gen(right_prefix, right_infix);
    }
    cout << root;
}

int main() {
    int num_cases;
    cin >> num_cases;
    for (int i = 0; i < num_cases; ++i) {
        int N;
        string pre, in;
        cin >> N >> pre >> in;
        gen(pre, in);
        cout << endl;
    }
}
