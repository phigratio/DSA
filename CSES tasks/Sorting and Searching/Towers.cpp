#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void muqtu()
{
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  multiset<ll> tops;
  for (int i = 0; i < n; i++)
  {
    auto it = tops.upper_bound(arr[i]);
    if (it == tops.end())
    {
      tops.insert(arr[i]);
    }
    else
    {
      tops.erase(it);
      tops.insert(arr[i]);
    }
  }
  cout << tops.size() << endl;
  return;
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
