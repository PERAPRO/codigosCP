int dfs(int u, int c){
    visited[u]=1;
    color[u]=c;
    for(int v:g[u]){
        if(!visited[v]){
            if(!dfs(v,!c)) return 0;
        }else{
            if(color[u] == color[v]) return 0;
        }
    }
    return 1;
}