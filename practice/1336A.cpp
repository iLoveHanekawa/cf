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

class Node {
    public:
        int height = 0;
        int parent = 0;
        int index = 0;
        int children = 0;
};

void dfs(std::vector<std::vector<int>> &v, std::vector<bool> &vis, std::vector<Node> &nodes, int x, int parent) {
    vis[x] = true;
    nodes[x].height = nodes[parent].height + 1;
    for(auto i: v[x]) {
        if(vis[i]) continue;
        nodes[i].parent = x;
        nodes[x].children++;
        dfs(v, vis, nodes, i, x);
    }
    nodes[parent].children += nodes[x].children;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<bool> vis(n + 1, false);
    std::vector<Node> nodes(n + 1);
    for(int i = 0; i < n + 1; i++) {
        nodes[i].index = i;
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(v, vis, nodes, 1, 0);
    std::sort(nodes.begin() + 1, nodes.end(), [](const Node &a, const Node &b) {
        return a.height - a.children > b.height - b.children;
    });
    std::fill(vis.begin(), vis.end(), false);
    ll res = 0;
    for(int i = 1; i <= k; i++) {
        auto [height, parent, index, children] = nodes[i];
        if(vis[index]) res += height - (1 + children);
        else res += height - 1;
        vis[parent] = true;
    }
    std::cout << res;
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