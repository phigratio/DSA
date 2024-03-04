#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5 + 10
#define inf 1e18 + 10

vector<pair<ll, pair<ll, ll>>> adj;
vector<ll> dist(maxi, inf);
ll n, m;

#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

bool bellmanFord()
{

  for (int i = 1; i <= n - 1; i++)
  {

    for (int j = 0; j < m; j++)
    {
      ll src = adj[j].second.first;
      ll dest = adj[j].second.second;
      ll weight = adj[j].first;

      if (dist[src] + weight < dist[dest])
      {
        dist[dest] = dist[src] + weight;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    ll src = adj[i].second.first;
    ll dest = adj[i].second.second;
    ll weight = adj[i].first;

    if (dist[src] + weight < dist[dest])
    {
      return true;
    }
  }

  return false;
}

int main()
{
  faster;
  ll t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    adj.clear();
    dist.assign(n + 1, inf);

    for (int i = 1; i <= m; i++)
    {
      ll src, dest, weight;
      cin >> src >> dest >> weight;

      adj.push_back({weight, {src, dest}});
    }

    if (bellmanFord())
    {
      cout << "possible" << endl;
    }
    else
    {
      cout << "not possible" << endl;
    }
  }
  return 0;
}
