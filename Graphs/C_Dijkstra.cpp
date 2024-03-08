#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
#define inf 1e18 + 1
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<bool> visited;
vector<ll> ans;

int main()
{
  ll n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  dist.assign(n + 1, inf);
  visited.assign(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    ll src, dest, weight;
    cin >> src >> dest >> weight;
    adj[src].push_back({dest, weight});
    adj[dest].push_back({src, weight});
  }

  pq.push({0, 1});
  dist[1] = 0;

  while (!pq.empty())
  {
    ll newDis = pq.top().first;
    ll newSrc = pq.top().second;
    pq.pop();

    if (visited[newSrc])
      continue;

    visited[newSrc] = true;

    for (auto child : adj[newSrc])
    {
      ll newDest = child.first;
      ll weight = child.second;

      if (dist[newSrc] + weight < dist[newDest])
      {
        dist[newDest] = dist[newSrc] + weight;
        pq.push({dist[newDest], newDest});
      }
    }
  }

  if (dist[n] == inf)
    cout << -1 << endl;
  else
  {
    ll current = n;
    while (current != 1)
    {
      ans.push_back(current);
      for (auto child : adj[current])
      {
        if (dist[current] == dist[child.first] + child.second)
        {
          current = child.first;
          break;
        }
      }
    }
    ans.push_back(1);

    reverse(ans.begin(), ans.end());

    for (ll node : ans)
      cout << node << " ";
  }
  cout << endl;

  return 0;
}
