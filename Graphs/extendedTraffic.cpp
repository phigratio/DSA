#include <bits/stdc++.h>
using namespace std;

const int maxi = 200001;
const long long inf = 1e18;

vector<vector<pair<int,int>>> adj;
vector<int8_t> val(maxi);
vector<long long> dist(maxi, inf);

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        long long dis = pq.top().first;
        int ind = pq.top().second;
        pq.pop();

        if (dis > dist[ind])
            continue;

        for (auto child : adj[ind]) {
            int newVer = child.first;
            long long newDis = child.second;
            if (dist[ind] + newDis < dist[newVer]) {
                dist[newVer] = dist[ind] + newDis;
                pq.push({dist[newVer], newVer});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, q;
        cin >> n;
        adj.assign(n + 1, vector<pair<int,int>>()); 
        val.resize(n + 1); 
        dist.assign(n + 1, inf);
        for (int j = 1; j <= n; j++) {
            cin >> val[j];
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            int diff = val[v] - val[u];
            diff = diff * diff * diff;
            adj[u].push_back({v, diff});
        }

        dijkstra(1);
        cout << "Case " << i << ":" << endl;

        cin >> q;

        for (int j = 0; j < q; j++) {
            int check;
            cin >> check;

            if (dist[check] < 3 || dist[check] == inf) {
                cout << "?" << endl;
            } else {
                cout << dist[check] << endl;
            }
        }

        adj.assign(maxi, vector<pair<int,int>>());
        dist.assign(maxi, inf);
    }

    return 0;
}
