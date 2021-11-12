vi parent;
 
int find(int a){
    if(parent[a]<0) return a; //En el main parent.assign(n,-1)
    return parent[a]=find(parent[a]);
}
 
int Union(int a, int b){
    a=find(a), b=find(b);
    if(a == b) return -parent[a];
    if(-parent[b] > -parent[a]) swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
    return -parent[a];
}