#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (cin.eof()) break;
        stack<int> stack;
        queue<int> queue;
        priority_queue<int, vector<int>> pq;
        bool is_stack, is_queue, is_heap;
        is_stack = is_queue = is_heap = true;
        for (int i = 0; i < n; ++i) {
            int op, x;
            cin >> op >> x;
            if (op == 1) {
                queue.push(x);
                stack.push(x);
                pq.push(x);
            } else if (op == 2) {
                if (queue.front() != x) {
                    is_queue = false;
                }
                queue.pop();
                if (stack.top() != x) {
                    is_stack = false;
                }
                stack.pop();
                if (pq.top() != x) {
                    is_heap = false;
                }
                pq.pop();
            }
        }
        if (is_stack && !is_queue && !is_heap) {
            cout << "stack" << endl;
        } else if (!is_stack && is_queue && !is_heap) {
            cout << "queue" << endl;
        } else if (!is_stack && !is_queue && is_heap) {
            cout << "priority queue" << endl;
        } else if (!is_stack && !is_queue && !is_heap) {
            cout << "impossible" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }
}
