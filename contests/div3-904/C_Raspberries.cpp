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
    std::cin >> n >> k;
    std::vector<int> v(n, 0);
    for(auto &i: v) {
        std::cin >> i;
    }
    int curr = 1e9;
    int sum = 0, ec = 0, oc = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] % k == 0) {
            std::cout << 0 << std::endl;
            return;
        }
        curr = std::min(curr, k - (v[i] % k));
        if(v[i] % 2 == 0) ec++;
        else oc++;
    }
    if(k == 4) {
        if(ec == 0) curr = std::min(2, curr);
        else if(ec == 1) curr = std::min(1, curr);
        else if(ec > 1) curr = 0;
    }
    std::cout << curr << std::endl;
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