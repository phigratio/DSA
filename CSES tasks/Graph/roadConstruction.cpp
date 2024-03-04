#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5 + 10
vector<pair<ll, pair<ll, ll>>> adj;
vector<ll> renk(maxi);
vector<ll> parent(maxi);
ll n, m;
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void DSU()
{
  for (int i = 0; i < n; i++)
  {
    renk[i] = 1;
    parent[i] = -1;
  }
}

int find(ll x)
{
  if (parent[x] == -1)
  {
    return x;
  }

  return parent[x] = find(parent[x]);
}

ll join(ll a, ll b)
{
  a = find(a);
  b = find(b);

  if (a == b)
  {
    return renk[a];
  }
  else if (renk[a] > renk[b])
  {
    renk[a] += renk[b];
    parent[b] = a;
    return renk[a];
  }
  else
  {
    renk[b] += renk[a];
    parent[a] = b;
    return renk[b];
  }
}
int main()
{
  ll a, b;
  cin >> n >> m;

  ll cases = n;
  ll mexi = 1;
  DSU();
  while (m--)
  {
    cin >> a >> b;

    if (find(a) != find(b))
    {
      mexi = max(mexi, join(a, b));
      cases--;
    }

    cout << cases << " " << mexi << endl;
  }
}