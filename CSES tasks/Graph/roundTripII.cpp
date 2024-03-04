#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e6 + 10
#define inf 1e18 + 10

vector<vector<ll>> adj;
vector<ll> dist(maxi, inf);
vector<ll> parent(maxi, -1);
ll n, m;
void bellmanFord(ll s, ll e)
{
  dist[s] = 0;
  for (int i = 1; i <= n; i++)
  {
    ll x = -1;
    for (int j = 1; j <= m; j++)
    {
    }
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    ll src, dest;
    cin >> src >> dest;
    adj[src].push_back(dest);
  }

  bellmanFord(1, n);
}