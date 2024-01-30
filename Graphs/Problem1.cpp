#include<bits/stdc++.h>
using namespace std;
int findMinMoves(int start, int end,int arr[],int n)
{
  int visited[end+1];
  visited[start] =1;
  queue<pair<int,int>> q;
  q.push(make_pair(start,0));
  while(!q.empty())
  {
    int node=q.front().first;
    int steps=q.front().second;
    q.pop();
    if(node==end) return steps;

    for(int i=0; i<n; i++)
    {
      int dest=node*arr[i];
      if(dest==end and !visited[dest]) 
      {
        visited[dest]=1;
        q.push(make_pair(dest,steps+1));
      }

    }
  }
  return -1;
}
int main()
{

}