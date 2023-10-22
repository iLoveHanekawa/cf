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
    sort(v.begin(), v.end());
    int sum = 0;
    bool nn = true;
    int ok = k;
    if(k == 4) k = 2;
    int fok = 0;
    for(int i = 0; i < n; i++) {
        if((i == 0 && v[i] == 1)) continue;
        if(v[i] % ok == 0 && ok != 4) {
            std::cout << "ans: " << 0 << std::endl;
            return;
        }
        else if(v[i] % k == 0 && ok == 4) {
            fok++;
        }
        curr = std::min(curr, k - (v[i] % k));
    }
    if(ok == 4) {
        if(fok % 2 == 0 && fok != 0) std::cout << "ans: " << 0 << std::endl;
        else if(fok == 0) std::cout << "ans: " << 2 << std::endl;
        else std::cout << "ans: " << 1 << std::endl;
    }
    else std::cout << "ans: " << curr << std::endl;
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