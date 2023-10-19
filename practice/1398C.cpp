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
#define defMethod(i) (i*i)

//---------------------------------------

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s; 
    std::vector<int> v; int pref = 0;
    v.reserve(n);
    for(auto &i: s) {
        v.push_back(static_cast<int>(i - 48));
    }
    std::map<int, int> m;
    ll c = 0;
    for(int i = 0; i < n; i++) {
        pref += v[i];
        c += (ll) m[pref];
        m[pref]++;
    }
    std::cout << c << std::endl;
}

int main() {
    sync;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    std::cin >> t;
    while(t--) solve();
    return 0;
}

//---------------------------------------