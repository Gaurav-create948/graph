#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    This is the bfs based cycle detection solution implemented by the logical use of kahns algo.
    Why this algo is working?
    because kahns algorithm only works for DAG (direct acyclic graph) and if there's a cycle
    it will detect easily
*/

bool bfsCycleDetect(vector<int> adj[], vector<int> indegree, int N)
{
    // vertex with indegree 0 are getting pushed in the stack.
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0; // this count will compared in the last with no. of vertices.
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++; // increasing the count when popping out an element.
        for (auto v : adj[u])
        {
            if (--indegree[v] == 0) // indegree of a adjacent vertex becomes 0 push in queue
            {
                q.push(v);
            }
        }
    }
    return (count != N); // if count is equal to n means a valid topological sort means no cycle else if not equal means cycle present.
}
bool isCyclic(int V, vector<int> adj[])
{
    // storing all the indegrees coming to a vertex
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto v : adj[i])
        {
            indegree[v]++;
        }
    }
    return bfsCycleDetect(adj, indegree, V);
}