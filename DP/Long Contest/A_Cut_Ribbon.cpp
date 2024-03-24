#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
ll n, a, b, c;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second
vector<ll> dp(4002, -1);
ll ans = INT_MIN;
ll dyni(ll x)
{
  if (x < 0)
    return -INF;
  if (x == 0)
    return 0;

  if (dp[x] != -1)
    return dp[x];
  ll ans = 1 + max(max(dyni(x - a), dyni(x - b)), dyni(x - c));

  return dp[x] = ans;
}
void muqtu()
{

  cin >> n >> a >> b >> c;
  cout << dyni(n) << endl;
}
int main()
{
  faster;
  ll t;
  t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}