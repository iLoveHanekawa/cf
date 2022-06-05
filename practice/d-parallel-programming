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
    //brute?
    int n, k;
    cin >> n >> k;
    int skips = 1;
    auto print = [] (vector<int> v) {
        for(auto i: v) cout << i << ' ';
        cout << endl;
    };
    for(int i = 0; i < k; i++) {
        vector<int> v(n, n);
        int x = 0;
        for(int j = n - 2 - skips; j > -1; j--) {
            v[j] = n - 1 - x;
            x++;
        }
        skips *= 2;
        print(v);
    }

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
