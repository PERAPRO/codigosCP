#include<bits/stdc++.h>

using namespace std;


struct Edge {
    long long  a, b, cost;
};

int n, m;
vector<Edge> e;
const long long INF = 1e17;
int v=0;
void solve()
{
    vector<long long> d (n, INF);
    d[v] = 0;
    vector<int> p (n - 1);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cout << "NO" << endl;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "YES" << endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] + 1 << ' ';
    }
}

int main(){
    int a,b,w;
    cin>>n>>m;
    //vector<edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        e.push_back({a - 1, b - 1, w});
    }
    solve();
}