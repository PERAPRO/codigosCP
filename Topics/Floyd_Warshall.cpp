vector<vector<ll>> distances(n+1,vector<ll>(n+1,oo));
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        distances[a][b]=distances[b][a]=min(distances[a][b],w);
    }
    for(int i=1;i<=n;i++) distances[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)  //Distancia de i a j usando los k primeros nodos
                distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);