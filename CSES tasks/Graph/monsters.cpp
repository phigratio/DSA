#include <bits/stdc++.h>
const int maxi = 1e5 + 1;
int n, m;
int si, sj, ti, tj;
char dc[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[1001][1001];
string matrix[1001];
vector<pair<int, int>> monster;
vector<vector<int>> adj;
map<pair<int, int>, pair<int, int>> par_mp;

pair<int, int> si, se;

string step = "";
using namespace std;
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> matrix[i];
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 'A')
      {
        si = i;
        sj = j;
      }
    }
  }
}