#include <bits/stdc++.h>
using namespace std;
#define V 4
#define ll long long
#define INF 99999

void printSolution(int dist[][V])
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (dist[i][j] == INF)
      {
        cout << "INF"
             << " ";
      }
      else
      {
        cout << dist[i][j] << " ";
      }
    }
    cout << endl;
  }
}

void floydWarshall(int dist[][V])
{
  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
          if (dist[i][j] > dist[i][k] + dist[k][j] and dist[k][j] != INF and dist[i][k]!=INF)
          {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        
      }
    }
  }

  printSolution(dist);
}