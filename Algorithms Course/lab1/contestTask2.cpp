#include <bits/stdc++.h>
#define ll long long
using namespace std;

int countInversions(const string &s, int n)
{
  int inversion = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'A')
    {
      continue;
    }
    for (int j = i + 1; j < n; j++)
    {
      if (s[i] > s[j])
      {
        inversion++;
      }
    }
  }
  return inversion;
}

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
  return a.second < b.second;
}

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n, m;
    cin >> n >> m;

    vector<pair<string, int>> strings;

    for (int i = 0; i < m; i++)
    {
      string current_string;
      cin >> current_string;
      int inversion = countInversions(current_string, n);
      strings.push_back({current_string, inversion});
    }

    sort(strings.begin(), strings.end(), compare);

    for (const auto &pair : strings)
    {
      cout << pair.first << endl;
    }
  }

  return 0;
}
