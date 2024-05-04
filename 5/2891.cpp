#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second

constexpr int INF = 0x3f3f3f3f;

using ll = long long;

using namespace std;

ll cross_product(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

bool is_convex(vector<pair<ll, ll>> &points) {
    ll n = (ll)points.size();
    ll last = 0;
    for (ll i = 0; i < n; i++) {
        ll cross = cross_product(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cross != 0) {
            if (cross * last < 0) return false;
            last = cross;
        }
    }
    return true;
}

double calc_area(vector<pair<ll, ll>> &points) {
    pair<double, double> A = points[0], B = points[1], C = points[2], D = points[3];
    double area1 = abs((A.fi * (B.se - C.se) + B.fi * (C.se - A.se) + C.fi * (A.se - B.se)) / 2.0);
    double area2 = abs((A.fi * (C.se - D.se) + C.fi * (D.se - A.se) + D.fi * (A.se - C.se)) / 2.0);
    return area1 + area2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<ll, ll>> p(5);

    while (true) {
        for (ll i = 0; i < 5; ++i) cin >> p[i].fi >> p[i].se;
        if (count(p.begin(), p.end(), (pair<ll, ll>)make_pair(0, 0)) == 5) break;
        double big = -INF;
        for (ll i = 0; i < 5; ++i) {
            vector<pair<ll, ll>> q;
            q.reserve(4);
            for (ll j = 0; j < 5; ++j) {
                if (i != j) q.emplace_back(p[j].first, p[j].second);
            }
            sort(q.begin(), q.end());
            do {
                if (is_convex(q)) {
                    double area = calc_area(q);
                    if (area > big) big = area;
                }
            } while (next_permutation(q.begin(), q.end()));
        }
        cout << big << endl;
    }

    return 0;
}
