#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.second < b.second;
}

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> values(n);

  for (int i = 0; i < n; i++)
  {
    cin >> values[i].first;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> values[i].second;
  }

  sort(values.begin(), values.end(), compare);

  int N = values.size();
  if (N <= 1)
  {
    cout << N << endl;
    return 0;
  }

  int count = 1;
  int currEnd = values[0].second;

  for (int i = 1; i < N; i++)
  {
    if (values[i].first > currEnd)
    {
      count++;
      currEnd = values[i].second;
    }
  }

  cout << count << endl;

  return 0;
}
