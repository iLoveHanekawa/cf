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
    int n, k, d;
    cin >> n >> k >> d;
    int m = 1e9 + 7;
    // dp[x][y] ways to get a path of length x at exactly height y
    vector<vector<ll>> dp(101, vector<ll>(101, 0));
    // valid[x][y] valid ways to get a path of length x at exactly height y but length of edges are < d
    vector<vector<ll>> invalid(101, vector<ll>(101, 0));
    dp[0][0] = 1;
    invalid[0][0] = 1;

    auto populate = [&n = n, &k = k, &d = d, &m = m](vector<vector<ll>> &dp) {
        for(int i = 1; i < 101; i++) {
            for(int j = 1; j <= min(100, i * k); j++) {
                for(int z = j - 1; j - z <= k && z >= 0; z--) {
                    dp[j][i] = (dp[j][i] + dp[z][i - 1]) % m;
                }
            }
        }
    };

    populate(dp);
    k = d = d - 1;
    populate(invalid);

    ll res = 0, bad = 0;
    for(int i = 1; i <= n; i++) {
        res = (res + dp[n][i]) % m; 
        bad = (bad + invalid[n][i]) % m;
    }
    auto modSub = [x = res, y = bad, n = m]() {
        return (x % n - y % n + n) % n;
    };
    cout << modSub() << endl;
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