#include <stack>
using namespace std;
/*
    Idea of the kosaraju algorithm is:-
        first find topological sort of the graph why we already discussed in the notebook
        second transpose the graph this also we discussed in the notebook
        third do normal dfs.

*/
void createAdj(vector<int> adj[], vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
}

// this dfs function call is normal dfs based used for topological sorting.
void dfs(int src, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (!visited[adj[src][i]])
        {
            dfs(adj[src][i], adj, visited, s);
        }
    }
    s.push(src);
}

//  this dfs function call is working with transposed graph.
void dfs(int src, vector<int> transPose[], vector<bool> &visited)
{
    visited[src] = true;
    for (int i = 0; i < transPose[src].size(); i++)
    {
        if (!visited[transPose[src][i]])
        {
            dfs(transPose[src][i], transPose, visited);
        }
    }
}

// this function is making the transpose array.
void transePoseGraph(vector<int> adj[], vector<int> temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j];
            temp[v].push_back(u);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[v];
    createAdj(adj, edges);
    stack<int> s;
    vector<bool> visited(v, false);
    // doing topological sort here if something is not visited calling         dfs
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }
    // transpose the graph;
    vector<int> transPose[v];
    transePoseGraph(adj, transPose, v);
    // again making visited as false.
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    // final call of dfs
    int count = 0;
    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        if (!visited[i])
        {
            dfs(i, transPose, visited);
            count++;
        }
    }
    return count;
}