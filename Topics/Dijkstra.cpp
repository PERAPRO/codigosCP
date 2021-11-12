//q{distance,node};
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<ll> distances(n+1,oo);
    
    q.push({0,1});
    distances[1]=0;
    while(q.size()){
        ll dd=q.top().ff;
        ll u=q.top().ss;
        q.pop();
        if(distances[u] != dd) continue;
        for(pii v:g[u]){
            ll nd=dd+v.ss;
            if(nd<distances[v.ff]){
                distances[v.ff]=nd;
                q.push({nd,v.ff});
            }
        }
    }