#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    int n;
    string s;
    while (true) {
        cin >> n;
        if (n == 0) break;
        getchar();
        getline(cin, s);
        int l = (int)s.length();
        int maxl = 0;
        int start = 0;
        unordered_map<char, int> freq;
        for (int end = 0; end < l; ++end) {
            freq[s[end]]++;
            while ((int)freq.size() > n) {
                char start_char = s[start];
                freq[start_char]--;
                if (freq[start_char] == 0) freq.erase(start_char);
                start++;
            }

            maxl = max(maxl, end - start + 1);
        }
        cout << maxl << '\n';
    }
    return 0;
}
