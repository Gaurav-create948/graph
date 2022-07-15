#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    BFS (breadth first search)
    All things same just this logic is similar to level order traversal in binary tree
    Using queue in this solution as we used in the level order traversal
*/

void bfs(vector<int> &res, vector<int> adj[], bool visited[], int s)
{
    // first pushing the source in the queue.
    queue<int> q;
    q.push(s);
    // marking visited for the source.
    visited[s] = true;
    // loop while queue is not empty.
    while (!q.empty())
    {
        // first take out the front item in queue.
        int front = q.front();
        q.pop();
        // push it in the result array
        res.push_back(front);
        // loop all the adjacents of the front item
        for (int i = 0; i < adj[front].size(); i++)
        {
            // if not visited then push it in the queue and mark it true.
            if (!visited[adj[front][i]])
            {
                q.push(adj[front][i]);
                visited[adj[front][i]] = true;
            }
        }
    }
}
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    
    vector<int> res;
    bool visited[V];
    // setting visited array false initially.
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    // calling the bfs function.
    bfs(res, adj, visited, 0);
    return res;
}