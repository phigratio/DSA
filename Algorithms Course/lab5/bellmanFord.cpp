#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k, q;
vector<vector<pair<ll, ll>>> adj(1000005);
vector<ll> dist(1000005);

ll bellmanFord(ll src, ll dest)
{
  for (int i = 0; i < n; i++)
  {
    dist[i] = LLONG_MAX;
  }

  dist[src] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    bool relaxed = false; // Check if any relaxation occurred in this iteration
    for (int j = 0; j < m; j++)
    {
      ll u = adj[j][0].first;
      ll v = adj[j][0].second;
      ll weight = adj[j][1].first;

      if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
        relaxed = true;
      }
    }

    if (!relaxed) // If no relaxation occurred in this iteration, break early
      break;
  }

  for (int i = 0; i < m; i++)
  {
    ll u = adj[i][0].first;
    ll v = adj[i][0].second;

    ll weight = adj[i][1].first;

    if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v])
    {
      return LLONG_MIN;
    }
  }

  if (dist[dest] == LLONG_MAX)
    return LLONG_MIN;
  else
    return dist[dest];
}

int main()
{
  while (1)
  {
    cin >> n >> m >> q;
    if (n == 0 && m == 0 && q == 0)
    {
      break;
    }
    for (int i = 0; i < m; i++)
    {
      adj[i].clear();
      ll src, dest, weight;
      cin >> src >> dest >> weight;
      adj[i].push_back({src, dest});

      adj[i].push_back({weight, 0});
    }
    for (int i = 0; i < q; i++)
    {
      ll src, dest;
      cin >> src >> dest;
      ll res = bellmanFord(src, dest);

      if (res == LLONG_MIN)
        cout << "Impossible" << endl;
      else
        cout << res << endl;
    }
    cout << endl;
  }
  return 0;
}
