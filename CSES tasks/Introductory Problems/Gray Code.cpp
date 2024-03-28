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
  vector<string> gc;
  gc.pb("");
  for (int i = 0; i < n; i++)
  {
    ll size = gc.size();
    for (int j = size - 1; j >= 0; j--)
    {
      gc.pb(gc[j]);
    }
    size *= 2;
    for (int j = 0; j < size; j++)
    {
      if (j < gc.size() / 2)
      {
        gc[j] += "0";
      }
      else
      {
        gc[j] += "1";
      }
    }
  }
  for (int i = 0; i < gc.size(); i++)
  {
    cout << gc[i] << endl;
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