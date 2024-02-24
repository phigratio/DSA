#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<int> busy(n);
        for (int i = 0; i < n; i++)
            cin >> busy[i];
        
        vector<vector<pair<int, int>>> adj(n);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int diff = busy[v] - busy[u];
            adj[u].push_back({v, diff * diff * diff});
        }

        int q;
        cin >> q;
        cout << "Case " << tc << ":" << endl;
        for (int i = 0; i < q; i++) {
            int dest;
            cin >> dest;
            dest--;
            
            vector<int> dist(n, inf);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, 0}); // {distance, junction}
            dist[0] = 0;

            while (!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d > dist[u]) continue;

                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            if (dist[dest] == inf || dist[dest] < 3)
                cout << "?" << endl;
            else
                cout << dist[dest] << endl;
        }
    }
    return 0;
}
