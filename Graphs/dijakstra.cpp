#include <bits/stdc++.h>
using namespace std;
#define maxi 1e9
#define ll long long
vector<vector<pair<ll, ll>>> graph(1e5 + 10);
vector<ll> dist(1e5 + 10, maxi);
ll n, m;
void dijakstra()
{
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  pq.push({0, 2});
  dist[2] = 0;
  while (!pq.empty())
  {
    pair<ll, ll> temp = pq.top();
    pq.pop();
    ll wt = temp.first;
    ll source = temp.second;

    if (dist[source] < wt)
      continue;

    for (auto e : graph[source])
    {
      ll newWeight = e.second;
      ll newSource = e.first;

      if (newWeight + dist[source] < dist[newSource])
      {
        dist[newSource] = newWeight + dist[newSource];

        pq.push({dist[newSource], newSource});
      }
    }
  }
}
int main()
{
  cin >> n >> m;
  ll src, dest, weight;

  for (ll i = 0; i < m; i++)
  {
    cin >> src >> dest >> weight;
    graph[src].push_back({dest, weight});
  }

  for (ll i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }
}