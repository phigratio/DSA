#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5 + 10
#define inf 1e18 + 10

vector<pair<ll, pair<ll, ll>>> adj;
vector<ll> dist(maxi, inf);
vector<ll> parent(maxi, -1);
ll n, m;

void bellmanFord()
{
  ll x;
  for (int i = 0; i < n; i++)
  {
    x = -1;
    for (int j = 0; j < m; j++)
    {
      ll src = adj[j].second.first;
      ll dest = adj[j].second.second;
      ll weight = adj[j].first;

      if (dist[src] + weight < dist[dest])
      {
        dist[dest] = dist[src] + weight;
        parent[dest] = src;
        x = dest;
      }
    }
  }

  if (x == -1)
    cout << "NO" << endl;
  else
  {
    vector<ll> cycle;
    ll dest = x;
    for (int i = 0; i < n; i++)
    {
      dest = parent[dest];
    }

    x = dest;
    cycle.push_back(x);

    while (x != dest or cycle.size() == 1)
    {
      x = parent[x];
      cycle.push_back(x);
    }

    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (auto vertex : cycle)
    {
      cout << vertex << " ";
    }
    cout << endl;
  }
}

#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

int main()
{
  faster;
  cin >> n >> m;
  adj.clear();
  dist.clear();
  parent.clear();
  for (int i = 0; i < m; i++)
  {
    ll src, dest, weight;
    cin >> src >> dest >> weight;

    adj.push_back({weight, {src, dest}});
  }

  for (int i = 0; i < n; i++)
  {
    parent[i] = -1;
  }

  bellmanFord();
}
