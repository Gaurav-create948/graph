#include <iostream>
#include <vector>
using namespace std;

/*
    DFS (depth first traversal)
    this is same like traversing a tree from depth to up.
    recursive solution.
*/

void dfs(vector<int> adj[], bool visited[], vector<int> &res, int source)
{
    // first marking the source that we got as true and adding it to the result array.
    visited[source] = true;
    res.push_back(source);
    // traversing all the adjcents of the source.
    for (int i = 0; i < adj[source].size(); i++)
    {
        // If the current adjacent is not visited then calling dfs for it else not.
        if (!visited[adj[source][i]])
        {
            dfs(adj, visited, res, adj[source][i]);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Creating a result vector to store the dfs traversal of the adjacency list.
    vector<int> res;
    // Visited array to check if a element is already visited or not if it is already visited don't visit again
    bool visited[V];
    // calling dfs function.
    dfs(adj, visited, res, 0);
    return res;
}