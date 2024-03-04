#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxi 2005
#define inf 1e18 + 10

vector<pair<ll, pair<ll, ll>>> adj(maxi);
vector<vector<ll>> adj2(2005);
vector<ll> dist(maxi, inf);
vector<bool> visited(maxi, 0);
vector<bool> isRelaxed(maxi, 0);
ll n, m;
ll cas = 1;

#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void dfs(int x)
{
  visited[x] = 1;

  for (auto i : adj2[x])
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
}

void bellmanFord(ll s, ll n)
{
  dist[s] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      ll src = adj[j].second.first;
      ll dest = adj[j].second.second;
      ll weight = adj[j].first;

      if (dist[src] + weight < dist[dest])
      {
        dist[dest] = dist[src] + weight;
        if (i == n)
        {
          isRelaxed[dest] = 1;
        }
      }
    }
  }
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
    adj2.clear();
    adj.resize(maxi);
    adj2.resize(maxi);
    dist.assign(maxi, inf);
    visited.clear();
    visited.assign(maxi, 0);
    isRelaxed.clear();
    isRelaxed.assign(maxi, 0);

    for (int i = 1; i <= m; i++)
    {
      ll src, dest, weight;
      cin >> src >> dest >> weight;
      src++, dest++;
      adj[i] = {weight, {dest, src}};
      adj2[dest].push_back(src);
    }

    bellmanFord(1, n);
    bool done = 0;
    for (int i = 1; i <= n; i++)
    {
      if (isRelaxed[i])
      {
        dfs(i);
        done = 1;
      }
    }

    if (done == 0)
      cout << "Case " << cas << ": "
           << "impossible\n";
    else
    {
      cout << "Case " << cas << ":";
      for (int i = 1; i <= n; i++)
      {
        if (visited[i])
        {
          cout << " " << i - 1;
        }
      }

      cout << endl;
    }
    cas++;
  }
  return 0;
}
