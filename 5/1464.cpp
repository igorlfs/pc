#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ll = long long;

struct Point {
    ll x, y;
    bool operator<(const Point &p) const { return (x < p.x) || (x == p.x && y < p.y); }
};

ll cross_product(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

vector<Point> convex_hull(vector<Point> &points) {
    uint n = points.size();
    if (n <= 1) return points;

    vector<Point> hull;

    for (const auto &p : points) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    uint h = hull.size() + 1;
    for (auto &p : ranges::reverse_view(points)) {
        while (hull.size() >= h && cross_product(hull[hull.size() - 2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    hull.pop_back();
    return hull;
}

bool is_in_side(const Point &p, const Point &A, const Point &B) {
    return (min(A.x, B.x) <= p.x && p.x <= max(A.x, B.x) && min(A.y, B.y) <= p.y &&
            p.y <= max(A.y, B.y) && cross_product(A, B, p) == 0);
}

void del_points(vector<Point> &points, const vector<Point> &hull) {
    set<Point> s(hull.begin(), hull.end());

    auto it = points.begin();
    while (it != points.end()) {
        bool bound_check = false;
        for (uint i = 0; i < hull.size(); ++i) {
            uint next = (i + 1) % hull.size();
            if (is_in_side(*it, hull[i], hull[next])) {
                bound_check = true;
                break;
            }
        }
        if (s.find(*it) != s.end() || bound_check) {
            it = points.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        vector<Point> P(N);
        vector<bool> in_hull(N);
        for (int i = 0; i < N; ++i) cin >> P[i].x >> P[i].y;
        set<Point> s(P.begin(), P.end());
        P.assign(s.begin(), s.end());
        sort(P.begin(), P.end());
        vector<Point> rp = P;
        int layer = 0;
        while (rp.size() >= 3) {
            layer++;
            vector<Point> hull = convex_hull(rp);

            del_points(rp, hull);
        }
        const string message =
            layer % 2 == 0 ? "Do not take this onion to the lab!" : "Take this onion to the lab!";
        cout << message << endl;
    }

    return 0;
}
