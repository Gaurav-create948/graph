/*
    This is the code of cycle detection in the undirected graph.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsCycle(vector<int> adj[], vector<bool> &visited, int source, int N)
{
    vector<int> parent(N, -1);
    visited[source] = true;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto itr : adj[front])
        {
            if (!visited[itr])
            {
                visited[itr] = true;
                parent[itr] = front;
                q.push(itr);
            }
            else if (parent[front] != itr)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && bfsCycle(adj, visited, i, V))
            return true;
    }
    return false;
}