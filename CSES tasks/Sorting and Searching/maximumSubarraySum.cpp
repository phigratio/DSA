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
  ll sum = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  ll maxi = arr[0];
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum > 0)
    {
      maxi = max(sum, maxi);
    }
    else
    {
      maxi = max(sum, maxi);
      sum = 0;
    }
  }
  cout << maxi << endl;
}
int main()
{
  faster;
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    muqtu();
  }
  return 0;
}