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
  vector<ll> ind(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    ind[arr[i]] = i;
  }
  ll ans = 1;
  for (int i = 1; i < n; i++)
  {
    if (ind[i] > ind[i + 1])
      ans++;
  }
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
