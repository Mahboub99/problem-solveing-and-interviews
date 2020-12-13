#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100;

ll n, m;
ll adj[MAXN][MAXN], dis[MAXN][MAXN];

void Floyd_Warshall()
{
    // intialize the matirx
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            if (i == j)
                dis[i][j] = 0;
            else if (adj[i][j])
                dis[i][j] = adj[i][j];
            else
                dis[i][j] = INF;

    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
void read()
{
    cin >> n >> m;
    ll u, v, w;
    adj.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }
}

int main()
{
    // just for testing
    read();
    Dijkstra(1);
    vector<ll> path = getPath(3);
    for (ll i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
/*
     5 6
     1 2 5
     1 4 9
     1 5 1
     5 4 2
     4 3 6
     2 3 2
     */