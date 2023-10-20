#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define PR(x) cout << #x": " << x << "\t";
#define vPR(v) for(auto i: v) {cout << i << " ";} cout << endl;
#define vvPR(v) for(auto i: v){ for(auto j: i) cout << j << " "; cout << endl;}
inline void cflag(string s){cout << s << endl;}
#define en cout << endl;		
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define defMethod(i) (i*i)

//---------------------------------------

void solve() {
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<ll, ll>> v(n);
    for(auto &&[x, y]: v) cin >> x >> y;

    auto pyth = [] (ll x, ll y) {
        return (ll) x * x + y * y;
    };
 
    auto xy = [&] (ll xi, ll yi, ll x, ll y) {
        return pyth(xi - x, yi - y);
    };

    ll res1 = 1e18;
    ll res2 = res1;

    for(int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        ll someMax = 0;
        ll dis1 = xy(x1, y1, a, b);
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            auto [x, y] = v[j];
            ll dis11 = xy(x1, y1, x, y);
            if(dis11 < dis1) continue;
            else someMax = max(someMax, (ll) xy(x2, y2, x, y));
        }
        res1 = min(res1, someMax + dis1);
    }
    for(int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        ll someMax = 0;
        ll dis1 = xy(x2, y2, a, b);
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            auto [x, y] = v[j];
            ll dis11 = xy(x2, y2, x, y);
            if(dis11 < dis1) continue;
            else someMax = max(someMax, (ll) xy(x1, y1, x, y));
        }
        res2 = min(res2, someMax + dis1);
    }
    cout << min(res1, res2) << endl;
}

int main() {
    sync;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

//---------------------------------------
