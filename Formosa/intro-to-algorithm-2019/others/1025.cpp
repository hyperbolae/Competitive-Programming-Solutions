#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

const int maxn = 2e3 + 5;
const ll inf = 1e18;

vector<ll> dijkstra(int src, vector<vector<pii>>& adj) {
    vector<ll> ret(maxn, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, src);

    while (!q.empty()) {
        int v = q.top().second;
        ll l = q.top().first;
        q.pop();
        if (l >= ret[v]) continue;
        ret[v] = l;
        for (auto& a : adj[v]) {
            int u = a.second;
            if (ret[u] <= ret[v] + a.first) continue;
            q.emplace(ret[v] + a.first, u);
        }
    }

    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj0(n + 1, vector<pii>());
    auto adj1 = adj0;
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        adj0[b].emplace_back(l, a);  // reverse
        adj1[a].emplace_back(l, b);  // reverse
    }

    auto minpath0 = dijkstra(0, adj0);
    auto minpath1 = dijkstra(0, adj1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += minpath0[i] + minpath1[i];
    }

    cout << ans << '\n';
    return 0;
}
