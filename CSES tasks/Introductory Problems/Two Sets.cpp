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
  vector<ll> arr1, arr;
  if (n % 4 == 1 || n % 4 == 2)
  {
    cout << "NO" << endl;
    return;
  }
  else if (n % 4 == 3)
  {
    arr.pb(1);
    arr.pb(2);
    arr1.pb(3);
    for (int i = 4; i <= n; i += 4)
    {
      arr.pb(i);
      arr1.pb(i + 1);
      arr1.pb(i + 2);
      arr.pb(i + 3);
    }
  }
  else
  {
    for (int i = 1; i <= n; i += 4)
    {
      arr.pb(i);
      arr1.pb(i + 1);
      arr1.pb(i + 2);
      arr.pb(i + 3);
    }
  }
  cout << "YES" << endl;
  cout << arr.size() << endl;
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << arr1.size() << endl;
  for (int i = 0; i < arr1.size(); i++)
  {
    cout << arr1[i] << " ";
  }
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