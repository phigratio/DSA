#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll maxi = 1e6 + 1;
#define pb push_back
#define f first
#define s second

ll muqtu(ll n, ll k)
{

  if (n == 1)
    return 1;
  if (k <= (n + 1) / 2)
  {
    if (2 * k > n)
    {
      return (2 * k) % n;
    }
    else
    {
      return 2 * k;
    }
  }

  ll c = muqtu(n >> 1, k - (n + 1) / 2);
  if (n & 1)
    return 2 * c + 1;
  else
    return 2 * c - 1;
}
int main()
{
  faster;
  ll t;
  cin >> t; // t=1;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    cout << muqtu(n, k) << endl;
  }
  return 0;
}