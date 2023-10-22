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
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::map<char, int> m;
    for(auto &i: s) {
        m[i]++;
    }
    int ef = 0, oc = 0;
    for(auto &[x, y]: m) {
        if(k == 0 && y % 2) {
            oc++;
        }
        else if(y % 2 == 1) {
            y -= 1;
            k -= 1;
        }
        ef += y;
    }
    bool res = 0;
    if(oc <= 1 and k == 0 || oc <= 1 && ef >= k) res = 1;
    std::cout << (res? "YES": "NO") << std::endl;
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