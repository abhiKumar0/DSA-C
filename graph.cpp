#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;
// #define n = 5;
vector<vector<int>> adj;

void bfs(int source, int n) {
  vector<bool> visited(n, false);
  queue<int> q;
  visited[source] = true;
  q.push(source);

  while (!q.empty()){
    int node = q.front();
    q.pop();
    cout<<node<<" ";
    for (auto next: adj[node]){
      if (!visited[next]){
        visited[next] = true;
        q.push(next);
      }
    }
  }
}


int main()
{
  // vector<int> v(5);
  int n = 5;
  adj.resize(n);
  int a; int b;
  for (int i = 0; i < n-1; i++) {
    cin >>a >>b;
    // adj[0].push_back(1);
    // adj[1].push_back(0);

    // adj[0].push_back(2);
    // adj[2].push_back(0);
    
    // adj[1].push_back(3);
    // adj[3].push_back(1);
    adj[a].push_back(b);
    adj[b].push_back(a);
  // cout <<adj[1][3]<<endl;
    
  }
  int source = 0;
  bfs(source, n);
  return 0;
}