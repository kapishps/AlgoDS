vector<int> graph[10000];
int visited[10000], d[10000], cyclenodes[10000];
 
int dfs(int src){
    visited[src] = 1;
    for(auto i: graph[src]){
        if(visited[i]){
            return i;
        }
        int x = dfs(i);
        if(x > 0 && x != src){
            return x;
        }
    }
    return 0;
}
 
int dfs1(int src, int depth, int og){
    visited[src] = 1;
    for(auto i: graph[src]){
        if(i == og && depth > 1){
            for (int j = 0; j < 1000; j++){
                cyclenodes[j] = visited[j];
            }
            return 1;
        }
        if(!visited[i]){
            int x = dfs1(i, depth+1, og);
            if(x > 0){
                return x;
            }
        }
    }
    visited[src] = 0;
    return 0;
 }
 
 int bfs(int src){
     if(cyclenodes[src] == 1){
         return 0;
     }
     queue<int> q;
     visited[src] = 1;
     q.push(src);
     while(!q.empty()){
         int curr = q.front();
         q.pop();
         for(auto i: graph[curr]){
             if(cyclenodes[i]){
                 return d[curr]+1;
             }
             if(!visited[i]){
                 d[i] = d[curr] +1;
                 visited[i] = 1;
                 q.push(i);
             }
         }
     }
     return 0;
 }

vector<int> nodeDistance(int g_nodes, vector<int> g_from, vector<int> g_to) {
    for(int i =0; i< g_from.size(); i++){
        graph[g_from[i]].push_back(g_to[i]);
        graph[g_to[i]].push_back(g_from[i]);
    }
    
    int cyclenode = dfs(1);
    cerr<<cyclenode<<"\n";
    for(int i = 0; i <= g_nodes; i++){
        visited[i] = 0;
    }
    dfs1(cyclenode, 0, cyclenode);
    
    
    vector<int> dist;
    for(int i =1; i<= g_nodes; i++){
        for(int j = 0; j <= g_nodes; j++){
            visited[j] = 0;
            d[j] = 0;
        }
        dist.push_back(bfs(i));
    }
    return dist;
    
}