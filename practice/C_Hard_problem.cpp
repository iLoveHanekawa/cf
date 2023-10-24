#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define PR(x) std::cout << #x": " << x << "\t";
#define vPR(v) for(auto i: v) {std::cout << i << " ";} std::cout << std::endl;
#define vvPR(v) for(auto i: v){ for(auto j: i) std::cout << j << " "; std::cout << std::endl;}
inline void cflag(std::string s){std::cout << s << std::endl;}
#define en std::cout << std::endl;		
#define ll long long
#define sync std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

//---------------------------------------

void solve() {
    int n;
    std::cin >> n;
    //dp[x][j] = min cost of 'sorting' a string array of lenght x when string[x] is in state j
    // if string[x] is reversed j = 0, else j = 1;
    std::vector<int> cost(n, 0);
    for(auto &i: cost) std::cin >> i;
    std::vector<std::string> v(n);
    for(auto &i: v) std::cin >> i;
    auto rev = [](std::string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++) std::swap(s[i], s[n - 1 - i]);
        return s;
    };
    std::vector<std::pair<ll, ll>> dp(n, { 1e18, 1e18 });
    dp[0] = { 0, cost[0] };
    for(int i = 1; i < n; i++) {
        std::string revA = rev(v[i]), revB = rev(v[i - 1]);
        auto &[x, y] = dp[i];
        auto &[ox, oy] = dp[i - 1];
        if(v[i] >= v[i - 1]) x = std::min(x, ox);
        if(v[i] >= revB) x = std::min(x, oy);
        if(revA >= v[i - 1]) y = std::min(y, (ll) ox + cost[i]);
        if(revA >= revB) y = std::min(y, (ll) oy + cost[i]);
    }
    ll res = 0;
    auto &[x, y] = dp[n - 1];
    if(x == 1e18 && y == 1e18) res = -1;
    else res = std::min(x, y);
    std::cout << res << std::endl;
}

int main() {
    sync;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // std::cin >> t;
    while(t--) solve();
    return 0;
}

//---------------------------------------