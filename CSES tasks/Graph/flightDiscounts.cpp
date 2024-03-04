#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5 + 10
#define inf 1e18 + 10

vector<vector<pair<ll, ll>>> adj;
vector<ll> dist(maxi, inf);
vector<ll> parent(maxi, -1);
ll n, m;
void dijakstra()
{
  dist[1] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 1});
  ll maxWeight = 0;
  while (!pq.empty())
  {
    pair<ll, ll> temp = pq.top();
    pq.pop();
    ll src = temp.second;

    for (auto neighbours : adj[src])
    {
      ll dest = neighbours.first;
      ll weight = neighbours.second;
      if (dist[src] + weight < dist[dest])
      {
        dist[dest] = dist[src] + weight;
        parent[dest] = src;
        pq.push({dist[dest], dest});
      }
    }
  }
}
int main()
{
  cin >> n >> m;
  ll src, dest, weight;
  for (int i = 1; i <= m; i++)
  {
    cin >> src >> dest >> weight;
    adj[src].push_back({dest, weight});
  }

  dijakstra();
  return 0;
}