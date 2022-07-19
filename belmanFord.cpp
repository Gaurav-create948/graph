/*
    Bellman ford algorithm (for shortest path algorithm)

    It is used to find the shortest path from a given source to a vertex.

    We already know the shortest path algorithms
    -> for (DAG) using bfs and topological sort
    -> Dijstra for cyclic but not works for negative edge weight.

    So here comes the bellman ford algorithm

    Idea -:

        traverse all the edges (V-1) times and inside that for all edges do relax operation
        that we do in (DAG) shortest path.

    Why (v-1) times because a simple path can only have (v-1) edges for (v) vertices
    Also useful to find the negative cycle detection.

    Time complexity : O((v-1)*E)
    overall : O(V*E) 
*/




int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1, 1e9);
    dist[src] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != 1e9 && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
    return dist[dest];
}
