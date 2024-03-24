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
  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  ll sum = 0;
  ll res = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > res)
    {
      cout << res << endl;
      return;
    }
    else
    {
      sum += arr[i];
      res = sum + 1;
    }
  }
  cout << res << endl;
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