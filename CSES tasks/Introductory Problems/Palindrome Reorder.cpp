#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void muqtu()
{
  vector<ll> hesh(26, 0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    hesh[s[i] - 'A']++;
  }
  ll flag = 0;
  ll ind = -1;
  string fir, sec;
  for (int i = 0; i < hesh.size(); i++)
  {
    if (hesh[i] % 2 == 1)
    {
      flag++;
      ind = i;
    }
  }
  if (flag > 1)
    cout << "NO SOLUTION" << endl;
  else
  {
    for (int i = 0; i < 26; i++)
    {
      if (hesh[i] % 2 == 0)
      {
        for (int j = 0; j < hesh[i] / 2; j++)
        {
          fir += char('A' + i);
          sec += char('A' + i);
        }
      }
    }
    if (ind != -1)
    {
      for (int i = 0; i < hesh[ind]; i++)
      {
        fir += char('A' + ind);
      }
    }
    reverse(sec.begin(), sec.end());
    cout << fir + sec << endl;
  }
}

int main()
{
  faster;
  muqtu();
  return 0;
}
