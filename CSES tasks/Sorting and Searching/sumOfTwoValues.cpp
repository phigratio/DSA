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
  ll n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> arr(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i].f;
    arr[i].s = i;
  }
  sort(arr.begin(), arr.end());
  ll i = 1;
  ll j = n;
  while (i < j)
  {
    if (arr[i].f + arr[j].f == x)
    {
      cout << arr[i].s << " " << arr[j].s << endl;
      return;
    }
    else if (arr[i].f + arr[j].f > x)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return;
}
int main()
{
  faster;
  ll t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}