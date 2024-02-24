#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 506
#define inf 1e18

vector<bool> vis(maxi, false);
vector<vector<pair<ll, ll>>> adj(maxi);
ll myDest;
vector<ll> dist(maxi, inf);

void dijkstra(ll src)
{
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty())
  {
    ll cur = pq.top().second;
    ll dis = pq.top().first;
    pq.pop();
    if (dis > dist[cur])
      continue;
    for (auto child : adj[cur])
    {
      ll childVer = child.first;
      ll childDis = child.second;
      if (max(dist[cur], childDis) < dist[childVer])
      {
        dist[childVer] = max(dist[cur], childDis);
        pq.push({dist[childVer], childVer});
      }
    }
  }
}

int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    ll n, m;
    cin >> n >> m;

    fill(dist.begin(), dist.end(), inf);

    for (int j = 0; j < m; j++)
    {
      ll u, v, d;
      cin >> u >> v >> d;
      adj[u].push_back({v, d});
      adj[v].push_back({u, d});
    }
    cin >> myDest;

    dijkstra(myDest);

    cout << "Case " << i << ":" << endl;

    for (int j = 0; j < n; j++)
    {
      if (j == myDest)
        cout << 0 << endl;
      else if (dist[j] == inf)
      {
        cout << "Impossible" << endl;
      }
      else
        cout << dist[j] << endl;
    }

    adj.assign(maxi, vector<pair<ll, ll>>());
  }

  return 0;
}
