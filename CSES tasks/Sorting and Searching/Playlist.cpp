#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second
void muqtu()
{
  ll n;
  cin >> n;
  vector<ll> arr(n + 1);
  unordered_map<ll, ll> hesh(n + 1);
  ll ans = 0, start = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (hesh.find(arr[i]) != hesh.end() && hesh[arr[i]] >= start)
    {
      ans = max(ans, i - start);
      start = hesh[arr[i]] + 1;
    }
    hesh[arr[i]] = i;
  }

  ans = max(ans, n - start);
  cout << ans << endl;
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